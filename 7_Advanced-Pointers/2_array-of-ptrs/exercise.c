/* Sneklang, being a super-robust programming language toolchain,
 * needs to represent "Tokens" - strings of text
 * that represent Sneklang syntax, things like if, else and def.
 * They're represented as structs,
 * you can see the struct in exercise.h.
 *
 * Take a look at create_token_pointer_array.
 * It correctly allocates an array of token pointers on the heap,
 * but notice that the addresses it's adding to each index
 * are the addresses of the stack-allocated inputs.
 *
 * 1 - Update the create_token_pointer_array's loop
 *     to allocate new space for each token on the heap,
 *     and store the address of the new space in the array.
 *
 * 2 - Copy the members of the input struct
 *     into the newly allocated one.
 */
#include <stdlib.h>

#include "exercise.h"

token_t **create_token_pointer_array(token_t *tokens, size_t count) {
  // allocate array of pointers
  token_t **token_pointers = malloc(count * sizeof(token_t*));
  if (token_pointers == NULL) {
    exit(1);
  }
  for (size_t i = 0; i < count; ++i) {
    // allocate new space for each token on the heap
    token_t *t = malloc(sizeof(token_t));
    // 2
    *t = tokens[i];
    // store the adress of the new space in the array
    token_pointers[i] = t;
  }
  return token_pointers;
}
