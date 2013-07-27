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
  bool inObjectBounds(Point loc);
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
  
  bool inObjectBounds(Point loc) {
    return (integerPosition.distanceTo(loc).abs() <= 5);
  }
}