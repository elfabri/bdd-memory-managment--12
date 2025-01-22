#include "munit.h"
#include "exercise.h"

/*
munit_case(RUN, test_allocate_scalar_list_size, {
  int size = 5;
  int multiplier = 2;
  int *result = allocate_scalar_list(size, multiplier);
  munit_assert_not_null(result, "Function should return a non-null pointer");
  free(result);
});

munit_case(RUN, test_allocate_scalar_list_values, {
  int size = 5;
  int multiplier = 2;
  int *result = allocate_scalar_list(size, multiplier);
  int expected[5];
  expected[0] = 0;
  expected[1] = 2;
  expected[2] = 4;
  expected[3] = 6;
  expected[4] = 8;
  for (int i = 0; i < size; i++) {
    munit_assert_int(result[i], ==, expected[i], "Element does not match expected value");
  }
  free(result);
});

munit_case(SUBMIT, test_allocate_scalar_list_zero_multiplier, {
  int size = 3;
  int multiplier = 0;
  int *result = allocate_scalar_list(size, multiplier);
  for (int i = 0; i < size; i++) {
    munit_assert_int(result[i], ==, 0, "All elements should be 0 with multiplier 0");
  }
  free(result);
});

munit_case(SUBMIT, test_allocate_too_much, {
  int size = 1024 * 1024 * 100;
  int multiplier = 1;
  int *result = allocate_scalar_list(size, multiplier);
  munit_assert_null(result, "Giant allocation should result in NULL");
});
*/

static MunitResult
test_allocate_scalar_list_size() {
  int size = 5;
  int multiplier = 2;
  int *result = allocate_scalar_list(size, multiplier);
  // Function should return a non-null pointer
  munit_assert_not_null(result);
  free(result);
  return MUNIT_OK;
}

static MunitResult
test_allocate_scalar_list_values() {
  int size = 5;
  int multiplier = 2;
  int *result = allocate_scalar_list(size, multiplier);
  int expected[5];
  expected[0] = 0;
  expected[1] = 2;
  expected[2] = 4;
  expected[3] = 6;
  expected[4] = 8;
  for (int i = 0; i < size; i++) {
    // Element does not match expected value
    munit_assert_int(result[i], ==, expected[i]);
  }
  free(result);
  return MUNIT_OK;
}

static MunitResult
test_allocate_scalar_list_zero_multiplier() {
  int size = 3;
  int multiplier = 0;
  int *result = allocate_scalar_list(size, multiplier);
  for (int i = 0; i < size; i++) {
    // All elements should be 0 with multiplier 0
    munit_assert_int(result[i], ==, 0);
  }
  free(result);
  return MUNIT_OK;
}

static MunitResult
test_allocate_too_much() {
  int size = 1024 * 1024 * 100;
  int multiplier = 1;
  int *result = allocate_scalar_list(size, multiplier);
  // Giant allocation should result in NULL
  munit_assert_null(result);
  return MUNIT_OK;
}

int main() {
  MunitTest tests[] = {
      {
          "/test_allocate_scalar_list_size",
          test_allocate_scalar_list_size,
          NULL,
          NULL,
          MUNIT_TEST_OPTION_NONE,
          NULL
      },
      {
          "/test_allocate_scalar_list_values",
          test_allocate_scalar_list_values,
          NULL,
          NULL,
          MUNIT_TEST_OPTION_NONE,
          NULL
      },
      {
          "/test_allocate_scalar_list_zero_multiplier",
          test_allocate_scalar_list_zero_multiplier,
          NULL,
          NULL,
          MUNIT_TEST_OPTION_NONE,
          NULL
      },
      {
          "/test_allocate_too_much",
          test_allocate_too_much,
          NULL,
          NULL,
          MUNIT_TEST_OPTION_NONE,
          NULL
      },
      { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
    };

    MunitSuite suite = {
        "/malloc", /* name */
        tests, /* tests */
        NULL, /* suites */
        1, /* iterations */
        MUNIT_SUITE_OPTION_NONE /* options */
    };

  return munit_suite_main(&suite, NULL, 0, NULL);
}
