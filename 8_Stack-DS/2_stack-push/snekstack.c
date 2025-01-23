/* Complete the stack_push function.
 * It safe(ish)ly adds a new object to the top
 * of the stack. Remember: the size of the data array
 * is the capacity of the stack, and
 * the number of elements that are actually in the stack
 * is the count (which is less than or equal to the capacity).
 *
 * If the stack's count is equal to the stack's capacity:
 *   * Double the stack's capacity
 *   * Reallocate enough memory for the stack's data
 *     using the new capacity
 *   * If realloc fails, free the old data and return immediately
 *   * If it succeeds, update the stack's data field
 *     to point to the new memory
 *
 * Add the new object to the top of the stack
 * (the count-th element in the array)
 *
 * Increment the stack's count
 */

#include "snekstack.h"
#include <assert.h>
#include <stddef.h>
#include <stdlib.h>

void stack_push(stack_t *stack, void *obj) {
  if (stack->capacity == stack->count) {
    stack->capacity *= 2;
    // this also pass the test
    // void *biggerStack = realloc(stack->data, stack->capacity * sizeof(void *));
    void **biggerStack = realloc(stack->data, stack->capacity * sizeof(void *));
    if (biggerStack == NULL) {
      free(stack->data);
      exit(1);
    }
    stack->data = biggerStack;
  }

  stack->data[stack->count] = obj;
  stack->count++;
  return;
}

// don't touch below this line

stack_t *stack_new(size_t capacity) {
  stack_t *stack = malloc(sizeof(stack_t));
  if (stack == NULL) {
    return NULL;
  }

  stack->count = 0;
  stack->capacity = capacity;
  stack->data = malloc(stack->capacity * sizeof(void *));
  if (stack->data == NULL) {
    free(stack);
    return NULL;
  }

  return stack;
}
