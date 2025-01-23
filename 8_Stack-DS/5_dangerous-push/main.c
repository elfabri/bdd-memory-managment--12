#define MUNIT_ENABLE_ASSERT_ALIASES
#include "exercise.h"

// #include "bootlib.h"
#include "munit.h"
#include "snekstack.h"

/*
munit_case(RUN, heterogenous_stack, {
  stack_t *s = stack_new(2);
  assert_ptr_not_null(s, "Must allocate a new stack");

  scary_double_push(s);
  assert_int(s->count, ==, 2, "Should have two items in the stack");

  int value = (int)s->data[0];
  assert_int(value, ==, 1337, "Zero item should be 1337");

  int *pointer = s->data[1];
  assert_int(*pointer, ==, 1024, "Top item should be 1024");

  free(pointer);
  stack_free(s);
});
*/

static MunitResult
heterogenous_stack() {
  stack_t *s = stack_new(2);
  // , "Must allocate a new stack"
  assert_ptr_not_null(s);

  scary_double_push(s);
  // , "Should have two items in the stack"
  assert_int(s->count, ==, 2);

  int value = (int)s->data[0];
  // , "Zero item should be 1337"
  assert_int(value, ==, 1337);

  int *pointer = s->data[1];
  // , "Top item should be 1024"
  assert_int(*pointer, ==, 1024);

  free(pointer);
  stack_free(s);
  return MUNIT_OK;
}

int main() {
  MunitTest tests[] = {
      {
          "/heterogenous_stack",
          heterogenous_stack,
          NULL,
          NULL,
          MUNIT_TEST_OPTION_NONE,
          NULL
      },
      { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
    };

    MunitSuite suite = {
        "/dangerous_push", /* name */
        tests, /* tests */
        NULL, /* suites */
        1, /* iterations */
        MUNIT_SUITE_OPTION_NONE /* options */
    };

  return munit_suite_main(&suite, NULL, 0, NULL);
}
