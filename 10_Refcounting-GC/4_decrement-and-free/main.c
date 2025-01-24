#define MUNIT_ENABLE_ASSERT_ALIASES
#include <stdio.h>
#include <stdlib.h>

// #include "bootlib.h"
#include "munit.h"
#include "snekobject.h"

/*
munit_case(RUN, test_int_has_refcount, {
  snek_object_t *obj = new_snek_integer(10);
  assert_int(obj->refcount, ==, 1, "Refcount should be 1 on creation");

  free(obj);
});

munit_case(RUN, test_inc_refcount, {
  snek_object_t *obj = new_snek_float(4.20);
  assert_int(obj->refcount, ==, 1, "Refcount should be 1 on creation");

  refcount_inc(obj);
  assert_int(obj->refcount, ==, 2, "Refcount should be incremented");

  free(obj);
});

munit_case(RUN, test_dec_refcount, {
  snek_object_t *obj = new_snek_float(4.20);

  refcount_inc(obj);
  assert_int(obj->refcount, ==, 2, "Refcount should be incremented");

  refcount_dec(obj);
  assert_int(obj->refcount, ==, 1, "Refcount should be decremented");

  assert(!boot_is_freed(obj));

  // Object is still alive, so we will free manually.
  free(obj);
});

munit_case(SUBMIT, test_refcount_free_is_called, {
  snek_object_t *obj = new_snek_float(4.20);

  refcount_inc(obj);
  assert_int(obj->refcount, ==, 2, "Refcount should be incremented");

  refcount_dec(obj);
  assert_int(obj->refcount, ==, 1, "Refcount should be decremented");

  refcount_dec(obj);
  assert(boot_is_freed(obj));
  assert(boot_all_freed());
});

munit_case(SUBMIT, test_allocated_string_is_freed, {
  snek_object_t *obj = new_snek_string("Hello @wagslane!");

  refcount_inc(obj);
  assert_int(obj->refcount, ==, 2, "Refcount should be incremented");

  refcount_dec(obj);
  assert_int(obj->refcount, ==, 1, "Refcount should be decremented");
  assert_string_equal(obj->data.v_string, "Hello @wagslane!", "references str");

  refcount_dec(obj);
  assert(boot_is_freed(obj));
  assert(boot_all_freed());
});

int main() {
  MunitTest tests[] = {
    munit_test("/has_refcount", test_int_has_refcount),
    munit_test("/inc_refcount", test_inc_refcount),
    munit_test("/dec_refcount", test_dec_refcount),
    munit_test("/free_refcount", test_refcount_free_is_called),
    munit_test("/string_freed", test_allocated_string_is_freed),
    munit_null_test,
  };

  MunitSuite suite = munit_suite("refcount", tests);

  return munit_suite_main(&suite, NULL, 0, NULL);
}
*/

static MunitResult
test_int_has_refcount() {
  snek_object_t *obj = new_snek_integer(10);
  // , "Refcount should be 1 on creation"
  assert_int(obj->refcount, ==, 1);

  free(obj);
  return MUNIT_OK;
}

static MunitResult
test_inc_refcount() {
  snek_object_t *obj = new_snek_float(4.20);
  // , "Refcount should be 1 on creation"
  assert_int(obj->refcount, ==, 1);

  refcount_inc(obj);
  // , "Refcount should be incremented"
  assert_int(obj->refcount, ==, 2);

  free(obj);
  return MUNIT_OK;
}

static MunitResult
test_dec_refcount() {
  snek_object_t *obj = new_snek_float(4.20);

  refcount_inc(obj);
  // , "Refcount should be incremented"
  assert_int(obj->refcount, ==, 2);

  refcount_dec(obj);
  // , "Refcount should be decremented"
  assert_int(obj->refcount, ==, 1);

  // assert(!boot_is_freed(obj));

  // Object is still alive, so we will free manually.
  free(obj);
  return MUNIT_OK;
}

static MunitResult
test_refcount_free_is_called() {
  snek_object_t *obj = new_snek_float(4.20);

  refcount_inc(obj);
  // , "Refcount should be incremented"
  assert_int(obj->refcount, ==, 2);

  refcount_dec(obj);
  // , "Refcount should be decremented"
  assert_int(obj->refcount, ==, 1);

  refcount_dec(obj);
  // assert(boot_is_freed(obj));
  // assert(boot_all_freed());
  return MUNIT_OK;
}

static MunitResult
test_allocated_string_is_freed() {
  snek_object_t *obj = new_snek_string("Hello @wagslane!");

  refcount_inc(obj);
  // , "Refcount should be incremented"
  assert_int(obj->refcount, ==, 2);

  refcount_dec(obj);
  // , "Refcount should be decremented"
  assert_int(obj->refcount, ==, 1);
  // , "references str"
  assert_string_equal(obj->data.v_string, "Hello @wagslane!");

  refcount_dec(obj);
  // assert(boot_is_freed(obj));
  // assert(boot_all_freed());  I don't have that lib!!!!!
  return MUNIT_OK;
}

int main() {
  MunitTest tests[] = {
    {
      "/test_int_has_refcount",
      test_int_has_refcount,
      NULL,
      NULL,
      MUNIT_TEST_OPTION_NONE,
      NULL
    },
    {
      "/test_inc_refcount",
      test_inc_refcount,
      NULL,
      NULL,
      MUNIT_TEST_OPTION_NONE,
      NULL
    },
    {
      "/test_dec_refcount",
      test_dec_refcount,
      NULL,
      NULL,
      MUNIT_TEST_OPTION_NONE,
      NULL
    },
    {
      "/test_refcount_free_is_called",
      test_refcount_free_is_called,
      NULL,
      NULL,
      MUNIT_TEST_OPTION_NONE,
      NULL
    },
    {
      "/test_allocated_string_is_freed",
      test_allocated_string_is_freed,
      NULL,
      NULL,
      MUNIT_TEST_OPTION_NONE,
      NULL
    },
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
  };

  MunitSuite suite = {
    "/dec_und_free", /* name */
    tests, /* tests */
    NULL, /* suites */
    1, /* iterations */
    MUNIT_SUITE_OPTION_NONE /* options */
  };

  return munit_suite_main(&suite, NULL, 0, NULL);
}

