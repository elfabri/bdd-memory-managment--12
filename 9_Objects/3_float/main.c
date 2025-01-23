#define MUNIT_ENABLE_ASSERT_ALIASES
#include <stdlib.h>

#include "munit.h"
#include "snekobject.h"

/*
munit_case(RUN, test_positive, {
  snek_object_t *obj = new_snek_float(42);
  assert_float(obj->data.v_float, ==, 42, "Must accept positive values");

  free(obj);
  assert(boot_all_freed());
});

munit_case(SUBMIT, test_zero, {
  snek_object_t *obj = new_snek_float(0.0);

  assert_float(obj->kind, ==, FLOAT, "Must set type to FLOAT");
  assert_float(obj->data.v_float, ==, 0.0, "Must accept 0.0");

  free(obj);
  assert(boot_all_freed());
});

munit_case(SUBMIT, test_negative, {
  snek_object_t *obj = new_snek_float(-5.0);

  assert_float(obj->kind, ==, FLOAT, "Must set type to FLOAT");
  assert_float(obj->data.v_float, ==, -5.0, "Must accept negative numbers");

  free(obj);
  assert(boot_all_freed());
});
*/

static MunitResult
test_positive() {
  snek_object_t *obj = new_snek_float(42);
  // , "Must accept positive values"
  assert_float(obj->data.v_float, ==, 42);

  free(obj);
  // assert(boot_all_freed());
  return MUNIT_OK;
}

static MunitResult
test_zero() {
  snek_object_t *obj = new_snek_float(0.0);

  // , "Must set type to FLOAT"
  assert_float(obj->kind, ==, FLOAT);
  // , "Must accept 0.0"
  assert_float(obj->data.v_float, ==, 0.0);

  free(obj);
  // assert(boot_all_freed());
  return MUNIT_OK;
}

static MunitResult
test_negative() {
  snek_object_t *obj = new_snek_float(-5.0);

  // , "Must set type to FLOAT"
  assert_float(obj->kind, ==, FLOAT);
  // , "Must accept negative numbers"
  assert_float(obj->data.v_float, ==, -5.0);

  free(obj);
  // assert(boot_all_freed());
  return MUNIT_OK;
}

int main() {
  MunitTest tests[] = {
      {
          "/test_positive",
          test_positive,
          NULL,
          NULL,
          MUNIT_TEST_OPTION_NONE,
          NULL
      },
      {
          "/test_zero",
          test_zero,
          NULL,
          NULL,
          MUNIT_TEST_OPTION_NONE,
          NULL
      },
      {
          "/test_negative",
          test_negative,
          NULL,
          NULL,
          MUNIT_TEST_OPTION_NONE,
          NULL
      },
      { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
    };

    MunitSuite suite = {
        "/snek_int_objects", /* name */
        tests, /* tests */
        NULL, /* suites */
        1, /* iterations */
        MUNIT_SUITE_OPTION_NONE /* options */
    };

  return munit_suite_main(&suite, NULL, 0, NULL);
}
