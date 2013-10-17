# Nearest Point

## Givens

 * A point (p1)
 * A group of points (g1)

## Result

 * The point in g1 which is nearest to p1

## Algorithm

 1. ACCEPT POINT (p1) and GROUP<POINT> (g1)
 1. CHOOSE the POINT from g1 as p2
 1. DEFINE the CIRCLE with CENTER p1 THROUGH p2 as c1
 1. SPECIFY PATTERN GROUP<POINT> with GROUPSIZE >= 2 as r1
 1. DEFINE the GROUP FROM g1 with POSITION INSIDE OR ON c1 as g2
 1. IF MATCH r1 to g2 DO nearest_point ELSE PROVIDE p2