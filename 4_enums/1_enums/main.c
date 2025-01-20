/* I made a special test for running it locally and it worked */
#define MUNIT_ENABLE_ASSERT_ALIASES
#include "munit.h"

#include "color.h"

/*
static MunitResult
munit_case(RUN, test_color_enum1, {
  assert_int(RED, ==, 0, "RED is defined as 0");
  assert_int(GREEN, ==, 1, "GREEN is defined as 1");
  assert_int(BLUE, ==, 2, "BLUE is defined as 2");
});

static MunitResult
munit_case(SUBMIT, test_color_enum2, {
  assert_int(RED, !=, 4, "RED is not defined as 4");
  assert_int(GREEN, !=, 2, "GREEN is not defined as 2");
  assert_int(BLUE, !=, 0, "BLUE is not defined as 0");
});
*/

static MunitResult
color_enum1() {
  assert_int(RED, ==, 0);
  assert_int(GREEN, ==, 1);
  assert_int(BLUE, ==, 2);
  return MUNIT_OK;
}

static MunitResult
color_enum2() {
  assert_int(RED, !=, 4);
  assert_int(GREEN, !=, 2);
  assert_int(BLUE, !=, 0);
  return MUNIT_OK;
}

int main() {
  MunitTest tests[] = {
      {
          "/my_test",
          color_enum1,
          NULL,
          NULL,
          MUNIT_TEST_OPTION_NONE,
          NULL
      },
      {
          "/my_test",
          color_enum2,
          NULL,
          NULL,
          MUNIT_TEST_OPTION_NONE,
          NULL
      },
      { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
    };

    MunitSuite suite = {
        "/my-tests", /* name */
        tests, /* tests */
        NULL, /* suites */
        1, /* iterations */
        MUNIT_SUITE_OPTION_NONE /* options */
    };

  return munit_suite_main(&suite, NULL, 0, NULL);
}
