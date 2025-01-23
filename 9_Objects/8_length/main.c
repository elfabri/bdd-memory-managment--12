#define MUNIT_ENABLE_ASSERT_ALIASES
#include "munit.h"
#include "snekobject.h"

/*
munit_case(RUN, test_integer, {
  snek_object_t *obj = new_snek_integer(42);
  assert_int(snek_length(obj), ==, 1, "Integers are length 1");
  free(obj);
  assert(boot_all_freed());
});

munit_case(RUN, test_float, {
  snek_object_t *obj = new_snek_float(3.14);
  assert_int(snek_length(obj), ==, 1, "Floats are length 1");
  free(obj);
  assert(boot_all_freed());
});

munit_case(RUN, test_string, {
  snek_object_t *shorter = new_snek_string("hello");
  assert_int(snek_length(shorter), ==, 5, "Should return based on input");
  snek_object_t *longer = new_snek_string("hello, world");
  assert_int(
      snek_length(longer), ==, strlen("hello, world"), "Should use strlen"
  );
  free(shorter->data.v_string);
  free(shorter);
  free(longer->data.v_string);
  free(longer);
  assert(boot_all_freed());
});

munit_case(SUBMIT, test_vector3, {
  snek_object_t *i = new_snek_integer(1);
  snek_object_t *vec = new_snek_vector3(i, i, i);
  assert_int(snek_length(vec), ==, 3, "Vec3 always has length 3");
  free(i);
  free(vec);
  assert(boot_all_freed());
});

munit_case(SUBMIT, test_array, {
  snek_object_t *i = new_snek_integer(1);
  snek_object_t *arr = new_snek_array(4);
  assert(snek_array_set(arr, 0, i));
  assert(snek_array_set(arr, 1, i));
  assert(snek_array_set(arr, 2, i));
  assert_int(snek_length(arr), ==, 4, "Length of array should be its size");
  free(i);
  free(arr->data.v_array.elements);
  free(arr);
  assert(boot_all_freed());
});
*/

static MunitResult
test_integer() {
  snek_object_t *obj = new_snek_integer(42);
  // , "Integers are length 1"
  assert_int(snek_length(obj), ==, 1);
  free(obj);
  // assert(boot_all_freed());
  return MUNIT_OK;
}

static MunitResult
test_float() {
  snek_object_t *obj = new_snek_float(3.14);
  // , "Floats are length 1"
  assert_int(snek_length(obj), ==, 1);
  free(obj);
  // assert(boot_all_freed());
  return MUNIT_OK;
}

static MunitResult
test_string() {
  snek_object_t *shorter = new_snek_string("hello");
  // , "Should return based on input"
  assert_int(snek_length(shorter), ==, 5);
  snek_object_t *longer = new_snek_string("hello, world");
  // , "Should use strlen"
  assert_int( snek_length(longer), ==, strlen("hello, world"));
  free(shorter->data.v_string);
  free(shorter);
  free(longer->data.v_string);
  free(longer);
  // assert(boot_all_freed());
  return MUNIT_OK;
}

static MunitResult
test_vector3() {
  snek_object_t *i = new_snek_integer(1);
  snek_object_t *vec = new_snek_vector3(i, i, i);
  // , "Vec3 always has length 3"
  assert_int(snek_length(vec), ==, 3);
  free(i);
  free(vec);
  // assert(boot_all_freed());
  return MUNIT_OK;
}

static MunitResult
test_array() {
  snek_object_t *i = new_snek_integer(1);
  snek_object_t *arr = new_snek_array(4);
  assert(snek_array_set(arr, 0, i));
  assert(snek_array_set(arr, 1, i));
  assert(snek_array_set(arr, 2, i));
  // , "Length of array should be its size"
  assert_int(snek_length(arr), ==, 4);
  free(i);
  free(arr->data.v_array.elements);
  free(arr);
  // assert(boot_all_freed());
  return MUNIT_OK;
}

int main() {
  MunitTest tests[] = {
      {
          "/test_integer",
          test_integer,
          NULL,
          NULL,
          MUNIT_TEST_OPTION_NONE,
          NULL
      },
      {
          "/test_float",
          test_float,
          NULL,
          NULL,
          MUNIT_TEST_OPTION_NONE,
          NULL
      },
      {
          "/test_string",
          test_string,
          NULL,
          NULL,
          MUNIT_TEST_OPTION_NONE,
          NULL
      },
      {
          "/test_vector3",
          test_vector3,
          NULL,
          NULL,
          MUNIT_TEST_OPTION_NONE,
          NULL
      },
      {
          "/test_array",
          test_array,
          NULL,
          NULL,
          MUNIT_TEST_OPTION_NONE,
          NULL
      },
      { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
    };

    MunitSuite suite = {
        "/snek_obj_length", /* name */
        tests, /* tests */
        NULL, /* suites */
        1, /* iterations */
        MUNIT_SUITE_OPTION_NONE /* options */
    };

  return munit_suite_main(&suite, NULL, 0, NULL);
}

