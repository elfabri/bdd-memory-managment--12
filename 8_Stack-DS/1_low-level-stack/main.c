// #include "bootlib.h"
#include "munit.h"
#include "snekstack.h"

/*
munit_case(RUN, create_stack_small, {
  stack_t *s = stack_new(3);
  assert_int(s->capacity, ==, 3, "Sets capacity to 3");
  assert_int(s->count, ==, 0, "No elements in the stack yet");
  assert_ptr_not_null(s->data, "Allocates the stack data");

  free(s->data);
  free(s);

  assert(boot_all_freed());
});

munit_case(SUBMIT, create_stack_large, {
  stack_t *s = stack_new(100);
  assert_int(s->capacity, ==, 100, "Sets capacity to 100");
  assert_int(s->count, ==, 0, "No elements in the stack yet");
  assert_ptr_not_null(s->data, "Allocates the stack data");

  free(s->data);
  free(s);

  assert(boot_all_freed());
});
*/

static MunitResult
create_stack_small() {
  stack_t *s = stack_new(3);
  // , "Sets capacity to 3"
  munit_assert_int(s->capacity, ==, 3);
  // , "No elements in the stack yet"
  munit_assert_int(s->count, ==, 0);
  // , "Allocates the stack data"
  munit_assert_ptr_not_null(s->data);

  free(s->data);
  free(s);

  // assert(boot_all_freed());
  return MUNIT_OK;
}

static MunitResult
create_stack_large() {
  stack_t *s = stack_new(100);
  // , "Sets capacity to 100"
  munit_assert_int(s->capacity, ==, 100);
  // , "No elements in the stack yet"
  munit_assert_int(s->count, ==, 0);
  // , "Allocates the stack data"
  munit_assert_ptr_not_null(s->data);

  free(s->data);
  free(s);

  // assert(boot_all_freed());
  return MUNIT_OK;
}

int main() {
  MunitTest tests[] = {
      {
          "/create_stack_small",
          create_stack_small,
          NULL,
          NULL,
          MUNIT_TEST_OPTION_NONE,
          NULL
      },
      {
          "/create_stack_large",
          create_stack_large,
          NULL,
          NULL,
          MUNIT_TEST_OPTION_NONE,
          NULL
      },
      { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
    };

    MunitSuite suite = {
        "/stack", /* name */
        tests, /* tests */
        NULL, /* suites */
        1, /* iterations */
        MUNIT_SUITE_OPTION_NONE /* options */
    };

  return munit_suite_main(&suite, NULL, 0, NULL);
}
