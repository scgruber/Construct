# Constraints

Constraints are used to specify Collection Primitives.

## Collection to Object Constraints

These constraints provide a single object when applied to a collection.
The provided object is guaranteed to have been a member of the original collection.

 * Most - This constraint takes a Vector and provides the object furthest in the direction of the vector.
 * Choose - This provides a single object from the collection.

## Collection to Collection Constraints

These constraints provide a collection when applied to a collection.
The provided collection is guaranteed to have been a subset of the original collection.

 * Beyond - This constraint takes a Line Primitive and a Vector and provides the collection of objects which are on the side of the Line in the direction of the Vector.
 * Within - This constraint takes a Circle Primitive and provides the collection of objects which are inside of the Circle.
 * Without - This constraint takes a Circle Primitive and provides the collection of objects which are outside the bounds of the Circle.

## Multi-Collection to Collection Constraints

These constraints provide a single collection when applied to multiple collections.
The provided collection is guaranteed to have been a subset of the union of the original collections.

 * Union - This constraint provides a collection containing all of the objects within any of the original collections.
 * Intersection - This constraint provides a collection containing all of the objects contained in every one of the original collections.