#define MUNIT_ENABLE_ASSERT_ALIASES
// #include "bootlib.h"
#include "munit.h"
#include "snekstack.h"

/*
munit_case(RUN, pop_stack, {
  stack_t *s = stack_new(2);
  assert_ptr_not_null(s, "Must allocate a new stack");

  assert_int(s->capacity, ==, 2, "Sets capacity to 2");
  assert_int(s->count, ==, 0, "No elements in the stack yet");
  assert_ptr_not_null(s->data, "Allocates the stack data");

  int one = 1;
  int two = 2;
  int three = 3;

  stack_push(s, &one);
  stack_push(s, &two);

  assert_int(s->capacity, ==, 2, "Sets capacity to 2");
  assert_int(s->count, ==, 2, "2 elements in the stack");

  stack_push(s, &three);
  assert_int(s->capacity, ==, 4, "Capcity is doubled");
  assert_int(s->count, ==, 3, "3 elements in the stack");

  int *popped = stack_pop(s);
  assert_int(*popped, ==, three, "Should pop the last element");

  popped = stack_pop(s);
  assert_int(*popped, ==, two, "Should pop the last element");

  popped = stack_pop(s);
  assert_int(*popped, ==, one, "Should pop the only remaining element");

  popped = stack_pop(s);
  assert_null(popped, "No remaining elements");

  stack_free(s);
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

  stack_push(s, &a);
  assert_int(s->capacity, ==, 4, "Capcity is doubled");
  assert_int(s->count, ==, 3, "3 elements in the stack");

  stack_free(s);
  assert(boot_all_freed());
});

munit_case(RUN, create_stack, {
  stack_t *s = stack_new(10);
  assert_int(s->capacity, ==, 10, "Sets capacity to 10");
  assert_int(s->count, ==, 0, "No elements in the stack yet");
  assert_ptr_not_null(s->data, "Allocates the stack data");

  stack_free(s);
  assert(boot_all_freed());
});
*/

static MunitResult
pop_stack() {
  stack_t *s = stack_new(2);
  // , "Must allocate a new stack"
  assert_ptr_not_null(s);

  // , "Sets capacity to 2"
  assert_int(s->capacity, ==, 2);
  // , "No elements in the stack yet"
  assert_int(s->count, ==, 0);
  // , "Allocates the stack data"
  assert_ptr_not_null(s->data);

  int one = 1;
  int two = 2;
  int three = 3;

  stack_push(s, &one);
  stack_push(s, &two);

  // , "Sets capacity to 2"
  assert_int(s->capacity, ==, 2);
  // , "2 elements in the stack"
  assert_int(s->count, ==, 2);

  stack_push(s, &three);
  // , "Capcity is doubled"
  assert_int(s->capacity, ==, 4);
  // , "3 elements in the stack"
  assert_int(s->count, ==, 3);

  int *popped = stack_pop(s);
  // , "Should pop the last element"
  assert_int(*popped, ==, three);

  popped = stack_pop(s);
  // , "Should pop the last element"
  assert_int(*popped, ==, two);

  popped = stack_pop(s);
  // , "Should pop the only remaining element"
  assert_int(*popped, ==, one);

  popped = stack_pop(s);
  // , "No remaining elements"
  assert_null(popped);

  stack_free(s);
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

  stack_push(s, &a);
  // , "Capcity is doubled"
  assert_int(s->capacity, ==, 4);
  // , "3 elements in the stack"
  assert_int(s->count, ==, 3);

  stack_free(s);
  // assert(boot_all_freed());
  return MUNIT_OK;
}

static MunitResult
create_stack() {
  stack_t *s = stack_new(10);
  // , "Sets capacity to 10"
  assert_int(s->capacity, ==, 10);
  // , "No elements in the stack yet"
  assert_int(s->count, ==, 0);
  // , "Allocates the stack data"
  assert_ptr_not_null(s->data);

  stack_free(s);
  // assert(boot_all_freed());
  return MUNIT_OK;
}

int main() {
  MunitTest tests[] = {
      {
          "/pop_stack",
          pop_stack,
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
          "/create_stack",
          create_stack,
          NULL,
          NULL,
          MUNIT_TEST_OPTION_NONE,
          NULL
      },
      { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
    };

    MunitSuite suite = {
        "/free_stack", /* name */
        tests, /* tests */
        NULL, /* suites */
        1, /* iterations */
        MUNIT_SUITE_OPTION_NONE /* options */
    };

  return munit_suite_main(&suite, NULL, 0, NULL);
}
