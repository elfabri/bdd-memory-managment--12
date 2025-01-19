/* Take a look at the main function.
 * It declares an array of numbers core_utilization
 * that represents the CPU utilization of each core
 * on a system running the Sneklang interpreter.
 * The array has 8 elements. On lines 31 and 32
 * it prints the size of the array and the length of the array.
 *
 * Complete the core_utils_func function to print:
 *
 * * sizeof core_utilization in core_utils_func: X
 *
 * Where X is the size of the array calculated using the sizeof operator.
 *
 * Once you've completed the function, run it and
 * take a look at the output. You'll notice that
 * due to the array decaying to a pointer, the reported size
 * is the size of a pointer, not the size of the actual array.
 *
 * this happens with arrays when they are used on functions, they 
 * "decay to pointers".
 */

#include <stdio.h>

void core_utils_func(int core_utilization[]) {
  printf("sizeof core_utilization in core_utils_func: %zu\n", sizeof(core_utilization));
}

// don't touch below this line

int main() {
  int core_utilization[] = {43, 67, 89, 92, 71, 43, 56, 12};
  int len = sizeof(core_utilization) / sizeof(core_utilization[0]);
  printf("sizeof core_utilization in main: %zu\n", sizeof(core_utilization));
  printf("len of core_utilization: %d\n", len);
  core_utils_func(core_utilization);
  return 0;
}
