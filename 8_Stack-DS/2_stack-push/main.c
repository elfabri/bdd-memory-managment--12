#define MUNIT_ENABLE_ASSERT_ALIASES
// #include "bootlib.h"
#include "munit.h"
#include "snekstack.h"

/*
munit_case(RUN, create_stack, {
  stack_t *s = stack_new(10);
  assert_int(s->capacity, ==, 10, "Sets capacity to 10");
  assert_int(s->count, ==, 0, "No elements in the stack yet");
  assert_ptr_not_null(s->data, "Allocates the stack data");

  // Clean up our allocated data.
  free(s->data);
  free(s);

  // Should be nothing left that is allocated.
  assert(boot_all_freed());
});

munit_case(RUN, push_stack, {
  stack_t *s = stack_new(2);
  assert_ptr_not_null(s, "Must allocate a new stack");

  assert_int(s->capacity, ==, 2, "Sets capacity to 2");
  assert_int(s->count, ==, 0, "No elements in the stack yet");
  assert_ptr_not_null(s->data, "Allocates the stack data");

  int a = 1;

  stack_push(s, &a);
  stack_push(s, &a);

  assert_int(s->capacity, ==, 2, "Sets capacity to 2");
  assert_int(s->count, ==, 2, "2 elements in the stack");
  assert_ptr_equal(s->data[0], &a, "element inserted into stack");

  // Clean up our allocated data.
  free(s->data);
  free(s);

  // Should be nothing left that is allocated.
  assert(boot_all_freed());
});

munit_case(SUBMIT, push_double_capcity, {
  stack_t *s = stack_new(2);
  assert_ptr_not_null(s, "Must allocate a new stack");

  assert_int(s->capacity, ==, 2, "Sets capacity to 2");
  assert_int(s->count, ==, 0, "No elements in the stack yet");
  assert_ptr_not_null(s->data, "Allocates the stack data");

  int a = 1;

  stack_push(s, &a);
  stack_push(s, &a);

  assert_int(s->capacity, ==, 2, "Sets capacity to 2");
  assert_int(s->count, ==, 2, "2 elements in the stack");

  stack_push(s, &a);
  assert_int(s->capacity, ==, 4, "Capcity is doubled");
  assert_int(s->count, ==, 3, "3 elements in the stack");

  // Should reallocate memory.
  assert_int_equal(boot_realloc_count(), 1, "Must reallocate memory for stack");

  // Clean up our allocated data.
  free(s->data);
  free(s);

  // Should be nothing left that is allocated.
  assert(boot_all_freed());
});
*/

static MunitResult
create_stack() {
  stack_t *s = stack_new(10);
  // , "Sets capacity to 10"
  assert_int(s->capacity, ==, 10);
  // , "No elements in the stack yet"
  assert_int(s->count, ==, 0);
  // , "Allocates the stack data"
  assert_ptr_not_null(s->data);

  // Clean up our allocated data.
  free(s->data);
  free(s);

  // Should be nothing left that is allocated.
  // assert(boot_all_freed());
  return MUNIT_OK;
}

static MunitResult
push_stack() {
  stack_t *s = stack_new(2);
  // , "Must allocate a new stack"
  assert_ptr_not_null(s);

  // , "Sets capacity to 2"
  assert_int(s->capacity, ==, 2);
  // , "No elements in the stack yet"
  assert_int(s->count, ==, 0);
  // , "Allocates the stack data"
  assert_ptr_not_null(s->data);

  int a = 1;

  stack_push(s, &a);
  stack_push(s, &a);

  // , "Sets capacity to 2"
  assert_int(s->capacity, ==, 2);
  // , "2 elements in the stack"
  assert_int(s->count, ==, 2);
  // , "element inserted into stack"
  assert_ptr_equal(s->data[0], &a);

  // Clean up our allocated data.
  free(s->data);
  free(s);

  // Should be nothing left that is allocated.
  // assert(boot_all_freed());
  return MUNIT_OK;
}

static MunitResult
push_double_capcity() {
  stack_t *s = stack_new(2);
  // , "Must allocate a new stack"
  assert_ptr_not_null(s);

  // , "Sets capacity to 2"
  assert_int(s->capacity, ==, 2);
  // , "No elements in the stack yet"
  assert_int(s->count, ==, 0);
  // , "Allocates the stack data"
  assert_ptr_not_null(s->data);

  int a = 1;

  stack_push(s, &a);
  stack_push(s, &a);

  // , "Sets capacity to 2"
  assert_int(s->capacity, ==, 2);
  // , "2 elements in the stack"
  assert_int(s->count, ==, 2);

  stack_push(s, &a);
  // , "Capcity is doubled"
  assert_int(s->capacity, ==, 4);
  // , "3 elements in the stack"
  assert_int(s->count, ==, 3);

  // Should reallocate memory.
  // , "Must reallocate memory for stack"
  // assert_int_equal(boot_realloc_count(), 1);

  // Clean up our allocated data.
  free(s->data);
  free(s);

  // Should be nothing left that is allocated.
  // assert(boot_all_freed());
  return MUNIT_OK;
}

int main() {
  MunitTest tests[] = {
      {
          "/create_stack",
          create_stack,
          NULL,
          NULL,
          MUNIT_TEST_OPTION_NONE,
          NULL
      },
      {
          "/push_stack",
          push_stack,
          NULL,
          NULL,
          MUNIT_TEST_OPTION_NONE,
          NULL
      },
      {
          "/push_double_capcity",
          push_double_capcity,
          NULL,
          NULL,
          MUNIT_TEST_OPTION_NONE,
          NULL
      },
      { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
    };

    MunitSuite suite = {
        "/stack_push", /* name */
        tests, /* tests */
        NULL, /* suites */
        1, /* iterations */
        MUNIT_SUITE_OPTION_NONE /* options */
    };

  return munit_suite_main(&suite, NULL, 0, NULL);
}
