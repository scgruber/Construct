# Addition

## Givens

 * Points (p1,p2)
 * Points (q1,q2)

## Result

 * A pair of points, the distance between them equalling the sum of the original distances

## Algorithm

 1. ACCEPT POINTS (p1,p2) and POINTS (q1,q2)
 1. DEFINE the LINE THROUGH p1 and THROUGH p2 as l1
 1. DEFINE the POINT ON l1 at DISTANCE d1 FROM p2 as p3<br/>
    WHERE d1 is BETWEEN q1 and q2<br/>
    WHERE d2 is BETWEEN p1 and p2<br/>
    WHERE d3 is BETWEEN p1 and p3<br/>
    WHERE d2 is LESS than d3
 1. PROVIDE POINTS (p1,p3)
