library constructedobject;

import 'dart:html';
import 'dart:math';
import 'construct.dart';
import 'constraint.dart';

abstract class ConstructedObject {
  static String name;
  Set<Constraint> constraints;
  
  void draw(CanvasRenderingContext2D cvs);
}

class PointObject implements ConstructedObject {
  static final String name = 'point';
  Point position;
  Set<Constraint> constraints;
  
  PointObject() {
    Random rand = new Random();
    position = new Point(rand.nextInt(200)-100,rand.nextInt(200)-100);
    constraints = new Set();
  }
  
  void draw(CanvasRenderingContext2D cvs) {
    cvs.fillStyle = '#BBBBBB';
    cvs.beginPath();
    cvs.arc(position.x, position.y, 2.5, 0.0, 2.0*PI);
    cvs.closePath();
    cvs.fill();
  }
  
  bool get isConstrained {
    int req = max(3, gProgramModel.size);
    return (constraints.length >= req);
  }
}