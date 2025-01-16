/*
 * Run the code. You should get a compilation error.
 * When updating a variable's value,
 * you don't need to redeclare the type. In fact, you can't.
 * Fix the code so that it updates (64 -> 32) properly.
 * */

#include <stdio.h>

int main() {
  int sneklang_int_size = 64;
  sneklang_int_size = 32;
  printf("Sneklang int size: %d bits\n", sneklang_int_size);
  return 0;
}
