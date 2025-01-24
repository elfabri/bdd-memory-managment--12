#define MUNIT_ENABLE_ASSERT_ALIASES
#include <stdio.h>
#include <stdlib.h>

// #include "bootlib.h"
#include "munit.h"
#include "vm.h"
/*
munit_case(RUN, test_vm_new, {
  vm_t *vm = vm_new();
  assert_int(vm->frames->capacity, ==, 8, "frames should have capacity 8");
  assert_int(vm->objects->capacity, ==, 8, "objects should have capacity 8");
  vm_free(vm);
});

munit_case(SUBMIT, test_vm_new_free, {
  vm_t *vm = vm_new();
  vm_free(vm);
  assert(boot_all_freed());
});

int main() {
  MunitTest tests[] = {
    munit_test("/vm", test_vm_new),
    munit_test("/vm", test_vm_new_free),
    munit_null_test,
  };

  MunitSuite suite = munit_suite("mark-and-sweep", tests);

  return munit_suite_main(&suite, NULL, 0, NULL);
}
*/

static MunitResult
test_vm_new() {
  vm_t *vm = vm_new();
  // , "frames should have capacity 8"
  assert_int(vm->frames->capacity, ==, 8);
  // , "objects should have capacity 8"
  assert_int(vm->objects->capacity, ==, 8);
  vm_free(vm);
  return MUNIT_OK;
}

static MunitResult
test_vm_new_free() {
  vm_t *vm = vm_new();
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
      "/test_vm_new_free",
      test_vm_new_free,
      NULL,
      NULL,
      MUNIT_TEST_OPTION_NONE,
      NULL
    },
  };

  MunitSuite suite = {
    "/virtual_machine_new", /* name */
    tests, /* tests */
    NULL, /* suites */
    1, /* iterations */
    MUNIT_SUITE_OPTION_NONE /* options */
  };

  return munit_suite_main(&suite, NULL, 0, NULL);
}

