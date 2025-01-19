/* worked first try on the web */
#include "munit.h"
#include "exercise.h"
#include <string.h>

munit_case(RUN, test_concat_empty_strings, {
  char str1[100] = "";
  const char *str2 = "";
  concat_strings(str1, str2);
  munit_assert_string_equal(str1, "", "Concatenating two empty strings should result in an empty string");
});

munit_case(RUN, test_concat_empty_to_nonempty, {
  char str1[100] = "Hello";
  const char *str2 = "";
  concat_strings(str1, str2);
  munit_assert_string_equal(str1, "Hello", "Concatenating an empty string to a non-empty string should not change the original string");
});

munit_case(RUN, test_concat_small_strings, {
  char str1[100] = "Hello ";
  const char *str2 = "World";
  concat_strings(str1, str2);
  munit_assert_string_equal(str1, "Hello World", "Concatenating strings should work correctly");
});

munit_case(SUBMIT, test_concat_long_strings, {
  char str1[200] = "This is a longer string that ";
  const char *str2 = "will be concatenated with another long string.";
  concat_strings(str1, str2);
  munit_assert_string_equal(str1, "This is a longer string that will be concatenated with another long string.", "Concatenating longer strings should work correctly");
});

munit_case(SUBMIT, test_concat_nonempty_to_empty, {
  char str1[100] = "";
  const char *str2 = "Hello";
  concat_strings(str1, str2);
  munit_assert_string_equal(str1, "Hello", "Concatenating a string to an empty should change the original string");
});


int main() {
  MunitTest tests[] = {
    munit_test("/test_concat_empty_strings", test_concat_empty_strings),
    munit_test("/test_concat_empty_to_nonempty", test_concat_empty_to_nonempty),
    munit_test("/test_concat_small_strings", test_concat_small_strings),
    munit_test("/test_concat_long_strings", test_concat_long_strings),
    munit_test("/test_concat_nonempty_to_empty", test_concat_nonempty_to_empty),
    munit_null_test,
  };

  MunitSuite suite = munit_suite("concat_strings", tests);

  return munit_suite_main(&suite, NULL, 0, NULL);
}
