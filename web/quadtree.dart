library quadtree;

import 'dart:math';
import 'dart:html' show Point;
import 'objects.dart' show DrawingObject;

const Point initialQuadtreeOrigin = const Point(0,0);
const num initialQuadtreeDim = 64;
const num quadtreeSplitLimit = 16;

// TODO: Add deletion capability
// TODO: Add soft intersects for draw culling
// TODO: Add balancing code

/* QuadTree is a container class for the QuadTreeNode tree. This allows us to 
 * grow the tree upward if an object is inserted out of the bounds of the 
 * current root
 */
class QuadTree {
  QuadTreeNode root;
  
  QuadTree() {
    root = new QuadTreeNode(initialQuadtreeOrigin, initialQuadtreeDim);
  }
  
  /* Adds a new object to the quadtree. If necessary, it grows the tree upwards
   * to accomodate this object.
   */
  void insert(BoundedObject obj) {
    // Default, place object inside root
    int where = -1;
    bool north, south = false;
    
    if (obj.bb.ne.y > (root.center.y + root.dimension)) {
      // Obj exceeds north limit
      north = true;
      where = 0; // North-east
      // If both east and west are false => 0
    } else if (obj.bb.sw.y < (root.center.y - root.dimension)){
      // Obj exceeds south limit
      south = true;
      where = 2; // South-west
      // If both east and west are false => 2
    }
    
    if (obj.bb.ne.x > (root.center.x + root.dimension)) {
      // Obj exceeds east limit
      if (south == true) {
        where = 3; // South east
      }
      // If north == true => 0
      // If both north and south are false, => 0
    } else if (obj.bb.sw.x < (root.center.x - root.dimension)) {
      if (north == true) {
        where = 1; // North-west
      }
      // If south == true => 2
      // If both north and south are false, => 2
    }
      
    if (where == -1) {
      // Place into current root
      root.insert(obj);
    } else {
      // Determine offsets for new center based on where old root goes
      num dy = (where < 2) ? (-root.dimension) : (root.dimension);
      num dx = (where % 3 == 0) ? (-root.dimension) : (root.dimension);
      
      QuadTreeNode newroot = new QuadTreeNode(root.center + new Point(dx, dy), 
          root.dimension*2);
      newroot.split();
      newroot.directions[where] = root;
      root = newroot;
      
      this.insert(obj); // FIXME: Recursing like this is bad form
    }
  }
  
  /* Returns all of the objects in the tree that intersect the supplied
   * bounding box.
   */
  List<BoundedObject> intersections(BoundingBox searchBB) {
    return root.intersections(searchBB);
  }
}

/* QuadTreeNode is used to store bounded elements by using recursive quadrant 
 * bounding boxes. Each node stores a collection of elements. If the node's
 * collection is larger than quadtreeSplitLimit elements, it attempts to 
 * distribute the elements to its child nodes.
 */
class QuadTreeNode {
  List<QuadTreeNode> directions;
  Point center;
  num dimension;
  List<BoundedObject> objects;
  
  QuadTreeNode(this.center, this.dimension) {
    directions = null;
    objects = new List();
  }
  
  void insert(BoundedObject obj) {
    if (directions = null) {
      // Haven't yet split the node
      if (objects.length == quadtreeSplitLimit) {
        this.split();
        this.insert(obj); // FIXME: Recursing like this is bad form
      } else {
        // If there are few enough objects just keep them here
        objects.add(obj);
      }
    } else {
      int where = this.where(obj.bb);
      
      if (where == -1) {
        objects.add(obj);
      } else {
        directions[where].insert(obj);
      }
    }
  }
  
  /* Returns a list of all objects beneath this node which intersect the
   * supplied bounding box.
   */
  List<BoundedObject> intersections(BoundingBox searchBB) {
    List<BoundedObject> result = new List();
    
    // Parent
    for (int i=0; i < objects.length; i++) {
      if (objects[i].intersects(searchBB)) {
        result.add(objects[i]);
      }
    }
    
    // Children
    if (directions != null) {
      // North-east
      if (searchBB.ne.x >= center.x && 
          searchBB.ne.y >= center.y &&
          searchBB.sw.x <= (center.x + dimension) && 
          searchBB.sw.y <= (center.y + dimension)) {
        result.addAll(directions[0].intersections(searchBB));
      }
      // North-west
      if (searchBB.sw.x <= center.x && 
          searchBB.ne.y >= center.y &&
          searchBB.ne.x >= (center.x - dimension) &&
          searchBB.sw.y <= (center.y + dimension)) {
        result.addAll(directions[1].intersections(searchBB));
      }
      // South-west
      if (searchBB.sw.x <= center.x && 
          searchBB.sw.y <= center.y &&
          searchBB.ne.x >= (center.x - dimension) &&
          searchBB.ne.y >= (center.y - dimension)) {
        result.addAll(directions[2].intersections(searchBB));
      }
      // South-east
      if (searchBB.ne.x >= center.x && 
          searchBB.sw.y <= center.y &&
          searchBB.sw.x <= (center.x + dimension) &&
          searchBB.ne.y >= (center.y - dimension)) {
        result.addAll(directions[3].intersections(searchBB));
      }
    }
    
    return result;
  }
  
  /* Creates four children to the current node and sorts the object list into
   * the child nodes if possible.
   */
  void split() {
    // Create child nodes
    directions = new List(4);
    for (int i=0; i<directions.length; i++) {
      // Determine offsets for new center based on quadrant
      num dy = (i<2) ? (dimension/2) : (-dimension/2);
      num dx = (i%3 == 0) ? (dimension/2) : (-dimension/2);
      
      directions[i] = new QuadTreeNode(this.center + new Point(dx, dy), dimension/2);
    }
    
    // Distribute objects into children where possible
    List<BoundedObject> tempObjectList = objects;
    objects = new List();
    
    for (int i=0; i < tempObjectList.length; i++) {
      int dir = this.where(tempObjectList[i].bb);
      if (dir == -1) {
        // Object straddles the quadrants, must remain up here
        objects.add(tempObjectList[i]);
      } else {
        directions[dir].insert(tempObjectList[i]);
      }
    }
  }
  
  /* Identifies which quadrant the bounding box belongs to
   * -1 -> Straddles quadrants, assign to this node
   * 0  -> North-east (+,+)
   * 1  -> North-west (-,+)
   * 2  -> South-west (-,-)
   * 3  -> South-east (+,-)
   */
  int where(BoundingBox searchBB) {
    // Default case, belongs to self
    int result = -1;
    
    if (searchBB.sw.y > this.center.y) {
      // Possible north?
      if (searchBB.sw.x > this.center.x) {
        // North-east
        result = 0;
      } else if (searchBB.ne.x < this.center.x){
        // North-west
        result = 1;
      }
    } else if (searchBB.ne.y < this.center.y) {
      // Possible south?
      if (searchBB.ne.x < this.center.x) {
        // South-west
        result = 2;
      } else if (searchBB.sw.x > this.center.x) {
        // South-east
        result = 3;
      }
    }
    
    return result;
  }
  
  // Returns a list of all objects within the bounds of this node
  List<BoundedObject> dump() {
    List<BoundedObject> out = new List();
    
    out.addAll(objects);
    
    if (directions != null) {
      for (int i=0; i < directions.length; i++) {
        out.addAll(directions[i].dump());
      }
    }
    
    return out;
  }
  
}

/* BoundedObject stores a DrawingObject with its bounding box for quick
 * reference by the QuadTree structure.
 */
class BoundedObject {
  DrawingObject obj;
  BoundingBox bb;
  
  BoundedObject(this.obj){
    this.bb = this.obj.bounds;
  }
  
  /* Returns true if the bounding box intersects the object */
  bool intersects(BoundingBox searchBB) {
    // Short-circuit evaluation means we only do the expensive check after
    // cheaply checking the bounding box.
    return bb.intersects(searchBB) && obj.intersects(searchBB);
  }
}

/* BoundingBox is an axis-aligned bounding box */
class BoundingBox {
  Point ne, sw;
  
  BoundingBox(this.ne, this.sw);
  
  /* Returns true if the box is inside our bounding box, false otherwise */
  bool contains(BoundingBox searchBB) {
    return (ne.x >= searchBB.ne.x && ne.y >= searchBB.ne.y &&
        sw. x <= searchBB.sw.x && sw.y <= searchBB.sw.y);
  }
  
  /* Returns true if the supplied bounding box intersects this box */
  bool intersects(BoundingBox searchBB) {
    return (
      (searchBB.sw.y <= this.ne.y) &&
      (searchBB.ne.y >= this.sw.y) &&
      (searchBB.sw.x <= this.ne.x) &&
      (searchBB.ne.x >= this.sw.x)
    );
  }
  
  /* Returns the tightest bounding box which completely contains the two given
   * bounding boxes.
   */
  static BoundingBox union(BoundingBox bb1, BoundingBox bb2) {
    num north = max(bb1.ne.y, bb2.ne.y);
    num south = min(bb1.sw.y, bb2.sw.y);
    num east = max(bb1.ne.x, bb2.ne.x);
    num west = min(bb1.sw.x, bb2.sw.x);
    
    return new BoundingBox(new Point(east, north), new Point(west, south));
  }
}

bool almostequal(num a, num b) {
  return (a-b < 0.00001);
}