library programmodel;

import 'constructedobject.dart';

class ProgramModel {
  Set<ConstructedObject> objs;
  
  ProgramModel() {
    objs = new Set();
  }
  
  void create(ConstructedObject inObj) {
    objs.add(inObj);
  }
}