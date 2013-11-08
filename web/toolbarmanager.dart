library toolbarmanager;

import 'dart:core';
import 'dart:html';

class ToolBarManager {
  CanvasRenderingContext2D cvs;
  List<Tool> objectTools;
  List<Tool> constraintTools;
  
  static const num buttonDim = 30;
  static const num buttonSpacing = 5;
  
  ToolBarManager(this.cvs){
    // Paint the background gray
    this.cvs.fillStyle = '#222222';
    this.cvs.fillRect(0, 0, this.cvs.canvas.width, this.cvs.canvas.height);
    
    // Set up the toolsets
    this.objectTools = new List();
    this.constraintTools = new List();
    
    // Draw the initial toolbar
    this.draw();
  }
  
  void draw() {
    num vpos = buttonSpacing;
    for (var t in objectTools) {
      t.drawButton(buttonSpacing, vpos, buttonDim, buttonDim);
      vpos += buttonDim + buttonSpacing;
    }
    drawSpacer(buttonSpacing, vpos, buttonDim, buttonSpacing);
    vpos += buttonSpacing + buttonSpacing;
    for (var t in constraintTools) {
      t.drawButton(buttonSpacing, vpos, buttonDim, buttonSpacing);
      vpos += buttonDim + buttonSpacing;
    }
  }
  
  void drawSpacer(num x, num y, num width, num height) {
    cvs.strokeStyle = '#BBBBBB';
    cvs.lineWidth = 1;
    cvs.moveTo(x, y);
    cvs.lineTo(x+width, y);
    cvs.stroke();
    cvs.moveTo(x, y+height);
    cvs.lineTo(x+width, y+height);
    cvs.stroke();
  }
}

abstract class Tool {
  Tool();
  void register(ToolBarManager tb);
  
  void drawButton(num x, num y, num width, num height);
  void click();
}