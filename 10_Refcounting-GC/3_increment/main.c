#define MUNIT_ENABLE_ASSERT_ALIASES
#include <stdio.h>
#include <stdlib.h>

// #include "bootlib.h"
#include "munit.h"
#include "snekobject.h"

/*
munit_case(RUN, test_inc_refcount, {
  snek_object_t *obj = new_snek_integer(10);
  assert_int(obj->refcount, ==, 1, "Refcount should be 1 on creation");

  refcount_inc(obj);
  assert_int(obj->refcount, ==, 2, "Refcount should be incremented");

  free(obj);
});

munit_case(SUBMIT, test_inc_refcount_more, {
  snek_object_t *obj = new_snek_float(4.20);
  assert_int(obj->refcount, ==, 1, "Refcount should be 1 on creation");

  refcount_inc(obj);
  refcount_inc(obj);
  refcount_inc(obj);
  refcount_inc(obj);
  refcount_inc(obj);
  assert_int(obj->refcount, ==, 6, "Refcount should be incremented to 6");

  free(obj);
});

munit_case(SUBMIT, test_null_obj, {
  refcount_inc(NULL);
  assert(1);
});

int main() {
  MunitTest tests[] = {
    munit_test("/test_inc_refcount", test_inc_refcount),
    munit_test("/test_inc_refcount_more", test_inc_refcount_more),
    munit_test("/test_null_obj", test_null_obj),
    munit_null_test,
  };

  MunitSuite suite = munit_suite("refcount", tests);

  return munit_suite_main(&suite, NULL, 0, NULL);
}
*/

static MunitResult
test_inc_refcount() {
  snek_object_t *obj = new_snek_integer(10);
  // , "Refcount should be 1 on creation"
  assert_int(obj->refcount, ==, 1);

  refcount_inc(obj);
  // , "Refcount should be incremented"
  assert_int(obj->refcount, ==, 2);

  free(obj);
  return MUNIT_OK;
}

static MunitResult
test_inc_refcount_more() {
  snek_object_t *obj = new_snek_float(4.20);
  // , "Refcount should be 1 on creation"
  assert_int(obj->refcount, ==, 1);

  refcount_inc(obj);
  refcount_inc(obj);
  refcount_inc(obj);
  refcount_inc(obj);
  refcount_inc(obj);
  // , "Refcount should be incremented to 6"
  assert_int(obj->refcount, ==, 6);

  free(obj);
  return MUNIT_OK;
}


static MunitResult
test_null_obj() {
  refcount_inc(NULL);
  assert(1);
  return MUNIT_OK;
}

int main() {
  MunitTest tests[] = {
      {
          "/test_inc_refcount",
          test_inc_refcount,
          NULL,
          NULL,
          MUNIT_TEST_OPTION_NONE,
          NULL
      },
      {
          "/test_inc_refcount_more",
          test_inc_refcount_more,
          NULL,
          NULL,
          MUNIT_TEST_OPTION_NONE,
          NULL
      },
      {
          "/test_null_obj",
          test_null_obj,
          NULL,
          NULL,
          MUNIT_TEST_OPTION_NONE,
          NULL
      },
      { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
    };

    MunitSuite suite = {
        "/increment_refcount", /* name */
        tests, /* tests */
        NULL, /* suites */
        1, /* iterations */
        MUNIT_SUITE_OPTION_NONE /* options */
    };

  return munit_suite_main(&suite, NULL, 0, NULL);
}

