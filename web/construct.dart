// Imports
import 'dart:html';
import 'draw.dart';
import 'objects.dart';
import 'constants.dart';
import 'toolbar.dart';

void main() {
  // Initialize the workspace canvas element
  CanvasElement wsCvs = query("#workspace");
  gRedrawManager = new RedrawManager(kRedrawAll+1, wsCvs.getContext("2d"));
  gRedrawManager.addDisplayObject(new LocusByCoords(new Point(0, 0)));
  gRedrawManager.addPreselectionObject(new LocusByCoords(new Point(0, -50)));
  gRedrawManager.addSelectionObject(new LocusByCoords(new Point(0, 50)));
  gRedrawManager.redraw();
  
  //Initialize the toolbar canvas element
  CanvasElement tbCvs = query("#toolbar");
  gToolbarManager = new ToolbarManager(tbCvs.getContext("2d"));
  registerAllTools();
  gToolbarManager.redraw();
}