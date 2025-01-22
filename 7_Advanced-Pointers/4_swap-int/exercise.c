/* Before we do something more tricky,
 * let's start with just swapping some integers.
 * Complete the swap_ints function. It accepts
 * two pointers to integers, and should swap
 * the values of the integers they point to.
 *
 * You'll need to use a temporary variable
 * to store one of the values while you swap them.
 */

void swap_ints(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}
