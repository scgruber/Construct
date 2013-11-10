library constructedobject;

import 'dart:html';
import 'dart:math';

abstract class ConstructedObject {
  static String name;
  
  void draw(CanvasRenderingContext2D cvs);
}

class PointObject implements ConstructedObject {
  static final String name = 'point';
  Point position;
  
  PointObject() {
    position = new Point(0,0);
  }
  
  void draw(CanvasRenderingContext2D cvs) {
    cvs.beginPath();
    cvs.arc(position.x, position.y, 2.5, 0.0, 2.0*PI);
    cvs.closePath();
    cvs.fill();
  }
}