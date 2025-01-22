/* We may be inefficient here at Sneklang,
 * but we don't want outright memory leaks!
 *
 * Run the code in its current state.
 * After a number of successful allocations
 * you should get a failure. The program
 * is running out of memory due to a leak.
 *
 * See how it's calling the allocate_scalar_list
 * function in a loop? Well, the lists aren't needed
 * from loop to loop, so they should be freed
 * at the end of each iteration.
 * If we do that, we should be able to allocate
 * as many lists as we want (because we return
 * the memory in between iterations).
 * Fix the code by freeing the allocated list
 * at the end of each loop.
 */

#include <stdlib.h>
#include "exercise.h"

int *allocate_scalar_list(int size, int multiplier) {
  int *lst = (int *)malloc(size * sizeof(int));
  if (lst == NULL) {
    return NULL;
  }
  for (int i = 0; i < size; i++) {
    lst[i] = i * multiplier;
  }
  return lst;
}
