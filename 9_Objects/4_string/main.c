#define MUNIT_ENABLE_ASSERT_ALIASES
#include <stdlib.h>

#include "munit.h"
#include "snekobject.h"

/*
munit_case(RUN, test_str_copied, {
  char *input = "Hello, World!";
  snek_object_t *obj = new_snek_string(input);

  assert_int(obj->kind, ==, STRING, "Must be a string!");

  // Should not have pointers be the same, otherwise we didn't copy the value.
  assert_ptr_not_equal(
      obj->data.v_string, input, "You need to copy the string."
  );

  // But should have the same data!
  //  This way the object can free it's own memory later.
  assert_string_equal(
      obj->data.v_string, input, "Should copy string correctly"
  );

  // Should allocate memory for the string with null terminator.
  assert_int_equal(boot_alloc_size(), 22, "Must allocate memory for string");

  // Free the string, and then free the object.
  free(obj->data.v_string);
  free(obj);
  assert(boot_all_freed());
});
*/

static MunitResult
test_str_copied() {
  char *input = "Hello, World!";
  snek_object_t *obj = new_snek_string(input);

  // , "Must be a string!"
  assert_int(obj->kind, ==, STRING);

  // Should not have pointers be the same, otherwise we didn't copy the value.
  // , "You need to copy the string."
  assert_ptr_not_equal( obj->data.v_string, input);

  // But should have the same data!
  //  This way the object can free it's own memory later.
  //  , "Should copy string correctly"
  assert_string_equal( obj->data.v_string, input);

  // Should allocate memory for the string with null terminator.
  // , "Must allocate memory for string"
  // assert_int_equal(boot_alloc_size(), 22);

  // Free the string, and then free the object.
  free(obj->data.v_string);
  free(obj);
  // assert(boot_all_freed());
  return MUNIT_OK;
}

int main() {
  MunitTest tests[] = {
      {
          "/test_str_copied",
          test_str_copied,
          NULL,
          NULL,
          MUNIT_TEST_OPTION_NONE,
          NULL
      },
      { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
    };

    MunitSuite suite = {
        "/snek_str_obj", /* name */
        tests, /* tests */
        NULL, /* suites */
        1, /* iterations */
        MUNIT_SUITE_OPTION_NONE /* options */
    };

  return munit_suite_main(&suite, NULL, 0, NULL);
}
