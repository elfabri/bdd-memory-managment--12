/* At the start of main(), print the size of the two enums
 * defined in main.c, in the format:
 *
 * * The size of BigNumbers is Y bytes
 * * The size of HttpErrorCode is X bytes
 *
 * Remember that %zu is the format specifier for size_t.
 */
#include <stdio.h>

typedef enum {
  BIG = 123412341234,
  BIGGER,
  BIGGEST,
} BigNumbers;

typedef enum {
  HTTP_BAD_REQUEST = 400,
  HTTP_UNAUTHORIZED = 401,
  HTTP_NOT_FOUND = 404,
  HTTP_I_AM_A_TEAPOT = 418,
  HTTP_INTERNAL_SERVER_ERROR = 500
} HttpErrorCode;

int main() {
  printf("The size of BigNumbers is %zu bytes\n", sizeof(BigNumbers));  // 8
  printf("The size of HttpErrorCode is %zu bytes\n", sizeof(HttpErrorCode));  // 4
  return 0;
}
