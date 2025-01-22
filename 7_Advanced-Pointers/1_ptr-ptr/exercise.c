/* Complete the allocate_int function.
 * It accepts a pointer to a pointer to an integer
 * called pointer_pointer, and a raw value.
 * Change the value of pointer_pointer's pointer's address
 * to point to new memory that has the value of the int.
 *
 * 1 - Allocate memory for a single integer on the heap,
 *     and save its address into a new pointer.
 *
 * 2 - Update the memory address that pointer_pointer is pointing to,
 *     to be the address of the new pointer.
 *
 * 3 - Set the raw value of the integer that
 *     pointer_pointer now points to
 *     (well, that it points to through 2 address hops)
 *     to the value passed in.
 *
 * Observe: If you take a look at test_does_not_overwrite
 * in the main.c file, you'll notice that
 * while pointer_pointer does indeed unravel
 * and point to the new value, the original value
 * still exists at its spot in memory.
 * We just don't point to it anymore.
 */

#include "stdlib.h"
#include "exercise.h"

void allocate_int(int **pointer_pointer, int value) {
  int *ptr = (int *)malloc(sizeof(int));
  // *ptr = value;
  *pointer_pointer = ptr;
  **pointer_pointer = value;
}
