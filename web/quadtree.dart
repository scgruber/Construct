library quadtree;

import 'dart:html' show Point;

// Quadtrees partition 2d space into a recursive quadrant grid.
// Note: this implementation behaves like a set; points are unique.

class QuadTree {
  QuadTreeNode root;
  
  QuadTree() {
    root = null;
  }
}

class QuadTreeNode {
  List<QuadTreeNode> directions;
  Point pt;
  
  QuadTreeNode(this.pt) {
    directions = new List(5);
    directions[0] = this;
  }
  
  void insert(Point newPt) {
    int dir = this.which(newPt);
    
    if (dir != 0) {
      if (directions[dir] != null) {
        directions[dir].insert(newPt);
      } else {
        directions[dir] = new QuadTreeNode(newPt);
      }
    }
  }
  
  bool contains(Point searchPt) {
    int dir = this.which(searchPt);
    
    if (dir == 0) {
      return true;
    } else {
      if (directions[dir] != null) {
        return directions[dir].contains(searchPt);
      } else {
        return false;
      }
    }
  }
  
  // Returns a list of all points below this node (inclusive)
  List<Point> dump() {
    List<Point> points = new List();
    
    if (pt != null) {
      points.add(pt);
    
      // Invariant: pt must exist if any children exist
      for (int i=0; i<directions.length; i++) {
        if (directions[i] != null)
          points.addAll(directions[i].dump());
      }
    }
    
    return points;
  }
  
  //////////////////////////////////////////////////////////////////////////////
  // Helper methods
  //////////////////////////////////////////////////////////////////////////////
  
  // Helper method for determining which direction to search next
  int which(Point searchPt) {
    int direction = 0;
    
    if (!(almostequal(pt.x, searchPt.x) && almostequal(pt.y, searchPt.y))) {
      if (pt.x < searchPt.x) {
        // East
        if (pt.y < searchPt.y){
          // North
          direction = 1;
          
        } else {
          // South
          direction = 4;
          
        }
      } else {
        // West
        if (pt.y < searchPt.y){
          // North
          direction = 2;
          
        } else {
          // South
          direction = 3;
          
        }
      }
    }
    
    return direction;
  }
}

bool almostequal(num a, num b) {
  return (a-b < 0.00001);
}

// Helper method for calculating 2d median
Point median(List<Point> points) {
  List<Point> weights = new List(points.length);
}