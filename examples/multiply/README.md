# Multiplication

## Givens

 * Points (p1,p2)
 * Points (q1,q2)

## Result

 * A pair of points, the distance between equal to the multiplication of the original distances

## Algorithm

 1. ACCEPT POINTS (p1,p2) and POINTS (q1,q2)
 1. DEFINE the DISTANCE BETWEEN q1 and q2 as d1
 1. DEFINE the LINE THROUGH p1 and THROUGH p2 as l1
 1. DEFINE a POINT at DISTANCE 1 from p1 NOT ON l1 as p3
 1. DEFINE the LINE THROUGH p1 and THROUGH p3 as l2
 1. DEFINE the POINT ON l2 and at DISTANCE d1 from p1 as p4
 1. DEFINE the LINE THROUGH p2 and THROUGH p3 as l3
 1. DEFINE the LINE THROUGH p3 and at ANGLE 90 to l3 as l4
 1. DEFINE the LINE THROUGH p4 and at ANGLE 90 to l4 as l5
 1. DEFINE the POINT ON l1 and ON l5 as p5
 1. PROVIDE POINTS (p1,p5)
