/* Let's get back to Sneklang's built in 2D graphics library.
 * Take a look at the new_coord function.
 * It accepts an x and y value and creates
 * a new pointer to a stack-allocated coord_t struct.
 *
 * 1 - Run the code in its current state.
 * You should see something... weird.
 * Why don't the x and y values match
 * the ones passed in on lines 16-18???
 *
 * Because we're accessing stack memory
 * (the pointer created on line 12) outside of the function
 * that created it, the memory has been deallocated
 * and is no longer safe to use. Technically the behavior
 * is undefined, but it's likely that in this specific
 * scenario you're just seeing it get overwritten by
 * the next function call (thus 50 and 60 always print).
 * 
 *  2 - Fix the new_coord function so that it returns a struct,
 * not a pointer to a struct. This will force the compiler
 * to copy the struct to the main function's stack frame,
 * and the memory will be safe to use.
 * You'll have to update syntax in a few places
 * to accomodate the change.
 *
 */
#include <stdio.h>

typedef struct {
  int x;
  int y;
} coord_t;

// coord_t *new_coord(int x, int y) {
coord_t new_coord(int x, int y) {
  coord_t c;
  c.x = x;
  c.y = y;
  return c;
}

int main() {
  coord_t c1 = new_coord(10, 20);
  coord_t c2 = new_coord(30, 40);
  coord_t c3 = new_coord(50, 60);

  // printf("c1: %d, %d\n", c1->x, c1->y);
  printf("c1: %d, %d\n", c1.x, c1.y);
  printf("c2: %d, %d\n", c2.x, c2.y);
  printf("c3: %d, %d\n", c3.x, c3.y);
}
