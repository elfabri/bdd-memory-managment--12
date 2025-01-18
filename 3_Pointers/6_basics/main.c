#include "munit.h"
#include "exercise.h"

munit_case(RUN, test_change_filetype_cpp_to_python, {
  codefile_t original;
  original.lines = 100;
  original.filetype = 1;
  codefile_t result = change_filetype(&original, 2);
  munit_assert_int(result.filetype, ==, 2, "Filetype should change from 1 to 2");
  munit_assert_int(result.lines, ==, 100, "Number of lines should remain unchanged");
});

munit_case(RUN, test_change_filetype_same_type, {
  codefile_t original;
  original.lines = 50;
  original.filetype = 3;
  codefile_t result = change_filetype(&original, 3);
  munit_assert_int(result.filetype, ==, 3, "Filetype should remain 3");
  munit_assert_int(result.lines, ==, 50, "Number of lines should remain unchanged");
});

munit_case(SUBMIT, test_change_filetype_java_to_rust, {
  codefile_t original;
  original.lines = 200;
  original.filetype = 4;
  codefile_t result = change_filetype(&original, 5);
  munit_assert_int(result.filetype, ==, 5, "Filetype should change from 4 to 5");
  munit_assert_int(result.lines, ==, 200, "Number of lines should remain unchanged");
});

munit_case(SUBMIT, test_change_filetype_zero_lines, {
  codefile_t original;
  original.lines = 0;
  original.filetype = 1;
  codefile_t result = change_filetype(&original, 6);
  munit_assert_int(result.filetype, ==, 6, "Filetype should change from 1 to 6");
  munit_assert_int(result.lines, ==, 0, "Number of lines should remain 0");
});

munit_case(RUN, test_change_filetype_no_mutation, {
  codefile_t original;
  original.lines = 150;
  original.filetype = 7;
  codefile_t backup = original;
  codefile_t result = change_filetype(&original, 8);
  munit_assert_int(result.filetype, ==, 8, "Filetype should change to 8");
  munit_assert_int(original.filetype, ==, backup.filetype, "Original filetype should remain unchanged");
  munit_assert_int(original.lines, ==, backup.lines, "Original number of lines should remain unchanged");
});

int main() {
  MunitTest tests[] = {
      munit_test("/test_change_filetype_cpp_to_python", test_change_filetype_cpp_to_python),
      munit_test("/test_change_filetype_same_type", test_change_filetype_same_type),
      munit_test("/test_change_filetype_java_to_rust", test_change_filetype_java_to_rust),
      munit_test("/test_change_filetype_zero_lines", test_change_filetype_zero_lines),
      munit_test("/test_change_filetype_no_mutation", test_change_filetype_no_mutation),
      munit_null_test,
  };

  MunitSuite suite = munit_suite("change_filetype", tests);

  return munit_suite_main(&suite, NULL, 0, NULL);
}
