/* Complete the stack_push_multiple_types function.
 * 
 *   * Allocate a float * on the heap
 *     and set the value that's pointed to to 3.14
 *
 *   * Push the float * onto the stack using stack_push
 *
 *   * Allocate a char * on the heap and set the value
 *     that's pointed to to Sneklang is blazingly slow!
 *
 *   * Push the char * onto the stack using stack_push
 */
#include "snekstack.h"
#include "stdlib.h"
#include "exercise.h"

void stack_push_multiple_types(stack_t *s) {
  float *floatPtr = malloc(sizeof(float));
  *floatPtr = 3.14f;
  stack_push(s, floatPtr);

  char **charPtr = malloc(28);
  *charPtr = "Sneklang is blazingly slow!";
  stack_push(s, *charPtr);
}
