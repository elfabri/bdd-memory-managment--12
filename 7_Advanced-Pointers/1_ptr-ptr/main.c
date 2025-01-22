#define MUNIT_ENABLE_ASSERT_ALIASES
#include <stdlib.h>

#include "exercise.h"
#include "munit.h"

/*
munit_case(RUN, test_allocate, {
  int *pointer = NULL;
  allocate_int(&pointer, 10);

  assert_ptr_not_null(pointer, "Should allocate pointer");
  assert_int(*pointer, ==, 10, "Should assign value to pointer");

  free(pointer);
});

munit_case(SUBMIT, test_does_not_overwrite, {
  int value = 5;
  int *pointer = &value;

  allocate_int(&pointer, 20);

  assert_int(value, ==, 5, "Should not overwrite original value");

  assert_ptr_not_null(pointer, "Should allocate pointer");
  assert_int(*pointer, ==, 20, "Should assign value to pointer");

  free(pointer);
});
*/

static MunitResult
test_allocate() {
  int *pointer = NULL;
  allocate_int(&pointer, 10);

  // Should allocate pointer
  assert_ptr_not_null(pointer);
  // Should assign value to pointer
  assert_int(*pointer, ==, 10);

  free(pointer);
  return MUNIT_OK;
}

static MunitResult
test_does_not_overwrite() {
  int value = 5;
  int *pointer = &value;

  allocate_int(&pointer, 20);

  // Should not overwrite original value
  assert_int(value, ==, 5);

  // Should allocate pointer
  assert_ptr_not_null(pointer);
  // Should assign value to pointer
  assert_int(*pointer, ==, 20);

  free(pointer);
  return MUNIT_OK;
}

int main() {
  MunitTest tests[] = {
      {
          "/test_allocate",
          test_allocate,
          NULL,
          NULL,
          MUNIT_TEST_OPTION_NONE,
          NULL
      },
      {
          "/test_does_not_overwrite",
          test_does_not_overwrite,
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
