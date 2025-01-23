#define MUNIT_ENABLE_ASSERT_ALIASES
#include <stdlib.h>

#include "munit.h"
#include "snekobject.h"

/*
munit_case(RUN, test_integer_constant, {
  assert_int(INTEGER, ==, 0, "INTEGER is defined as 0");
});

munit_case(RUN, test_integer_obj, {
  snek_object_t *obj = malloc(sizeof(snek_object_t));
  obj->kind = INTEGER;
  obj->data.v_int = 0;
  assert_int(obj->kind, ==, INTEGER, "must be INTEGER type");
  assert_int(obj->data.v_int, ==, 0, "must equal zero");

  free(obj);
});
*/

static MunitResult
test_integer_constant() {
  // , "INTEGER is defined as 0"
  assert_int(INTEGER, ==, 0);
  return MUNIT_OK;
}

static MunitResult
test_integer_obj() {
  snek_object_t *obj = malloc(sizeof(snek_object_t));
  obj->kind = INTEGER;
  obj->data.v_int = 0;
  // , "must be INTEGER type"
  assert_int(obj->kind, ==, INTEGER);
  // , "must equal zero"
  assert_int(obj->data.v_int, ==, 0);

  free(obj);
  return MUNIT_OK;
}

int main() {
  MunitTest tests[] = {
      {
          "/test_integer_constant",
          test_integer_constant,
          NULL,
          NULL,
          MUNIT_TEST_OPTION_NONE,
          NULL
      },
      {
          "/test_integer_obj",
          test_integer_obj,
          NULL,
          NULL,
          MUNIT_TEST_OPTION_NONE,
          NULL
      },
      { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
    };

    MunitSuite suite = {
        "/snek_objects", /* name */
        tests, /* tests */
        NULL, /* suites */
        1, /* iterations */
        MUNIT_SUITE_OPTION_NONE /* options */
    };

  return munit_suite_main(&suite, NULL, 0, NULL);
}
