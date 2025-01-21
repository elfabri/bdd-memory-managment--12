#include "munit.h"
#include "exercise.h"
#include <string.h>

/*
munit_case(RUN, test_packet_header_size, {
  munit_assert_size(sizeof(packet_header_t), ==, 8, "PacketHeader union should be 8 bytes");
});

munit_case(RUN, test_tcp_header_fields, {
  packet_header_t header;
  header.tcp_header.src_port = 0x1234;
  header.tcp_header.dest_port = 0x5678;
  header.tcp_header.seq_num = 0x9ABCDEF0;

  munit_assert_uint16(header.tcp_header.src_port, ==, 0x1234, "src_port should be 0x1234");
  munit_assert_uint16(header.tcp_header.dest_port, ==, 0x5678, "dest_port should be 0x5678");
  munit_assert_uint32(header.tcp_header.seq_num, ==, 0x9ABCDEF0, "seq_num should be 0x9ABCDEF0");
});

munit_case(SUBMIT, test_field_raw_size, {
  munit_assert_size(sizeof(((packet_header_t *)0)->raw), ==, 8, "PacketHeader union should be 8 bytes");
});

munit_case(SUBMIT, test_field_to_raw_consistency, {
  packet_header_t header = {0};
  header.tcp_header.src_port = 0x1234;
  header.tcp_header.dest_port = 0x5678;
  header.tcp_header.seq_num = 0x9ABCDEF0;

  munit_assert_uint8(header.raw[0], ==, 0x34, "[0] should be 0x34");
  munit_assert_uint8(header.raw[1], ==, 0x12, "[1] should be 0x12");
  munit_assert_uint8(header.raw[2], ==, 0x78, "[2] should be 0x78");
  munit_assert_uint8(header.raw[3], ==, 0x56, "[3] should be 0x56");
  munit_assert_uint8(header.raw[4], ==, 0xF0, "[4] should be 0xF0");
  munit_assert_uint8(header.raw[5], ==, 0xDE, "[5] should be 0xDE");
  munit_assert_uint8(header.raw[6], ==, 0xBC, "[6] should be 0xBC");
  munit_assert_uint8(header.raw[7], ==, 0x9A, "[7] should be 0x9A");
});
*/

static MunitResult
test_packet_header_size() {
  // PacketHeader union should be 8 bytes
  munit_assert_size(sizeof(packet_header_t), ==, 8);
  return MUNIT_OK;
}

static MunitResult
test_tcp_header_fields() {
  packet_header_t header;
  header.tcp_header.src_port = 0x1234;
  header.tcp_header.dest_port = 0x5678;
  header.tcp_header.seq_num = 0x9ABCDEF0;

  // src_port should be 0x1234
  munit_assert_uint16(header.tcp_header.src_port, ==, 0x1234);
  // dest_port should be 0x5678
  munit_assert_uint16(header.tcp_header.dest_port, ==, 0x5678);
  // seq_num should be 0x9ABCDEF0
  munit_assert_uint32(header.tcp_header.seq_num, ==, 0x9ABCDEF0);
  return MUNIT_OK;
}

static MunitResult
test_field_raw_size() {
  // PacketHeader union should be 8 bytes
  munit_assert_size(sizeof(((packet_header_t *)0)->raw), ==, 8);
  return MUNIT_OK;
}

static MunitResult
test_field_to_raw_consistency() {
  packet_header_t header = {0};
  header.tcp_header.src_port = 0x1234;
  header.tcp_header.dest_port = 0x5678;
  header.tcp_header.seq_num = 0x9ABCDEF0;

  // [0] should be 0x34
  munit_assert_uint8(header.raw[0], ==, 0x34);
  // [1] should be 0x12
  munit_assert_uint8(header.raw[1], ==, 0x12);
  // [2] should be 0x78
  munit_assert_uint8(header.raw[2], ==, 0x78);
  // [3] should be 0x56
  munit_assert_uint8(header.raw[3], ==, 0x56);
  // [4] should be 0xF0
  munit_assert_uint8(header.raw[4], ==, 0xF0);
  // [5] should be 0xDE
  munit_assert_uint8(header.raw[5], ==, 0xDE);
  // [6] should be 0xBC
  munit_assert_uint8(header.raw[6], ==, 0xBC);
  // [7] should be 0x9A
  munit_assert_uint8(header.raw[7], ==, 0x9A);
  return MUNIT_OK;
}

int main() {
  MunitTest tests[] = {
      {
          "/test_packet_header_size",
          test_packet_header_size,
          NULL,
          NULL,
          MUNIT_TEST_OPTION_NONE,
          NULL
      },
      {
          "/test_tcp_header_fields",
          test_tcp_header_fields,
          NULL,
          NULL,
          MUNIT_TEST_OPTION_NONE,
          NULL
      },
      {
          "/test_field_raw_size",
          test_field_raw_size,
          NULL,
          NULL,
          MUNIT_TEST_OPTION_NONE,
          NULL
      },
      {
          "/test_field_to_raw_consistency",
          test_field_to_raw_consistency,
          NULL,
          NULL,
          MUNIT_TEST_OPTION_NONE,
          NULL
      },
      { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
    };

    MunitSuite suite = {
        "/formats", /* name */
        tests, /* tests */
        NULL, /* suites */
        1, /* iterations */
        MUNIT_SUITE_OPTION_NONE /* options */
    };

  return munit_suite_main(&suite, NULL, 0, NULL);
}
