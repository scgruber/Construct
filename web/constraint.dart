library constraint;
import 'constructedobject.dart';

abstract class Constraint {
  static String name;
  ConstructedObject referenceObject;
}

class DistanceConstraint implements Constraint {
  static String name = 'distance';
  num distance;
  PointObject referenceObject;
  
  DistanceConstraint(this.distance) {} 
}