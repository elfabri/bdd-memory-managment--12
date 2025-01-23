#define MUNIT_ENABLE_ASSERT_ALIASES
#include "munit.h"
#include "snekobject.h"

/*
munit_case(RUN, test_positive, {
  snek_object_t *int_object = new_snek_integer(42);
  assert_int(int_object->data.v_int, ==, 42, "must allow positive numbers");

  free(int_object);
});

munit_case(RUN, test_zero, {
  snek_object_t *int_object = new_snek_integer(0);

  assert_int(int_object->kind, ==, INTEGER, "must be INTEGER type");
  assert_int(int_object->data.v_int, ==, 0, "must equal zero");

  free(int_object);
});

munit_case(SUBMIT, test_negative, {
  snek_object_t *int_object = new_snek_integer(-5);

  assert_int(int_object->kind, ==, INTEGER, "must be INTEGER type");
  assert_int(int_object->data.v_int, ==, -5, "must allow negative numbers");

  free(int_object);
});
*/

static MunitResult
test_positive() {
  snek_object_t *int_object = new_snek_integer(42);
  // , "must allow positive numbers"
  assert_int(int_object->data.v_int, ==, 42);

  free(int_object);
  return MUNIT_OK;
}

static MunitResult
test_zero() {
  snek_object_t *int_object = new_snek_integer(0);

  // , "must be INTEGER type"
  assert_int(int_object->kind, ==, INTEGER);
  // , "must equal zero"
  assert_int(int_object->data.v_int, ==, 0);

  free(int_object);
  return MUNIT_OK;
}

static MunitResult
test_negative() {
  snek_object_t *int_object = new_snek_integer(-5);

  // , "must be INTEGER type"
  assert_int(int_object->kind, ==, INTEGER);
  // , "must allow negative numbers"
  assert_int(int_object->data.v_int, ==, -5);

  free(int_object);
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
