/* Complete the swap_strings function.
 * It swaps the values stored in the string pointers.
 *
 * Remember, char ** is a pointer to a char pointer,
 * which means we can simply switch the "address"
 * that we're referencing in our swap function.
 *
 * You won't need to use any str_ specific functions
 * for this swap implementation.
 */

void swap_strings(char **a, char **b) {
  char *c = *a;
  *a = *b;
  *b = c;
}
