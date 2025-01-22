#include "munit.h"
#include "exercise.h"
#include <stdlib.h>
#include <string.h>

/*
munit_case(RUN, test_create_token_pointer_array_single,
{
  token_t token = {"hello", 1, 1};
  token_t** result = create_token_pointer_array(&token, 1);

  munit_assert_not_null(result, "Result array should not be null");
  munit_assert_not_null(result[0], "First token pointer should not be null");
  munit_assert_string_equal(result[0]->literal, "hello", "Literal should match");
  munit_assert_int(result[0]->line, ==, 1, "Line number should match");
  munit_assert_int(result[0]->column, ==, 1, "Column number should match");
  munit_assert_ptr_not_equal(result[0], &token, "Token pointer should not point to original token");

  free(result[0]);
  free(result);
})

munit_case(RUN, test_create_token_pointer_array_multiple,
{
  token_t tokens[3] = {
    {"foo", 1, 1},
    {"bar", 2, 5},
    {"baz", 3, 10}
  };
  token_t** result = create_token_pointer_array(tokens, 3);

  munit_assert_not_null(result, "Result array should not be null");
  for (int i = 0; i < 3; i++) {
    munit_assert_not_null(result[i], "Token pointer should not be null");
    munit_assert_string_equal(result[i]->literal, tokens[i].literal, "Literal should match");
    munit_assert_int(result[i]->line, ==, tokens[i].line, "Line number should match");
    munit_assert_int(result[i]->column, ==, tokens[i].column, "Column number should match");
    munit_assert_ptr_not_equal(result[i], &tokens[i], "Token pointer should not point to original token");
  }

  for (int i = 0; i < 3; i++) {
    free(result[i]);
  }
  free(result);
})

munit_case(SUBMIT, test_create_token_pointer_array_memory_allocation,
{
  token_t tokens[2] = {
    {"test1", 1, 1},
    {"test2", 2, 2}
  };
  token_t** result = create_token_pointer_array(tokens, 2);

  munit_assert_not_null(result, "Result array should not be null");
  munit_assert_not_null(result[0], "First token pointer should not be null");
  munit_assert_not_null(result[1], "Second token pointer should not be null");
  munit_assert_ptr_not_equal(result[0], result[1], "Token pointers should be different");
  munit_assert_ptr_not_equal(result[0], &tokens[0], "First token pointer should not point to original token");
  munit_assert_ptr_not_equal(result[1], &tokens[1], "Second token pointer should not point to original token");

  free(result[0]);
  free(result[1]);
  free(result);
})
*/

static MunitResult
test_create_token_pointer_array_single() {
  token_t token = {"hello", 1, 1};
  token_t** result = create_token_pointer_array(&token, 1);

  // , "Result array should not be null"
  munit_assert_not_null(result);
  // , "First token pointer should not be null"
  munit_assert_not_null(result[0]);
  // , "Literal should match"
  munit_assert_string_equal(result[0]->literal, "hello");
  // , "Line number should match"
  munit_assert_int(result[0]->line, ==, 1);
  // , "Column number should match"
  munit_assert_int(result[0]->column, ==, 1);
  // , "Token pointer should not point to original token"
  munit_assert_ptr_not_equal(result[0], &token);

  free(result[0]);
  free(result);
  return MUNIT_OK;
}

static MunitResult
test_create_token_pointer_array_multiple() {
  token_t tokens[3] = {
    {"foo", 1, 1},
    {"bar", 2, 5},
    {"baz", 3, 10}
  };
  token_t** result = create_token_pointer_array(tokens, 3);

  // , "Result array should not be null"
  munit_assert_not_null(result);
  for (int i = 0; i < 3; i++) {
    // , "Token pointer should not be null"
    munit_assert_not_null(result[i]);
    // , "Literal should match"
    munit_assert_string_equal(result[i]->literal, tokens[i].literal);
    // , "Line number should match"
    munit_assert_int(result[i]->line, ==, tokens[i].line);
    // , "Column number should match"
    munit_assert_int(result[i]->column, ==, tokens[i].column);
    // , "Token pointer should not point to original token"
    munit_assert_ptr_not_equal(result[i], &tokens[i]);
  }

  for (int i = 0; i < 3; i++) {
    free(result[i]);
  }
  free(result);
  return MUNIT_OK;
}

static MunitResult
test_create_token_pointer_array_memory_allocation() {
  token_t tokens[2] = {
    {"test1", 1, 1},
    {"test2", 2, 2}
  };
  token_t** result = create_token_pointer_array(tokens, 2);

  // , "Result array should not be null"
  munit_assert_not_null(result);
  // , "First token pointer should not be null"
  munit_assert_not_null(result[0]);
  // , "Second token pointer should not be null"
  munit_assert_not_null(result[1]);
  // , "Token pointers should be different"
  munit_assert_ptr_not_equal(result[0], result[1]);
  // , "First token pointer should not point to original token"
  munit_assert_ptr_not_equal(result[0], &tokens[0]);
  // , "Second token pointer should not point to original token"
  munit_assert_ptr_not_equal(result[1], &tokens[1]);

  free(result[0]);
  free(result[1]);
  free(result);
  return MUNIT_OK;
}

int main() {
  MunitTest tests[] = {
      {
          "/test_create_token_pointer_array_single",
          test_create_token_pointer_array_single,
          NULL,
          NULL,
          MUNIT_TEST_OPTION_NONE,
          NULL
      },
      {
          "/test_create_token_pointer_array_multiple",
          test_create_token_pointer_array_multiple,
          NULL,
          NULL,
          MUNIT_TEST_OPTION_NONE,
          NULL
      },
      {
          "/test_create_token_pointer_array_memory_allocation",
          test_create_token_pointer_array_memory_allocation,
          NULL,
          NULL,
          MUNIT_TEST_OPTION_NONE,
          NULL
      },
      { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
    };

    MunitSuite suite = {
        "/array_pointers", /* name */
        tests, /* tests */
        NULL, /* suites */
        1, /* iterations */
        MUNIT_SUITE_OPTION_NONE /* options */
    };

  return munit_suite_main(&suite, NULL, 0, NULL);
}
