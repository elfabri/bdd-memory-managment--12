/* Sneklang is admittedly a fairly inefficient language
 * (don't tell the VC investors!). Sometimes,
 * rather than carefully managing memory,
 * the Sneklang interpreter allocates a big chunk of stack data
 * - simply because the creators (us) are too lazy
 *   to allocate the right amount.
 *
 * Anyhow, the BDFL of Sneklang has allowed this laziness,
 * but only to a maximum amount of 10 kibibyte.
 * A single kibibyte is 1024 bytes.
 *
 * 1 Run the code in its current state.
 *   You should get a stack overflow which will cause
 *   a segmentation fault.
 *
 * 2 Fix the pool_size so that it allocates exactly 10 kibibyte.
 */

#include <stdio.h>

int main() {
  const int pool_size = 1024 * 10;
  char snek_pool[pool_size];
  snek_pool[0] = 's';
  snek_pool[1] = 'n';
  snek_pool[2] = 'e';
  snek_pool[3] = 'k';
  snek_pool[4] = '\0';

  printf("Size of pool: %d\n", pool_size);
  printf("Initial string: %s\n", snek_pool);
  return 0;
}
