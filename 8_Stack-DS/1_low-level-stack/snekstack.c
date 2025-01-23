/* Take a look at snekstack.h, specifically the Stack struct.
 * 
 * * count is the number of elements in the stack.
 *
 * * capacity is the number of elements the stack can hold
 *   before it needs to be resized in memory.
 *
 * * data is a pointer to all the generic data.
 *
 * Implement the stack_new function:
 * 
 * * Allocate memory for a new Stack struct on the heap.
 *
 * * If allocation fails, return NULL.
 *
 * * Initialize the count to 0.
 *
 * * Initialize the capacity to the given value.
 *
 * * Initialize the data by allocating enough memory
 *   for capacity number of void * pointers.
 *
 * * If allocation fails, free the Stack struct and return NULL.
 *
 * * Return the new Stack struct.
*/
#include "snekstack.h"
#include <stdlib.h>

stack_t *stack_new(size_t capacity) {
  stack_t *stack_ptr = malloc(sizeof(stack_t));
  if (stack_ptr == NULL) {
    return NULL;
  }

  stack_ptr->count = 0;
  stack_ptr->capacity = capacity;
  stack_ptr->data = (void *)malloc(capacity);

  if (stack_ptr->data == NULL) {
    free(stack_ptr);
    return NULL;
  }
  return stack_ptr;
}
