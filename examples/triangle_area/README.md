# Area of a Triangle

## Given

 * Point (p1)
 * Point (p2)
 * Point (p3)

## Result

 * A vector whose length is the area of the triangle formed by p1,p2,p3

## Algorithm

 1. ACCEPT POINTS (p1, p2, p3)
 1. DEFINE the LINE THROUGH p1 and THROUGH p2 as l1
 1. DEFINE the LINE THROUGH p3 and PARALLEL to l1 as l2
 1. DEFINE the LINE THROUGH p2 and PERPENDICULAR to l1 as l3
 1. DEFINE the POINT ON l2 and ON l3 as p4
 1. DEFINE the VECTOR ALONG l3 FROM p2 with LENGTH 2 as v1
 1. DEFINE the POINT at the TERMINAL of v1 as p5
 1. DEFINE the LINE THROUGH p1 and THROUGH p5 as l4
 1. DEFINE the LINE THROUGH p4 and PARALLEL to l4 as l5
 1. DEFINE the POINT ON l1 and ON l5 as p6
 1. PROVIDE POINTS (p2, p6)