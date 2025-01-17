/*
 * Complete the new_coord function.
 * It accepts 3 integers and returns a Coordinate.
 *
 * Use the "designated initializer" syntax...
 * because I said so.
 */

#include "coord.h"

struct Coordinate new_coord(int x, int y, int z) {
    struct Coordinate c = {
        .x = x,
        .y = y,
        .z = z,
    };

    return c;
}
