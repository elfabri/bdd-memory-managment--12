/* Run the get_full_greeting function in its current state.
 * If you take a look at the main.c file,
 * you'll notice that it's testing to ensure that a pointer
 * to stack memory isn't returned
 * (which you never should do, because it's undefined behavior).
 *
 * Fix the get_full_greeting function so that
 * it allocates memory on the heap
 * and returns a pointer to that memory.
 */

#include <stdio.h>
#include <stdlib.h>
#include "exercise.h"

char *get_full_greeting(char *greeting, char *name, int size) {
  char *heapBuffer = (char*)malloc(size);
  if (heapBuffer == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(1);
  }
  snprintf(heapBuffer, size, "%s %s", greeting, name);
  return heapBuffer;
}
