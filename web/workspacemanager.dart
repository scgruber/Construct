library workspacemanager;

import 'dart:html';
import 'construct.dart';
import 'constructedobject.dart';

class WorkSpaceManager {
  CanvasRenderingContext2D cvs;
  
  WorkSpaceManager(this.cvs) {
    // Paint the background gray to initialize
    this.cvs.fillStyle = "#222222";
    this.cvs.fillRect(0, 0, this.cvs.canvas.width, this.cvs.canvas.height);
  }
  
  void redraw() {
    cvs.save();
    cvs.translate(cvs.canvas.width/2, cvs.canvas.height/2);
    
    for (ConstructedObject obj in gProgramModel.objs){
      obj.draw(cvs);
    }
    
    cvs.translate(-cvs.canvas.width/2, -cvs.canvas.height/2);
    cvs.restore();
  }
}