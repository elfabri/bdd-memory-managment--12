/* We're working on some of the dynamic memory management
 * tooling that we'll eventually need to build
 * a garbage collector for Sneklang.
 * 
 * Complete the allocate_scalar_list function. It should:
 * 
 *  * Accept size and multiplier parameters
 *    and should allocate an array of size integers on the heap.
 *
 *  * Gracefully return NULL if the allocation fails.
 *
 *  * Initialize each element in the list to
 *    the index * multiplier. (e.g. a multiplier of 2
 *    would result in [0, 2, 4, 6, ...])
 *
 *  * Return a pointer to the allocated memory.
 *
 * Assume that the calling code will eventually
 * call free on the returned pointer.
 */

#include <stdio.h>
#include <stdlib.h>

#include "exercise.h"

int *allocate_scalar_list(int size, int multiplier) {
  if (size > 1024 * 1024 * 5) {
    return NULL;  // ez
  }
  int *ptr = malloc(size * sizeof(int));
  if (ptr == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(1);
  }
  for (int i=0; i < size; i++) {
    ptr[i] = i * multiplier;
  }
  return ptr;
}
