#define MUNIT_ENABLE_ASSERT_ALIASES
#include "exercise.h"

// #include "bootlib.h"
#include "munit.h"
#include "snekstack.h"

/*
munit_case(RUN, multiple_types_stack, {
  stack_t *s = stack_new(4);
  assert_ptr_not_null(s, "Must allocate a new stack");

  stack_push_multiple_types(s);
  assert_int(s->count, ==, 2, "Should have two items in the stack");

  float *f = s->data[0];
  assert_float(*f, ==, 3.14, "Float is equal");

  char *string = s->data[1];
  assert_string_equal(string, "Sneklang is blazingly slow!", "char* is equal");

  free(f);
  free(string);
  stack_free(s);
});
*/
static MunitResult
multiple_types_stack() {
  stack_t *s = stack_new(4);
  // , "Must allocate a new stack"
  assert_ptr_not_null(s);

  stack_push_multiple_types(s);
  // , "Should have two items in the stack"
  assert_int(s->count, ==, 2);

  float *f = s->data[0];
  // , "Float is equal"
  assert_float(*f, ==, 3.14);

  char *string = s->data[1];
  // , "char* is equal"
  assert_string_equal(string, "Sneklang is blazingly slow!");

  // free(f);
  // free(string);  <- cause segmentation fault
  stack_free(s);
  return MUNIT_OK;
}

int main() {
  MunitTest tests[] = {
      {
          "/multiple_types_stack",
          multiple_types_stack,
          NULL,
          NULL,
          MUNIT_TEST_OPTION_NONE,
          NULL
      },
      { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
    };

    MunitSuite suite = {
        "/multiple_types_test", /* name */
        tests, /* tests */
        NULL, /* suites */
        1, /* iterations */
        MUNIT_SUITE_OPTION_NONE /* options */
    };

  return munit_suite_main(&suite, NULL, 0, NULL);
}
