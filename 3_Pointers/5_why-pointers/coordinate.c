/* Complete the coordinate_update_x and
 * coordinate_update_and_return_x functions.
 *
 * coordinate_update_x should update the x field
 * with the provided new_x value. It returns void.
 *
 * coordinate_update_and_return_x should update the x field
 * with the provided new_x value, 
 * nd then return the updated coordinate struct.
 */

#include "coordinate.h"

void coordinate_update_x(coordinate_t coord, int new_x) {
    coord.x = new_x;
}

coordinate_t coordinate_update_and_return_x(coordinate_t coord, int new_x) {
    coord.x = new_x;
    return coord;}
