#define MUNIT_ENABLE_ASSERT_ALIASES
#include <stdio.h>
#include <stdlib.h>

// #include "bootlib.h"
#include "munit.h"
#include "sneknew.h"
#include "vm.h"

/*
munit_case(RUN, test_reference_object, {
  vm_t *vm = vm_new();
  new_snek_integer(vm, 5);
  new_snek_string(vm, "hello");
  vm_free(vm);
  assert(boot_all_freed());
});

munit_case(SUBMIT, test_frames_are_freed, {
  vm_t *vm = vm_new();
  vm_new_frame(vm);
  vm_new_frame(vm);
  vm_free(vm);
  assert(boot_all_freed());
});

int main() {
  MunitTest tests[] = {
    munit_test("/test_reference_object", test_reference_object),
    munit_test("/test_frames_are_freed", test_frames_are_freed),
    munit_null_test,
  };

  MunitSuite suite = munit_suite("mark-and-sweep", tests);

  return munit_suite_main(&suite, NULL, 0, NULL);
}
*/

static MunitResult
test_reference_object() {
  vm_t *vm = vm_new();
  new_snek_integer(vm, 5);
  new_snek_string(vm, "hello");
  vm_free(vm);
  // assert_null(vm);
  // assert(boot_all_freed());
  return MUNIT_OK;
}

static MunitResult
test_frames_are_freed() {
  vm_t *vm = vm_new();
  vm_new_frame(vm);
  vm_new_frame(vm);
  vm_free(vm);
  // assert(boot_all_freed());
  // assert_null(vm);
  return MUNIT_OK;
}

int main() {
  MunitTest tests[] = {
    {
      "/test_reference_object",
      test_reference_object,
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
    "/vm_free", /* name */
    tests, /* tests */
    NULL, /* suites */
    1, /* iterations */
    MUNIT_SUITE_OPTION_NONE /* options */
  };

  return munit_suite_main(&suite, NULL, 0, NULL);
}

