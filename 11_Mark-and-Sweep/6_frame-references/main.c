#define MUNIT_ENABLE_ASSERT_ALIASES
#include <stdio.h>
#include <stdlib.h>

// #include "bootlib.h"
#include "munit.h"
#include "sneknew.h"
#include "vm.h"

/*
munit_case(RUN, test_one_ref, {
  vm_t *vm = vm_new();
  frame_t *frame = vm_new_frame(vm);

  snek_object_t *lanes_wpm = new_snek_integer(vm, 9);
  frame_reference_object(frame, lanes_wpm);

  assert_int(frame->references->count, ==, 1, "Only one reference");
  assert_ptr_equal(lanes_wpm, frame->references->data[0], "Refs lanes_wpm");

  vm_free(vm);
  assert(boot_all_freed());
});

munit_case(SUBMIT, test_multi_ref, {
  vm_t *vm = vm_new();
  frame_t *frame = vm_new_frame(vm);

  snek_object_t *lanes_wpm = new_snek_integer(vm, 9);
  snek_object_t *teej_wpm = new_snek_integer(vm, 160);
  frame_reference_object(frame, lanes_wpm);
  frame_reference_object(frame, teej_wpm);

  assert_int(frame->references->count, ==, 2, "Two references");
  assert_ptr_equal(lanes_wpm, frame->references->data[0], "Refs lanes_wpm");
  assert_ptr_equal(teej_wpm, frame->references->data[1], "Refs teej_wpm");

  vm_free(vm);
  assert(boot_all_freed());
});

int main() {
  MunitTest tests[] = {
    munit_test("/test_one_ref", test_one_ref),
    munit_test("/test_multi_ref", test_multi_ref),
    munit_null_test,
  };

  MunitSuite suite = munit_suite("mark-and-sweep", tests);

  return munit_suite_main(&suite, NULL, 0, NULL);
}
*/

static MunitResult
test_one_ref() {
  vm_t *vm = vm_new();
  frame_t *frame = vm_new_frame(vm);

  snek_object_t *lanes_wpm = new_snek_integer(vm, 9);
  frame_reference_object(frame, lanes_wpm);

  // , "Only one reference"
  assert_int(frame->references->count, ==, 1);
  // , "Refs lanes_wpm"
  assert_ptr_equal(lanes_wpm, frame->references->data[0]);

  vm_free(vm);
  // assert(boot_all_freed());
  return MUNIT_OK;
}

static MunitResult
test_multi_ref() {
  vm_t *vm = vm_new();
  frame_t *frame = vm_new_frame(vm);

  snek_object_t *lanes_wpm = new_snek_integer(vm, 9);
  snek_object_t *teej_wpm = new_snek_integer(vm, 160);
  frame_reference_object(frame, lanes_wpm);
  frame_reference_object(frame, teej_wpm);

  // , "Two references"
  assert_int(frame->references->count, ==, 2);
  // , "Refs lanes_wpm"
  assert_ptr_equal(lanes_wpm, frame->references->data[0]);
  // , "Refs teej_wpm"
  assert_ptr_equal(teej_wpm, frame->references->data[1]);

  vm_free(vm);
  // assert(boot_all_freed());
  return MUNIT_OK;
}

int main() {
  MunitTest tests[] = {
    {
      "/test_one_ref",
      test_one_ref,
      NULL,
      NULL,
      MUNIT_TEST_OPTION_NONE,
      NULL
    },
    {
      "/test_multi_ref",
      test_multi_ref,
      NULL,
      NULL,
      MUNIT_TEST_OPTION_NONE,
      NULL
    },
    {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}
  };

  MunitSuite suite = {
    "/vm_frame_ref", /* name */
    tests, /* tests */
    NULL, /* suites */
    1, /* iterations */
    MUNIT_SUITE_OPTION_NONE /* options */
  };

  return munit_suite_main(&suite, NULL, 0, NULL);
}

