library toolbarmanager;

import 'dart:html';

class ToolBarManager {
  CanvasRenderingContext2D cvs;
  
  ToolBarManager(this.cvs){
    // Paint the background gray to initialize
    this.cvs.fillStyle = "#222222";
    this.cvs.fillRect(0, 0, this.cvs.canvas.width, this.cvs.canvas.height);
  }
}