/* Run the code in its current state. Notice that
 * the assertions fail. Even though we decremented
 * both the first and second arrays' refcounts,
 * neither were freed (refcount = 0).
 *
 * Fix the assertions to pass by updating them to match
 * the sad reality of our current implementation.
 */
#define MUNIT_ENABLE_ASSERT_ALIASES
#include <stdio.h>
#include <stdlib.h>

// #include "bootlib.h"
#include "munit.h"
#include "snekobject.h"

/*
munit_case(RUN, correctly_free, {
  snek_object_t *first = new_snek_array(1);
  snek_object_t *second = new_snek_array(1);
  // refcounts: first = 1, second = 1
  snek_array_set(first, 0, second);
  // refcounts: first = 1, second = 2
  snek_array_set(second, 0, first);
  // refcounts: first = 2, second = 2
  refcount_dec(first);
  refcount_dec(second);
  assert_int(first->refcount, ==, 0, "Refcount first should be ?");
  assert_int(second->refcount, ==, 0, "Refcount second should be ?");
});

int main() {
  MunitTest tests[] = {
    munit_test("/correctly_free", correctly_free),
    munit_null_test,
  };

  MunitSuite suite = munit_suite("refcount", tests);

  return munit_suite_main(&suite, NULL, 0, NULL);
}
*/

static MunitResult
correctly_free() {
  snek_object_t *first = new_snek_array(1);
  snek_object_t *second = new_snek_array(1);
  // refcounts: first = 1, second = 1
  snek_array_set(first, 0, second);
  // refcounts: first = 1, second = 2
  snek_array_set(second, 0, first);
  // refcounts: first = 2, second = 2
  refcount_dec(first);
  refcount_dec(second);
  // , "Refcount first should be ?"
  assert_int(first->refcount, ==, 1);
  // , "Refcount second should be ?"
  assert_int(second->refcount, ==, 1);
  return MUNIT_OK;
}

int main() {
  MunitTest tests[] = {
    {
      "/correctly_free",
      correctly_free,
      NULL,
      NULL,
      MUNIT_TEST_OPTION_NONE,
      NULL
    },
    {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}
  };

  MunitSuite suite = {
    "/correctly-free", /* name */
    tests, /* tests */
    NULL, /* suites */
    1, /* iterations */
    MUNIT_SUITE_OPTION_NONE /* options */
  };

  return munit_suite_main(&suite, NULL, 0, NULL);
}

