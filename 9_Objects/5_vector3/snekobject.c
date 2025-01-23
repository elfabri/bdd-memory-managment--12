/* Vector3 is going to be the first Snek Object
 * that can hold a reference to another Snek Object.
 * It's a collection type: a type that holds other types.
 *
 *  * In snekobject.h:
 *
 *    - Forward declare the snek_object_t struct
 *      at the top of the file. It will need to be used
 *      in a circular dependency between
 *      snek_object_t -> snek_object_data_t -> snek_vector_t.
 *
 *    - Create a new struct called snek_vector_t
 *      that has three fields.
 *      Name the fields x, y, and z.
 *      Each field should be a Sneklang Object pointer
 *      (snek_object_t *).
 *
 *    - Add a new enum value to the snek_object_kind_t enum
 *      called VECTOR3.
 *
 *    - Add a new snek_vector_t field
 *      (the struct type you just created) to snek_object_data_t
 *      called v_vector3.
 *
 *    - Declare the new_snek_vector3 function.
 *
 * Note that the v_vector3 field is not a pointer to a vector3;
 * it's directly allocated inside the struct.
 * We can do this because we know the size of the vector
 * (it's only 3 pointers wide) in advance.
 *
 *  * In snekobject.c, complete the new_snek_vector3 function:
 *
 *    - If any of the inputs are NULL, return NULL.
 *
 *    - Allocate memory for a new pointer to a snek_object_t,
 *      and if the allocation fails return NULL.
 *
 *    - Set the kind field to the appropriate enum.
 * 
 *    - Create a new snek_vector_t struct and set the x, y,
 *      and z fields to the input pointers.
 * 
 *    - Set the v_vector3 field of the new snek object
 *      to the newly created snek_vector_t.
 *
 *    - Return the pointer to the new snek object.
 */

#include <stdlib.h>
#include <string.h>

#include "snekobject.h"

snek_object_t *new_snek_vector3(
    snek_object_t *x, snek_object_t *y, snek_object_t *z
) {
  if (x == NULL || y == NULL || z == NULL) {
    return NULL;
  }
  snek_object_t *obj = malloc(sizeof(snek_object_t *));
  if (obj == NULL) {
    return NULL;
  }
  obj->kind = VECTOR3;
  snek_vector_t newVector = {
    .x = x,
    .y = y,
    .z = z,
  };
  obj->data.v_vector3 = newVector;
  return obj;
}

// don't touch below this line

snek_object_t *new_snek_integer(int value) {
  snek_object_t *obj = malloc(sizeof(snek_object_t));
  if (obj == NULL) {
    return NULL;
  }

  obj->kind = INTEGER;
  obj->data.v_int = value;
  return obj;
}

snek_object_t *new_snek_float(float value) {
  snek_object_t *obj = malloc(sizeof(snek_object_t));
  if (obj == NULL) {
    return NULL;
  }

  obj->kind = FLOAT;
  obj->data.v_float = value;
  return obj;
}

snek_object_t *new_snek_string(char *value) {
  snek_object_t *obj = malloc(sizeof(snek_object_t));
  if (obj == NULL) {
    return NULL;
  }

  int len = strlen(value);
  char *dst = malloc(len + 1);
  if (dst == NULL) {
    free(obj);
    return NULL;
  }

  strcpy(dst, value);

  obj->kind = STRING;
  obj->data.v_string = dst;
  return obj;
}
