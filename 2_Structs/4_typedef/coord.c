/* 1. Update the Coordinate declaration in coord.h
 * to use typedef to create a new type called coordinate_t.
 *
 * 2. Update the new_coord and scale_coordinate functions
 * to use the coordinate_t type instead of struct Coordinate.
 * */

#include "coord.h"

coordinate_t new_coord(int x, int y, int z) {
  coordinate_t coord = {.x = x, .y = y, .z = z};

  return coord;
}

coordinate_t scale_coordinate(coordinate_t coord, int factor) {
  coordinate_t scaled = coord;
  scaled.x *= factor;
  scaled.y *= factor;
  scaled.z *= factor;

  return scaled;
}
