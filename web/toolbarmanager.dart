library toolbarmanager;

import 'dart:core';
import 'dart:html';
import 'dart:math';

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
    (new PointTool()).register(this);
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
  // Constructor
  Tool();
  // Called to attach the tool to the toolbar manager
  void register(ToolBarManager tb);
  
  // Called to draw the glyph for the button in the toolbar
  void drawButton(num x, num y, num width, num height);
  
  // Called when the user clicks on the toolbar button
  void toolStart();
  // Called when the user clicks in the workspace
  void click();
}

class PointTool implements Tool {
  CanvasRenderingContext2D cvs;
  
  PointTool() {}
  void register(ToolBarManager tb) {
    cvs = tb.cvs;
    tb.objectTools.add(this);
  }
  
  void drawButton(num x, num y, num width, num height) {
    cvs.strokeStyle = '#BBBBBB';
    cvs.fillStyle = '#BBBBBB';
    num cx = x + (width/2);
    num cy = y + (height/2);
    cvs.arc(cx, cy, 2.5, 0, 2*PI);
    cvs.fill();
  }
  
  void toolStart() {
    // Create an unconstrained point object
  }
  
  void click() {}
}