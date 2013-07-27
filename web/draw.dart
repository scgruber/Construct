library draw;

import 'dart:html';
import 'constants.dart';
import 'toolbar.dart';
import 'objects.dart';

RedrawManager gRedrawManager;

class RedrawManager {
  List<bool> flags;
  CanvasRenderingContext2D wsCtx;
  num wsWidth, wsHeight;
  List<DrawingObject> displayList;
  List<DrawingObject> preselectList;
  List<DrawingObject> selectList;
  
  RedrawManager(ct, this.wsCtx) {
    this.flags = new List(ct);
    this.wsWidth = this.wsCtx.canvas.clientWidth;
    this.wsHeight = this.wsCtx.canvas.clientHeight;
    for (var i=0; i < ct; i++) {
      this.flags[i] = false;
    }
    this.displayList = new List();
    this.preselectList = new List();
    this.selectList = new List();
    this.wsCtx.canvas.onClick.listen(this.clickRouter);
  }
  
  void redraw() {
    // Clear the workspace background
    wsCtx
    ..setFillColorHsl(0, 0, 20)
    ..setStrokeColorHsl(0, 0, 100)
    ..fillRect(0, 0, wsWidth, wsHeight);
    
    // Translate (0,0) to center of workspace
    wsCtx.translate(wsWidth/2, wsHeight/2);
    
    // Draw all objects in the display list
    for (int i=0; i < displayList.length; i++) {
      displayList[i].draw(wsCtx);
    }
    
    // Highlight all objects in the highlight lists
    for (int i=0; i <preselectList.length; i++) {
      preselectList[i].highlight(wsCtx, 200, 70, 100);
    }
    for (int i=0; i <selectList.length; i++) {
      selectList[i].highlight(wsCtx, 300, 70, 100);
    }
    
    // Reset translation matrix
    wsCtx.translate(-wsWidth/2, -wsHeight/2);
  }
  
  void addDisplayObject(DrawingObject obj) {
    displayList.add(obj);
  }
  
  void addPreselectionObject(DrawingObject obj) {
    preselectList.add(obj);
  }
  
  void clearPreselection() {
    preselectList.clear();
  }
  
  void addSelectionObject(DrawingObject obj) {
    selectList.add(obj);
  }
  
  void clearSelection() {
    selectList.clear();
  }
  
  DrawingObject unprojectToObject(Point loc) {
    for (var i=0; i < displayList.length; i++) {
      if (displayList[i].inObjectBounds(loc))
        return displayList[i];
    }
    
    // Only reach here if there is nothing at loc
    return null;
  }
  
  /* void clickRouter(event)
   * This function manages all clicks that occur in the editor workspace
   */
  void clickRouter(MouseEvent event) {
    window.alert("You clicked on the workspace!");
    event.client.x;
  }
}