#define MUNIT_ENABLE_ASSERT_ALIASES
#include <stdio.h>
#include <stdlib.h>

// #include "bootlib.h"
#include "munit.h"
#include "sneknew.h"
#include "snekobject.h"
#include "vm.h"

/*
munit_case(RUN, test_new_object, {
  vm_t *vm = vm_new();
  snek_object_t *obj = new_snek_integer(vm, 5);
  assert_int(obj->kind, ==, INTEGER, "kind must be INTEGER");
  assert_ptr_equal(vm->objects->data[0], obj, "object must be tracked");
  free(obj);
  vm_free(vm);
  assert(boot_all_freed());
});

munit_case(RUN, test_vm_new, {
  vm_t *vm = vm_new();
  assert_ptr_not_null(vm->frames, "frames must not be NULL");
  assert_ptr_not_null(vm->objects, "objects must not be NULL");
  vm_free(vm);
  assert(boot_all_freed());
});

munit_case(RUN, test_frames_are_freed, {
  vm_t *vm = vm_new();
  vm_new_frame(vm);
  vm_free(vm);
  assert(boot_all_freed());
});

int main() {
  MunitTest tests[] = {
    munit_test("/test_vm_new", test_vm_new),
    munit_test("/test_frames_are_freed", test_frames_are_freed),
    munit_test("/test_new_object", test_new_object),
    munit_null_test,
  };

  MunitSuite suite = munit_suite("mark-and-sweep", tests);

  return munit_suite_main(&suite, NULL, 0, NULL);
}
*/

static MunitResult
test_new_object() {
  vm_t *vm = vm_new();
  snek_object_t *obj = new_snek_integer(vm, 5);
  // , "kind must be INTEGER"
  assert_int(obj->kind, ==, INTEGER);
  // , "object must be tracked"
  assert_ptr_equal(vm->objects->data[0], obj);
  free(obj);
  vm_free(vm);
  // assert(boot_all_freed());
  return MUNIT_OK;
}

static MunitResult
test_vm_new() {
  vm_t *vm = vm_new();
  // , "frames must not be NULL"
  assert_ptr_not_null(vm->frames);
  // , "objects must not be NULL"
  assert_ptr_not_null(vm->objects);
  vm_free(vm);
  // assert(boot_all_freed());
  return MUNIT_OK;
}

static MunitResult
test_frames_are_freed() {
  vm_t *vm = vm_new();
  vm_new_frame(vm);
  vm_free(vm);
  // assert(boot_all_freed());
  return MUNIT_OK;
}

int main() {
  MunitTest tests[] = {
    {
      "/test_new_object",
      test_new_object,
      NULL,
      NULL,
      MUNIT_TEST_OPTION_NONE,
      NULL
    },
    {
      "/test_vm_new",
      test_vm_new,
      NULL,
      NULL,
      MUNIT_TEST_OPTION_NONE,
      NULL
    },
    {
      "/test_frames_are_freed",
      test_frames_are_freed,
      NULL,
      NULL,
      MUNIT_TEST_OPTION_NONE,
      NULL
    },
  };

  MunitSuite suite = {
    "/vm_stack-frames", /* name */
    tests, /* tests */
    NULL, /* suites */
    1, /* iterations */
    MUNIT_SUITE_OPTION_NONE /* options */
  };

  return munit_suite_main(&suite, NULL, 0, NULL);
}

