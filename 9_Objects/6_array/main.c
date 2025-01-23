#define MUNIT_ENABLE_ASSERT_ALIASES
#include <stdlib.h>

#include "munit.h"
#include "snekobject.h"

/*
munit_case(RUN, test_create_empty_array, {
  snek_object_t *obj = new_snek_array(2);

  assert_int(obj->kind, ==, ARRAY, "Must set type to ARRAY");
  assert_int(obj->data.v_array.size, ==, 2, "Must set size to 2");

  free(obj->data.v_array.elements);
  free(obj);
  assert(boot_all_freed());
});

munit_case(SUBMIT, test_used_calloc, {
  snek_object_t *obj = new_snek_array(2);

  assert_ptr_null(obj->data.v_array.elements[0], "Should use calloc");
  assert_ptr_null(obj->data.v_array.elements[1], "Should use calloc");

  free(obj->data.v_array.elements);
  free(obj);
  assert(boot_all_freed());
});
*/

static MunitResult
test_create_empty_array() {
  snek_object_t *obj = new_snek_array(2);

  // , "Must set type to ARRAY"
  assert_int(obj->kind, ==, ARRAY);
  // , "Must set size to 2"
  assert_int(obj->data.v_array.size, ==, 2);

  free(obj->data.v_array.elements);
  free(obj);
  // assert(boot_all_freed());
  return MUNIT_OK;
}

static MunitResult
test_used_calloc() {
  snek_object_t *obj = new_snek_array(2);

  // , "Should use calloc"
  munit_assert_ptr_null(obj->data.v_array.elements[0]);
  // , "Should use calloc"
  munit_assert_ptr_null(obj->data.v_array.elements[1]);

  free(obj->data.v_array.elements);
  free(obj);
  // assert(boot_all_freed());
  return MUNIT_OK;
}

int main() {
  MunitTest tests[] = {
      {
          "/test_create_empty_array",
          test_create_empty_array,
          NULL,
          NULL,
          MUNIT_TEST_OPTION_NONE,
          NULL
      },
      {
          "/test_used_calloc",
          test_used_calloc,
          NULL,
          NULL,
          MUNIT_TEST_OPTION_NONE,
          NULL
      },
      { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
    };

    MunitSuite suite = {
        "/snek_array_obj", /* name */
        tests, /* tests */
        NULL, /* suites */
        1, /* iterations */
        MUNIT_SUITE_OPTION_NONE /* options */
    };

  return munit_suite_main(&suite, NULL, 0, NULL);
}
