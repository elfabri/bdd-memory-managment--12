#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "exercise.h"
#include "munit.h"

/*
munit_case(RUN, test_swap_ints, {
  int a = 5;
  int b = 6;

  swap_ints(&a, &b);

  assert_int(a, ==, 6, "a is now 6");
  assert_int(b, ==, 5, "b is now 5");
});

munit_case(SUBMIT, test_swap_ints_same, {
  int a = 5;

  swap_ints(&a, &a);

  assert_int(a, ==, 5, "a is still 5");
});
*/

static MunitResult
test_swap_ints() {
  int a = 5;
  int b = 6;

  swap_ints(&a, &b);

  // , "a is now 6"
  munit_assert_int(a, ==, 6);
  // , "b is now 5"
  munit_assert_int(b, ==, 5);
  return MUNIT_OK;
}

static MunitResult
test_swap_ints_same() {
  int a = 5;

  swap_ints(&a, &a);

  // , "a is still 5"
  munit_assert_int(a, ==, 5);
  return MUNIT_OK;
}

int main() {
  MunitTest tests[] = {
      {
          "/test_swap_ints",
          test_swap_ints,
          NULL,
          NULL,
          MUNIT_TEST_OPTION_NONE,
          NULL
      },
      {
          "/test_swap_ints_same",
          test_swap_ints_same,
          NULL,
          NULL,
          MUNIT_TEST_OPTION_NONE,
          NULL
      },
      { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
    };

    MunitSuite suite = {
        "/swap_ints", /* name */
        tests, /* tests */
        NULL, /* suites */
        1, /* iterations */
        MUNIT_SUITE_OPTION_NONE /* options */
    };

  return munit_suite_main(&suite, NULL, 0, NULL);
}
