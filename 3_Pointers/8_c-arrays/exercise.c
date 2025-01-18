/* Complete the update_file function.
 * The filedata array is a large 200-integer array
 * representing a Sneklang source file. Each integer
 * in the array represents a special piece of data.
 *
 * * Index 1 is the number of lines
 * * Index 2 is the filetype
 * * Index 199 is always 0
 *
 * Update the function so that it overwrites indexes 1 and 2
 * with the provided values, and ensures that index 199 is always 0.
 *
 * Note: Notice that by modifying the array within your function,
 * you're changing the values of the original array,
 * not just a copy. More on that later.
 */

#include "exercise.h"

void update_file(int filedata[200], int new_filetype, int new_num_lines){
    filedata[1] = new_num_lines;
    filedata[2] = new_filetype;
    filedata[199] = 0;
}
