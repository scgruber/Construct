library toolbar;

import 'dart:html';
import 'constants.dart';
import 'draw.dart';
import 'objects.dart';

ToolbarManager gToolbarManager;
num activeTool = 0;

class ToolbarManager {
  List<Tool> tools;
  num activeTool;
  CanvasRenderingContext2D tbCtx;
  num tbWidth, tbHeight;
  
  ToolbarManager(this.tbCtx) {
     this.tbWidth = this.tbCtx.canvas.width;
     this.tbHeight = this.tbCtx.canvas.height;
     this.tools = new List();
     this.activeTool = 0; // This should always be the selection tool
     this.tbCtx.canvas.onClick.listen(this.clickRouter);
  }
  
  void registerTool(Tool inRegTool) {
    this.tools.add(inRegTool);
  }
  
  /* void clickRouter(event)
   * This function manages all clicks that occur in the editor toolbar
   */
  void clickRouter(MouseEvent event) {
    window.alert("You clicked on the toolbar!");
    event.client.x;
  }
  
  void redraw() {
    // Clear the toolbar drawing area
    tbCtx
      ..setFillColorHsl(0, 0, 80)
      ..setStrokeColorHsl(0, 0, 0)
      ..fillRect(0, 0, tbWidth, tbHeight);
    
    // Draw the tool buttons
    for (int i=0; i < tools.length; i++) {
      // Active tool indication
      if (i == activeTool) {
        tbCtx
          ..setFillColorRgb(0, 0, 255, 0.1)
          ..setStrokeColorRgb(0, 0, 255, 0.5)
          ..fillRect(5, (tbWidth*i+5), tbWidth-10, tbWidth-10)
          ..strokeRect(5, (tbWidth*i+5), tbWidth-10, tbWidth-10);
      }
      
      tools[i].drawButton(new Point(10, (tbWidth*i+10)), 20);
    }
  }
}

abstract class Tool {
  void toolBegin();
  void toolEnd();
  
  void drawButton(Point topleft, num buttonDimension);
  void mouseMove(Point mousePosition);
  
  void clickHandler(Point clickedPoint);
  
  List<Point> toolPoints;
  
  void register() {
    gToolbarManager.registerTool(this);
  }
}

/* void registerAllTools()
 * Registers all of the tools that have been defined
 * Call from main before the redraw goes out
 */
void registerAllTools() {
  (new SelectionTool()).register(); // Must be first registered
}

////////////////////////////////////////////////////////////////////////////////
// Selection Tool
////////////////////////////////////////////////////////////////////////////////

class SelectionTool extends Tool {
  
  void toolBegin() {
    // Anything that needs to be done when we start using the tool
    gRedrawManager.wsCtx.canvas.style.cursor = "default";
  }
  
  void toolEnd() {
    // Anything that needs to be done when we stop using the tool
    gRedrawManager.clearPreselection();
  }
  
  void drawButton(Point topleft, num buttonDimension) {
    // Set colors
    gToolbarManager.tbCtx
      ..setStrokeColorHsl(0, 0, 30)
      ..lineWidth = 1.5
      ..setFillColorHsl(0, 0, 90);
    
    // Fill
    gToolbarManager.tbCtx
      ..beginPath()
      ..moveTo(topleft.x + (buttonDimension*0.2), topleft.y)
      ..lineTo(topleft.x + (buttonDimension*0.2), topleft.y + buttonDimension)
      ..lineTo(topleft.x + (buttonDimension*0.525), topleft.y + (buttonDimension*0.7))
      ..lineTo(topleft.x + (buttonDimension*0.9), topleft.y + (buttonDimension*0.7))
      ..lineTo(topleft.x + (buttonDimension*0.2), topleft.y)
      ..fill()
      ..closePath();
    
    // Stroke
    gToolbarManager.tbCtx
      ..beginPath()
      ..moveTo(topleft.x + (buttonDimension*0.2), topleft.y)
      ..lineTo(topleft.x + (buttonDimension*0.2), topleft.y + buttonDimension)
      ..lineTo(topleft.x + (buttonDimension*0.525), topleft.y + (buttonDimension*0.7))
      ..lineTo(topleft.x + (buttonDimension*0.9), topleft.y + (buttonDimension*0.7))
      ..lineTo(topleft.x + (buttonDimension*0.2), topleft.y)
      ..stroke()
      ..closePath();
  }
  
  void mouseMove(Point mousePosition) {
    DrawingObject underObj = gRedrawManager.unprojectToObject(mousePosition);
    if (underObj == null) {
      // Clear preselection
      gRedrawManager.clearPreselection();
    } else {
      gRedrawManager.addPreselectionObject(underObj);
    }
  }
  
  void clickHandler(Point clickedPoint) {
    DrawingObject underObj = gRedrawManager.unprojectToObject(clickedPoint);
    if (underObj != null) {
      // TODO: Add permanent selection highlighting to the object
    }
  }
}