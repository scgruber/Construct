library programmodel;

import 'constructedobject.dart';

class ProgramModel {
  Set<ConstructedObject> objs;
  int size;
  
  ProgramModel() {
    objs = new Set();
    size = 0;
  }
  
  void create(ConstructedObject inObj) {
    objs.add(inObj);
    size++;
  }
}