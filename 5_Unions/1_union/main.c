#define MUNIT_ENABLE_ASSERT_ALIASES
#include <stdio.h>

#include "exercise.h"
#include "munit.h"

/*
munit_case(RUN, test_formats_int1, {
  char buffer[100];
  snek_object_t i = new_integer(5);
  format_object(i, buffer);

  assert_string_equal("int:5", buffer, "formats INTEGER");
});

munit_case(RUN, test_formats_string1, {
  char buffer[100];
  snek_object_t s = new_string("Hello!");
  format_object(s, buffer);

  assert_string_equal("string:Hello!", buffer, "formats STRING");
});

munit_case(SUBMIT, test_formats_int2, {
  char buffer[100];
  snek_object_t i = new_integer(2014);
  format_object(i, buffer);

  assert_string_equal("int:2014", buffer, "formats INTEGER");
});

munit_case(SUBMIT, test_formats_string2, {
  char buffer[100];
  snek_object_t s = new_string("nvim btw");
  format_object(s, buffer);

  assert_string_equal("string:nvim btw", buffer, "formats STRING");
});
*/


static MunitResult
test_formats_int1() {
  char buffer[100];
  snek_object_t i = new_integer(5);
  format_object(i, buffer);

  assert_string_equal("int:5", buffer);
  return MUNIT_OK;
}

static MunitResult
test_formats_string1() {
  char buffer[100];
  snek_object_t s = new_string("Hello!");
  format_object(s, buffer);

  assert_string_equal("string:Hello!", buffer);
  return MUNIT_OK;
}

static MunitResult
test_formats_int2() {
  char buffer[100];
  snek_object_t i = new_integer(2014);
  format_object(i, buffer);

  assert_string_equal("int:2014", buffer);
  return MUNIT_OK;
}

static MunitResult
test_formats_string2() {
  char buffer[100];
  snek_object_t s = new_string("nvim btw");
  format_object(s, buffer);

  assert_string_equal("string:nvim btw", buffer);
  return MUNIT_OK;
}

int main() {
  MunitTest tests[] = {
      {
          "/format_int-1",
          test_formats_int1,
          NULL,
          NULL,
          MUNIT_TEST_OPTION_NONE,
          NULL
      },
      {
          "/format_string-1",
          test_formats_string1,
          NULL,
          NULL,
          MUNIT_TEST_OPTION_NONE,
          NULL
      },
      {
          "/format_int-2",
          test_formats_int2,
          NULL,
          NULL,
          MUNIT_TEST_OPTION_NONE,
          NULL
      },
      {
          "/format_string-2",
          test_formats_string2,
          NULL,
          NULL,
          MUNIT_TEST_OPTION_NONE,
          NULL
      },
      { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
    };

    MunitSuite suite = {
        "/formats", /* name */
        tests, /* tests */
        NULL, /* suites */
        1, /* iterations */
        MUNIT_SUITE_OPTION_NONE /* options */
    };

  return munit_suite_main(&suite, NULL, 0, NULL);
}
