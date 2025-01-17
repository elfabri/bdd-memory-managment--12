#include "munit.h"

#include "exercise.h"

munit_case(RUN, test_optimal_size, {
  assert_int(
      sizeof(sneklang_var_t), ==, 16, "Should be 16 (in online playground)"
  );
});

int main() {
  MunitTest tests[] = {
      munit_test("/test_optimal_size", test_optimal_size),
      munit_null_test,
  };

  MunitSuite suite = munit_suite("padding", tests);

  return munit_suite_main(&suite, NULL, 0, NULL);
}
