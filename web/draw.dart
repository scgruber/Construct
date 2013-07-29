library draw;

import 'dart:html';
import 'constants.dart';
import 'toolbar.dart';
import 'objects.dart';
import 'quadtree.dart';

RedrawManager gRedrawManager;

class RedrawManager {
  List<bool> flags;
  CanvasRenderingContext2D wsCtx;
  num wsWidth, wsHeight;
  QuadTree displayTree;
  QuadTree preselectTree;
  QuadTree selectTree;
  
  RedrawManager(ct, this.wsCtx) {
    this.flags = new List(ct);
    this.wsWidth = this.wsCtx.canvas.clientWidth;
    this.wsHeight = this.wsCtx.canvas.clientHeight;
    for (var i=0; i < ct; i++) {
      this.flags[i] = false;
    }
    this.displayTree = new QuadTree();
    this.preselectTree = new QuadTree();
    this.selectTree = new QuadTree();
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
    List<BoundedObject> displayList = displayTree.root.dump();
    for (int i=0; i < displayList.length; i++) {
      displayList[i].obj.draw(wsCtx);
    }
    
    // Highlight all objects in the highlight lists
    List<BoundedObject> preselectList = preselectTree.root.dump();
    for (int i=0; i <preselectList.length; i++) {
      preselectList[i].obj.highlight(wsCtx, 200, 70, 100);
    }
    List<BoundedObject> selectList = selectTree.root.dump();
    for (int i=0; i <selectList.length; i++) {
      selectList[i].obj.highlight(wsCtx, 300, 70, 100);
    }
    
    // Reset translation matrix
    wsCtx.translate(-wsWidth/2, -wsHeight/2);
  }
  
  void addDisplayObject(DrawingObject obj) {
    displayTree.insert(new BoundedObject(obj));
  }
  
  void addPreselectionObject(DrawingObject obj) {
    preselectTree.insert(new BoundedObject(obj));
  }
  
  void clearPreselection() {
    preselectTree = new QuadTree();
  }
  
  void addSelectionObject(DrawingObject obj) {
    selectTree.insert(new BoundedObject(obj));
  }
  
  void clearSelection() {
    selectTree = new QuadTree();
  }
  
  DrawingObject unprojectToObject(Point loc) {
    BoundingBox mouseBB = new BoundingBox(loc + new Point(10,10), 
        loc - new Point(10,10));
    List<BoundedObject> unprojections = displayTree.intersections(mouseBB);
    if (unprojections.length >= 1) {
      return unprojections[0].obj;
    } else {
      return null;
    }
  }
  
  /* void clickRouter(event)
   * This function manages all clicks that occur in the editor workspace
   */
  void clickRouter(MouseEvent event) {
    window.alert("You clicked on the workspace!");
    event.client.x;
  }
}