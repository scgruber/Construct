library workspacemanager;

import 'dart:html';

class WorkSpaceManager {
  CanvasRenderingContext2D cvs;
  
  WorkSpaceManager(this.cvs) {
    // Paint the background gray to initialize
    this.cvs.fillStyle = "#222222";
    this.cvs.fillRect(0, 0, this.cvs.canvas.width, this.cvs.canvas.height);
  }
}