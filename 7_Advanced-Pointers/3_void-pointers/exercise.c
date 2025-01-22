/* In Sneklang, we have to dynamically interpret Snek code
 * and store the values in memory. The snek_object_kind_t enum
 * defines the different types of objects
 * that can be stored in memory.
 *
 * Complete the snek_zero_out function.
 * It accepts a generic pointer to one of:
 *
 * * snek_int_t
 * * snek_float_t
 * * snek_bool_t
 *
 * It should "zero out" the .value field of the struct
 * by setting it to the zero value of its type.
 * Use the kind parameter to figure out
 * which type of struct you are working with.
 */
#include "exercise.h"

void snek_zero_out(void *ptr, snek_object_kind_t kind){
  switch (kind) {
    case INTEGER:
      snek_int_t *intPtr = (snek_int_t *)ptr;
      intPtr->value = 0;
      break;
    case FLOAT:
      snek_float_t *floatPtr = (snek_float_t *)ptr;
      floatPtr->value = 0;
      break;
    case BOOL:
      snek_bool_t *bPtr = (snek_bool_t *)ptr;
      bPtr->value = 0;
      break;
    default:
      break;
  }
}
