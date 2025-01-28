#define MUNIT_ENABLE_ASSERT_ALIASES
#include <stdio.h>
#include <stdlib.h>

// #include "bootlib.h"
#include "munit.h"
#include "sneknew.h"
#include "vm.h"

/*
munit_case(RUN, test_field_exists, {
  vm_t *vm = vm_new();
  snek_object_t *lane_courses = new_snek_integer(vm, 20);
  snek_object_t *teej_courses = new_snek_integer(vm, 1);
  lane_courses->is_marked;
  teej_courses->is_marked;
  vm_free(vm);
  assert(boot_all_freed());
});

munit_case(SUBMIT, test_marked_is_false, {
  vm_t *vm = vm_new();
  snek_object_t *lane_courses = new_snek_integer(vm, 20);
  snek_object_t *teej_courses = new_snek_integer(vm, 1);
  assert_false(lane_courses->is_marked);
  assert_false(teej_courses->is_marked);
  vm_free(vm);
  assert(boot_all_freed());
});

int main() {
  MunitTest tests[] = {
    munit_test("/test_field_exists", test_field_exists),
    munit_test("/test_marked_is_false", test_marked_is_false),
    munit_null_test,
  };

  MunitSuite suite = munit_suite("mark-and-sweep", tests);

  return munit_suite_main(&suite, NULL, 0, NULL);
}
*/

static MunitResult
test_field_exists() {
  vm_t *vm = vm_new();
  snek_object_t *lane_courses = new_snek_integer(vm, 20);
  snek_object_t *teej_courses = new_snek_integer(vm, 1);
  lane_courses->is_marked;
  teej_courses->is_marked;
  vm_free(vm);
  // assert(boot_all_freed());
  return MUNIT_OK;
}

static MunitResult
test_marked_is_false() {
  vm_t *vm = vm_new();
  snek_object_t *lane_courses = new_snek_integer(vm, 20);
  snek_object_t *teej_courses = new_snek_integer(vm, 1);
  assert_false(lane_courses->is_marked);
  assert_false(teej_courses->is_marked);
  vm_free(vm);
  // assert(boot_all_freed());
  return MUNIT_OK;
}

int main() {
  MunitTest tests[] = {
    {
      "/test_field_exists",
      test_field_exists,
      NULL,
      NULL,
      MUNIT_TEST_OPTION_NONE,
      NULL
    },
    {
      "/test_marked_is_false",
      test_marked_is_false,
      NULL,
      NULL,
      MUNIT_TEST_OPTION_NONE,
      NULL
    },
    {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}
  };

  MunitSuite suite = {
    "/mark-and-seep", /* name */
    tests, /* tests */
    NULL, /* suites */
    1, /* iterations */
    MUNIT_SUITE_OPTION_NONE /* options */
  };

  return munit_suite_main(&suite, NULL, 0, NULL);
}

