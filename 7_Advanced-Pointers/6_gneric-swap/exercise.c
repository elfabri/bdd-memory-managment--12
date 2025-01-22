/* Implement the generic swap() function.
 *
 * 1 - Allocate memory for a temporary buffer to store the data using malloc.
 * 2 - If the allocation fails (returns NULL) return immediately.
 * 3 - Use memcpy to shuffle the data around.
 * 4 - Don't forget to free the temporary buffer.
 */

#include <stdlib.h>
#include <string.h>

void swap(void *vp1, void *vp2, size_t size) {
  void *tmp = malloc(size);
  if (tmp == NULL) {
    exit(1);
  }
  memcpy(tmp, vp1, size);
  memcpy(vp1, vp2, size);
  memcpy(vp2, tmp, size);
  free(tmp);
}
