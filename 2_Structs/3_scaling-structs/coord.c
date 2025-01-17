/* Open coord.h and add a declaration for
 * the scale_coordinate function as defined
 * in the coord.c file.
 *
 * Complete the scale_coordinate function in coord.c.
 * It should return a new Coordinate where each field
 * is scaled up (multiplied) by the factor parameter.
 */

#include "coord.h"

struct Coordinate new_coord(int x, int y, int z) {
  struct Coordinate coord = {.x = x, .y = y, .z = z};
  return coord;
}

struct Coordinate scale_coordinate(struct Coordinate coord, int factor) {
  coord.x *= factor;
  coord.y *= factor;
  coord.z *= factor;

  return coord;
}
