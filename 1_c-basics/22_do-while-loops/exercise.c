/* Run the code. Notice that it prints 5 -> 1.
 * However, it doesn't print anything from 1 -> 5
 * because the condition of the while loop is never true.
 * Change print_numbers_reverse to use a do-while loop
 * so that it always at least prints the starting number.
 */
#include <stdio.h>

void print_numbers_reverse(int start, int end) {
  do {
    printf("%d\n", start);
    start--;
  } while (start >= end);
}
