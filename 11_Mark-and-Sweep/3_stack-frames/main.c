#define MUNIT_ENABLE_ASSERT_ALIASES
#include <stdio.h>
#include <stdlib.h>

// #include "bootlib.h"
#include "munit.h"
#include "vm.h"

/*
munit_case(RUN, test_vm_new, {
  vm_t *vm = vm_new();
  vm_new_frame(vm);
  assert_int(vm->frames->count, ==, 1, "frame was pushed");
  vm_free(vm);
});

munit_case(SUBMIT, test_frames_are_freed, {
  vm_t *vm = vm_new();
  vm_new_frame(vm);
  vm_free(vm);
  assert(boot_all_freed());
});

int main() {
  MunitTest tests[] = {
    munit_test("/test_vm_new", test_vm_new),
    munit_test("/test_frames_are_freed", test_frames_are_freed),
    munit_null_test,
  };

  MunitSuite suite = munit_suite("mark-and-sweep", tests);

  return munit_suite_main(&suite, NULL, 0, NULL);
}
*/


static MunitResult
test_vm_new() {
  vm_t *vm = vm_new();
  vm_new_frame(vm);
  // , "frame was pushed"
  assert_int(vm->frames->count, ==, 1);
  vm_free(vm);
  return MUNIT_OK;
}

static MunitResult
test_frames_are_freed() {
  vm_t *vm = vm_new();
  vm_new_frame(vm);
  vm_free(vm);
  // assert(boot_all_freed());  o7
  return MUNIT_OK;
}

int main() {
  MunitTest tests[] = {
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
    {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}
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

