# Area of a Triangle

## Given

 * Point (p1)
 * Point (p2)
 * Point (p3)

## Result

 * A pair of points, the distance between equal to the area of triangle (p1,p2,p3)

## Algorithm

 1. ACCEPT POINTS (p1, p2, p3)
 1. DEFINE the LINE THROUGH p1 and THROUGH p2 as l1
 1. DEFINE the LINE THROUGH p2 and at ANGLE 90 to l1 as l2
 1. DEFINE the LINE THROUGH p3 and at ANGLE 90 to l2 as l3
 1. DEFINE the POINT ON l3 and ON l2 as p4
 1. DEFINE the POINT ON l2 and at DISTANCE 2 from p2 as p5
 1. DEFINE the LINE THROUGH p1 and THROUGH p5 as l4
 2. DEFINE the LINE THROUGH p5 and at ANGLE 90 to l4 as l5
 1. DEFINE the LINE THROUGH p4 and at ANGLE 90 to l5 as l6
 1. DEFINE the POINT ON l1 and ON l6 as p6
 1. PROVIDE POINTS (p2, p6)
