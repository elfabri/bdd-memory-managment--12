/* Implement the print_numbers prototyped in exercise.h
 * that takes a starting number and an ending number
 * and prints all the numbers in that range inclusive
 * (using a for-loop).
 */

#include <stdio.h>
#include "exercise.h"

void print_numbers(int start, int end) {
    for(int i = start; i <= end; i++) {
        printf("%d\n",i);
    }
}
