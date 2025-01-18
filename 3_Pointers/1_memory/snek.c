/* The size_of_addr function accepts a long long
 * (a potentially very large integer) as input
 * and returns the size of its address.
 *
 * There's a bug! Memory addresses in Sneklang
 * should always be 4 bytes long...
 *
 * Fix the function so that it returns
 * the size of i's address, not value.
 */

#include "snek.h"

unsigned long size_of_addr(long long i){
  unsigned long sizeof_snek_version = sizeof(&i);
  return sizeof_snek_version;
}
