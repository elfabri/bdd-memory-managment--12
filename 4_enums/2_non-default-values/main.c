/* local test different than the one on the web */
#define MUNIT_ENABLE_ASSERT_ALIASES
#include "munit.h"

#include "color.h"

/*
munit_case(RUN, test_colors_defined, {
  assert_int(RED, ==, 55, "RED is defined as 55 (nvim green!)");
  assert_int(GREEN, ==, 176, "GREEN is defined as 176 (nvim green!)");
  assert_int(BLUE, ==, 38, "BLUE is defined as 38 (nvim green!)");
});

munit_case(SUBMIT, test_colors_defined_correctly, {
  assert_int(RED, !=, 0, "RED is not defined as 0 (vsc*de blue!)");
  assert_int(GREEN, !=, 120, "GREEN is not defined as 120 (vsc*de blue!)");
  assert_int(BLUE, !=, 215, "BLUE is not defined as 215 (vsc*de blue!)");
});
*/


static MunitResult
test_colors_defined() {
  assert_int(RED, ==, 55);
  assert_int(GREEN, ==, 176);
  assert_int(BLUE, ==, 38);
  return MUNIT_OK;
}

static MunitResult
test_colors_defined_correctly() {
  assert_int(RED, !=, 0);
  assert_int(GREEN, !=, 120);
  assert_int(BLUE, !=, 215);
  return MUNIT_OK;
}

int main() {
  MunitTest tests[] = {
      {
          "/colors1",
          test_colors_defined,
          NULL,
          NULL,
          MUNIT_TEST_OPTION_NONE,
          NULL
      },
      {
          "/colors2",
          test_colors_defined_correctly,
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
