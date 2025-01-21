/* * 1 Run the code in its current state.
 *
 * See how with each successive nested function call
 * (printMessageOne, which calls printMessageTwo,
 * which calls printMessageThree)
 * the memory addresses allocate more and more space?
 *
 * * 2 Update where printMessageTwo and printMessageThree
 *     are called from so that all three of the functions
 *     use the same stack space.
 *
 * The offsets printed by printStackPointerDiff
 * should now be different from before.
 * The printStackPointerDiff() calls should
 * remain at the start of each function.
*/

#include <stdio.h>
#include "exercise.h"

int main() {
  printMessageOne();
  printMessageTwo();
  printMessageThree();
  return 0;
}

void printMessageOne() {
  const char *message = "Dark mode?\n";
  printStackPointerDiff();
  printf("%s\n", message);
  // printMessageTwo();
}

void printMessageTwo() {
  const char *message = "More like...\n";
  printStackPointerDiff();
  printf("%s\n", message);
  // printMessageThree();
}

void printMessageThree() {
  const char *message = "dark roast.\n";
  printStackPointerDiff();
  printf("%s\n", message);
}

// don't touch below this line

void printStackPointerDiff() {
  static void *last_sp = NULL;
  void *current_sp;
  current_sp = __builtin_frame_address(0);
  long diff = (char*)last_sp - (char*)current_sp;
  if (last_sp == NULL){
    last_sp = current_sp;
    diff = 0;
  }
  printf("---------------------------------\n");
  printf("Stack pointer offset: %ld bytes\n", diff);
  printf("---------------------------------\n");
}
