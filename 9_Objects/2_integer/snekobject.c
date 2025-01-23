/* Complete the new_snek_integer function in snekobject.c. It should:
 * 
 * 1 - Use malloc to allocate heap memory for a new pointer
 *     to a snek_object_t.
 *
 * 2 - If the allocation fails, return NULL.
 *
 * 3 - Set the kind field of the new snek object
 *     to the INTEGER enum value (defined in snekobject.h).
 *
 * 4 - Set the v_int field of the new snek object
 *     to the integer value passed in.
 *
 * 5 - Return the pointer to the new snek object.
 *
 * If you're curious how this will be used,
 * take a look at the main.c file (where the tests are).
 * You'll see some code that looks like this:
 * 
 * snek_object_t *int_object = new_snek_integer(42);
 */

#include <stdlib.h>

#include "snekobject.h"

snek_object_t *new_snek_integer(int value) {
  snek_object_t *int_obj = malloc(sizeof(int));
  if (int_obj == NULL) {
    return NULL;
  }
  int_obj->kind = INTEGER;
  int_obj->data.v_int = value;
  return int_obj;
}
