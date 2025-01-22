#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "exercise.h"
#include "munit.h"

/*
munit_case(RUN, test_swap_str, {
  char *a = "Hello";
  char *b = "Goodbye";

  swap_strings(&a, &b);

  assert_string_equal(a, "Goodbye", "a is now 'Goodbye'");
  assert_string_equal(b, "Hello", "b is now 'Hello'");
});

munit_case(SUBMIT, test_swap_str_long, {
  char *a = "terminal.shop";
  char *b = "ssh";

  swap_strings(&a, &b);

  assert_string_equal(a, "ssh", "a is now 'ssh'");
  assert_string_equal(b, "terminal.shop", "b is now 'terminal.shop'");
});
*/

static MunitResult
test_swap_str() {
  char *a = "Hello";
  char *b = "Goodbye";

  swap_strings(&a, &b);

  // , "a is now 'Goodbye'"
  munit_assert_string_equal(a, "Goodbye");
  // , "b is now 'Hello'"
  munit_assert_string_equal(b, "Hello");
  return MUNIT_OK;
}

static MunitResult
test_swap_str_long() {
  char *a = "terminal.shop";
  char *b = "ssh";

  swap_strings(&a, &b);

  // , "a is now 'ssh'"
  munit_assert_string_equal(a, "ssh");
  // , "b is now 'terminal.shop'"
  munit_assert_string_equal(b, "terminal.shop");
  return MUNIT_OK;
}

int main() {
  MunitTest tests[] = {
      {
          "/test_swap_str",
          test_swap_str,
          NULL,
          NULL,
          MUNIT_TEST_OPTION_NONE,
          NULL
      },
      {
          "/test_swap_str_long",
          test_swap_str_long,
          NULL,
          NULL,
          MUNIT_TEST_OPTION_NONE,
          NULL
      },
      { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
    };

    MunitSuite suite = {
        "/swap_strs", /* name */
        tests, /* tests */
        NULL, /* suites */
        1, /* iterations */
        MUNIT_SUITE_OPTION_NONE /* options */
    };

  return munit_suite_main(&suite, NULL, 0, NULL);
}
