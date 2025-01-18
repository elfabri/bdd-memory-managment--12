#include "munit.h"

#include "snek.h"

munit_case(RUN, size_of_addr_16, {
  unsigned long size = size_of_addr(16);
  munit_assert_ulong(size, ==, 4, "size must be 4");
});

munit_case(RUN, size_of_addr_32, {
  unsigned long size = size_of_addr(32);
  munit_assert_ulong(size, ==, 4, "size must be 4");
});

munit_case(SUBMIT, size_of_addr_64, {
  unsigned long size = size_of_addr(64);
  munit_assert_ulong(size, ==, 4, "size must be 4");
});

munit_case(SUBMIT, size_of_addr_128, {
  unsigned long size = size_of_addr(128);
  munit_assert_ulong(size, ==, 4, "size must be 4");
});

int main() {
  MunitTest tests[] = {
      munit_test("/size_of_addr_16", size_of_addr_16),
      munit_test("/size_of_addr_32", size_of_addr_32),
      munit_test("/size_of_addr_64", size_of_addr_64),
      munit_test("/size_of_addr_128", size_of_addr_128),

      munit_null_test,
  };

  MunitSuite suite = munit_suite("colors", tests);

  return munit_suite_main(&suite, NULL, 0, NULL);
}
