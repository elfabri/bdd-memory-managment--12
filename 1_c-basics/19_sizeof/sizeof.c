/*
 * Run the function to see the size of a char.
 * Update main to also print the size of each of the following
 * types in order:
 *
 *  * bool
 *  * int
 *  * float
 *  * double
 *  * size_t
 *
 * Take a look at the results before moving on!
 * Notice that a char only takes up 1 byte (8 bits),
 * while the other types take up more space.
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

int main() {
  // Use %zu is for printing `sizeof` result
  printf("sizeof(char)   = %zu\n", sizeof(char));
  printf("sizeof(bool)   = %zu\n", sizeof(bool));
  printf("sizeof(int)   = %zu\n", sizeof(int));
  printf("sizeof(float)   = %zu\n", sizeof(float));
  printf("sizeof(double)   = %zu\n", sizeof(double));
  printf("sizeof(size_t)   = %zu\n", sizeof(size_t));
}

