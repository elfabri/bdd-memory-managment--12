/* Implement the print_numbers_reverse prototyped in exercise.h.
 * It takes a starting number (higher) and an ending number (lower)
 * and prints all the numbers in that range from highest to lowest
 * inclusive (this time, using a while-loop).
 */

#include <stdio.h>
#include "exercise.h"

void print_numbers_reverse(int start, int end) {
    while (start >= end) {
        printf("%d\n", start);
        start--;
    }
}
