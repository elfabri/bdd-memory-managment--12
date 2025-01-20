#define MUNIT_ENABLE_ASSERT_ALIASES
#include "munit.h"

#include "http.h"

/*
munit_case(RUN, test_switch_enum, {
  assert_string_equal(http_to_str(HTTP_BAD_REQUEST), "400 Bad Request", "");
  assert_string_equal(http_to_str(HTTP_UNAUTHORIZED), "401 Unauthorized", "");
  assert_string_equal(http_to_str(HTTP_NOT_FOUND), "404 Not Found", "");
  assert_string_equal(http_to_str(HTTP_TEAPOT), "418 I AM A TEAPOT!", "");
  assert_string_equal(http_to_str(HTTP_INTERNAL_SERVER_ERROR), "500 Internal Server Error", "");
});

munit_case(SUBMIT, test_switch_enum_default, {
  assert_string_equal(http_to_str((HttpErrorCode)999), "Unknown HTTP status code", "");
});
*/

static MunitResult
test_switch_enum() {
  assert_string_equal(http_to_str(HTTP_BAD_REQUEST), "400 Bad Request");
  assert_string_equal(http_to_str(HTTP_UNAUTHORIZED), "401 Unauthorized");
  assert_string_equal(http_to_str(HTTP_NOT_FOUND), "404 Not Found");
  assert_string_equal(http_to_str(HTTP_TEAPOT), "418 I AM A TEAPOT!");
  assert_string_equal(http_to_str(HTTP_INTERNAL_SERVER_ERROR), "500 Internal Server Error");
  return MUNIT_OK;
}

static MunitResult
test_switch_enum_default() {
  assert_string_equal(http_to_str((HttpErrorCode)999), "Unknown HTTP status code");
  return MUNIT_OK;
}

int main() {
  MunitTest tests[] = {
      {
          "/test_enum",
          test_switch_enum,
          NULL,
          NULL,
          MUNIT_TEST_OPTION_NONE,
          NULL
      },
      {
          "/test_enum2",
          test_switch_enum_default,
          NULL,
          NULL,
          MUNIT_TEST_OPTION_NONE,
          NULL
      },
      { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
    };

    MunitSuite suite = {
        "/test_enums", /* name */
        tests, /* tests */
        NULL, /* suites */
        1, /* iterations */
        MUNIT_SUITE_OPTION_NONE /* options */
    };

  return munit_suite_main(&suite, NULL, 0, NULL);
}
