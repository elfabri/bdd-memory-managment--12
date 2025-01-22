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
 *
 * Fix the code by freeing the allocated list
 * at the end of each loop.
 */

#include <stdio.h>
#include <stdlib.h>
#include "exercise.h"

int main(){
  const int num_lists = 500;
  for (int i = 0; i < num_lists; i++) {
    int *lst = allocate_scalar_list(50000, 2);
    if (lst == NULL) {
      printf("Failed to allocate list\n");
      return 1;
    } else {
      printf("Allocated list %d\n", i);
    }
    free(lst);
  }
  return 0;
}
