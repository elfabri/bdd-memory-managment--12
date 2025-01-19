/* Take a look at the dump_graphics function.
 * It works similarly to the example above.
 *
 * Go ahead and run it in its current state.
 * You should notice that after all the values
 * specified in main.c are printed...
 * all hell breaks loose. That's because we've ventured out
 * of the bounds of our array! We're off the reservation!
 * We're in the weeds! We're in undefined territory.
 * This is something you do not want to do.
 * It's one of the things that makes C powerful but dangerous.
 * Other languages stop you from going out of bounds,
 * but C will let you fly off the edge of the world.
 *
 * Fix the loop to only print the values that
 * are actually in the array of structs. Take a look
 * at the graphics_t struct in exercise.h
 * to figure out how large each struct is.
 */
#include <stdio.h>
#include "exercise.h"

void dump_graphics(graphics_t gsettings[10]) {
  int *ptr = (int *)gsettings;
  for (int i = 0; i < 30; i++) {
    printf("settings[%d] = %d\n", i, ptr[i]);
  }
}
