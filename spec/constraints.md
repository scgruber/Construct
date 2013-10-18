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

## Vector Constraints

 * Equal - Given a vector, achieved if the magnitude of that vector is the same as this vector
 * Parallel - Given a vector, achieved if the direction of that vector is the same as this vector
 * Unit - Achieved if the magnitude of this vector is 1

## Angle Constraints

 * Equal - Given two angles, achieved if the sweep of the angles is the same
 * Right - Achieved if the sweep of this angle is 90 degrees
 * Acute - Acheived if the sweep of this angle is less than 90 degrees
 * Obtuse - Achieved if the sweep of this angle is greater than 90 degrees
