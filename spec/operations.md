# Operations

## Definition Operations

 * Define Object Primitive - This operation creates an object primitive of some kind based on other objects or absolute information specified.
 * Define Measurement Primitive - This operation creates a measurement primitive of some kind based on other objects or absolute information specified.
 * Define Collection Primitive - This operation creates a collection primitive of some kind based on other objects or absolute information specified.

## Execution Operations

 * Execute - This operation supplies givens to a procedure, evaluates it, and provides the procedure's result to the current workspace.
 * Execute If - This operation functions exactly as the Execute operation, except that it only executes the procedure if a specified Collection is non-empty
 * Provide - This operation indicates the result of the current procedure

## Collection Operations

 * Most - This operation takes a Vector and provides the object furthest in the direction of the vector.
 * Choose - This operation provides a single arbitrary object from the collection.
 * Union - This operation provides a collection containing all elements present in any of the supplied collections
 * Intersection - This operation provides a collection containing all elements present in every one of the supplied collections.
 * Refine - This operation applies a Constraint to a Collection Primitive, providing a new Collection that contains all elements within the provided collection that achieve the constraint.