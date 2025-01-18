/* Fix the change_filetype function (both in the .c and .h files).
 *
 * It should:
 *
 * * Accept a pointer to a code file
 * * Dereference the pointer into a codefile_t struct
 * * Change the filetype field to the provided new_filetype value
 * * Return the updated codefile_t struct
 */

#include "exercise.h"

codefile_t change_filetype(codefile_t *f, int new_filetype){
  codefile_t new_f = *f;
  new_f.filetype = new_filetype;
  return new_f;
}
