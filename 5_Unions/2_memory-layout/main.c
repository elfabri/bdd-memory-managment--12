/* Take a look at the val_or_err_t union.
 * It represents either an integer value
 * or an unsigned (non-negative) integer error code.
 * 
 * Run the code in its current state.
 *
 * Notice that the .value field is set to -420,
 * then the data in each field is printed.
 * The .value field works as you'd expect, printing -420.
 * However, the .error field prints 4294966876!
 * It's trying to interpret the bytes of -420 as an unsigned integer,
 * which results in a very large number.
 * 
 * Uncomment the next block of code, and run it without submitting.
 * Notice that now we set the .err field (an unsigned integer)
 * to UINT_MAX, which is a constant representing the largest possible
 * unsigned integer (4294967295 in my case).
 * As expected, the .err field prints 4294967295.
 * However, the .value field prints -1! It's interpreting
 * the bytes that represent 4294967295 as an unsigned integer
 * as a signed integer, which is -1.
 *
 * Submit the fully uncommented code.
 */

#include <stdio.h>

#include "limits.h"
#include "munit.h"

typedef union {
  int value;
  unsigned int err;
} val_or_err_t;

int main() {
  val_or_err_t lanes_score = {
    .value = -420
  };
  printf("value (set): %d\n", lanes_score.value);
  printf("err (unset): %u\n", lanes_score.err);

  val_or_err_t teejs_score = {
    .err = UINT_MAX
  };
  printf("value (unset): %d\n", teejs_score.value);
  printf("err (set): %u\n", teejs_score.err);
} 
