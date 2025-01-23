/* Complete the scary_double_push function.
 *
 *   * Push the value 1337 directly onto the stack
 *     using the stack_push function.
 *     You'll need to cast the value to a void *.
 *
 *   * Allocate memory for a new int on the heap
 *
 *   * Set the value that the address points to to 1024
 *
 *   * Push the int pointer onto the stack using
 *     the stack_push function
 *  */

#include "snekstack.c"
#include "snekstack.h"
#include "stdlib.h"

void scary_double_push(stack_t *s) {
  stack_push(s, (void *)1337);

  int *newInt = malloc(sizeof(int));
  *newInt = 1024;

  stack_push(s, newInt);
}
