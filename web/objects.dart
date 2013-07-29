import 'dart:html';
import 'dart:math';

class Vec2 {
  num x, y;
  Vec2(this.x, this.y);
  Vec2 operator +(Vec2 other) => new Vec2(x + other.x, y + other.y);
  Vec2 operator -(Vec2 other) => new Vec2(x - other.x, y - other.y);
  // Dot Product
  num operator *(Vec2 other) => (x * other.x) + (y * other.y);
  // Cross Product
  num operator ^(Vec2 other) => (x * other.y) - (y * other.x);
  // Scalar Product
  Vec2 operator &(num scalar) => new Vec2(x*scalar, y*scalar);
  // Decomposition
  Vec2 operator /(Vec2 other) => other&((this*other)/(other*other));
  // Residual
  Vec2 operator %(Vec2 other) => this - this/other;
}

abstract class DrawingObject {
  bool resolved;
  
  void draw(CanvasRenderingContext2D ctx);
  highlight(CanvasRenderingContext2D ctx, num h, num s, num l);
  bool intersects(BoundingBox searchBB);
  
  BoundingBox get bounds;
}

class LocusByCoords extends DrawingObject {
  Point integerPosition;
  
  LocusByCoords(this.integerPosition) {
    this.resolved = true;
  }
  
  void draw(CanvasRenderingContext2D ctx) {
    ctx.setFillColorHsl(0, 0, 80);
    ctx.beginPath();
    ctx.arc(integerPosition.x, integerPosition.y, 5, 0, 2*PI);
    ctx.fill();
    ctx.closePath();
  }
  
  void highlight(CanvasRenderingContext2D ctx, num h, num s, num l) {
    ctx.setStrokeColorHsl(h, s, l, 0.5);
    ctx.beginPath();
    ctx.arc(integerPosition.x, integerPosition.y, 5, 0, 2*PI);
    ctx.stroke();
    ctx.closePath();
  }
  
  bool intersects(BoundingBox searchBB) {
    return (searchBB.ne.x >= integerPosition.x &&
        searchBB.ne.y >= integerPosition.y &&
        searchBB.sw.x <= integerPosition.x &&
        searchBB.sw.y <= integerPosition.y);
  }
  
  BoundingBox get bounds {
    return new BoundingBox(integerPosition, integerPosition);
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