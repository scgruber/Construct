library solver;

import 'constructedobject.dart';
import 'constraint.dart';

Set<ConstructedObject> solve(Set<ConstructedObject> objs) {
  
}

Set<ConstructedObject> graphSearchSolver( Set<ConstructedObject> visited,
                                          Set<ConstructedObject> graph) {
  /* All objects in VISITED have known positions
   * Objects in GRAPH may be connected to objects in visited
   */
  
  // Build the frontier
  Set<ConstructedObject> frontier = mkFrontier(visited, graph);
  // For every object in the frontier, attempt to solve its position
  for (ConstructedObject f in frontier) {
    // Filter only constraints connected to the visited set
    f.constraints.retainWhere((c){return visited.contains(c.referenceObject);});
  }
}

Set<ConstructedObject> mkFrontier ( Set<ConstructedObject> visited,
                                    Set<ConstructedObject> graph) {
  Set<ConstructedObject> frontier = new Set();
  // Acquire all outNeighbors of visited
  for (ConstructedObject v in visited) {
    for (Constraint c in v.constraints)
      frontier.add(c.referenceObject);
  }
  // Difference out all objects in visited
  frontier = frontier.difference(visited);
  return frontier;
}