# Constraints

Constraints are used to check whether primitives achieve certain criteria.

## General Constraints

 * Not - Given a constraint, achieved if that constraint is not achieved

## Point Constraints

 * Coincident - Given a point, achieved if that point is in exactly the same location as this point
 * At Origin - Given a vector, achieved if this point is at the origin of the vector
 * At Terminal - Given a vector, achieved if this point is at the terminal of the vector
 * On - Given a line, achieved if this point lies upon that line
 * On - Given a circle, achieved if this point lies upon that circle
 * Inside - Given a circle, achieved if this point lies within the circle

## Line Constraints

 * Coincident - Given a line, achieved if that line is in exactly the same location as this line
 * Through - Given a point, achieved if this line passes through that point
 * Intersecting - Given a line, achieved if that line crosses this line
 * Parallel - Given a line, achieved if that line has the same slope as this line

## Circle Constraints

 * Coincident - Given a circle, achieved if that circle is in exactly the same location as this circle
 * Through - Given a point, achieved if this circle passes through that point
 * Intersecting - Given a line, achieved if that line crosses this circle
 * Intersecting - Given a circle, achieved if that circle crosses this circle
 * About - Given a point, achieved if that point is coincident with this circle's center

## Distance Constraints

 * Equal - Given a distance, achieved if that distance is the same as this distance
 * Constant - Given a number, achieved if this distance is the same as that number
 * Less - Given a distance, achieved if this distance is shorter than that distance
 * Greater - Given a distance, achieved if this distance is longer than that distance
 * Between - Given two points, achieved if this distance is the same as the length between those two points

## Angle Constraints

 * Equal - Given an angle, achieved if the sweep of this angle is the same as the sweep of that angle
 * Constant - Given a number, achieved if the sweep of this angle is equal to that number
 * Wider - Given an angle, achieved if the sweep of this angle is greater than the sweep of that angle
 * Narrower - Given an angle, achieved if the sweep of this angle is less than the sweep of that angle
 * Between - Given two lines, achieved if this angle's sweep is the same as the small sweep between those two lines
