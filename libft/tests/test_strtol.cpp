// Copyright 2024, reasuke.

#include "gtest/gtest.h"
#include "unit_test_utils.hpp"

extern "C" {
#include "ft_string.h"
}

// output test
TEST(ft_strtol, checkBase) {
  CHECK_EQ(strtol, "100101011", NULL, 2);
  CHECK_EQ(strtol, "-100101011", NULL, 2);
  CHECK_EQ(strtol, "22764274", NULL, 8);
  CHECK_EQ(strtol, "-22764274", NULL, 8);
  CHECK_EQ(strtol, "756267263410", NULL, 10);
  CHECK_EQ(strtol, "-756267263410", NULL, 10);
  CHECK_EQ(strtol, "328ab9fe", NULL, 16);
  CHECK_EQ(strtol, "-328ab9fe", NULL, 16);
  CHECK_EQ(strtol, "nzx8p", NULL, 36);
  CHECK_EQ(strtol, "-nzx8p", NULL, 36);
}

TEST(ft_strtol, baseWithPrefix) {
  CHECK_EQ(strtol, "0123", NULL, 8);
  CHECK_EQ(strtol, "-0123", NULL, 8);
  CHECK_EQ(strtol, "0x8fd", NULL, 16);
  CHECK_EQ(strtol, "-0x8fd", NULL, 16);
}

TEST(ft_strtol, autoDetectBase) {
  CHECK_EQ(strtol, "123", NULL, 0);
  CHECK_EQ(strtol, "-123", NULL, 0);
  CHECK_EQ(strtol, "0123", NULL, 0);
  CHECK_EQ(strtol, "-0123", NULL, 0);
  CHECK_EQ(strtol, "0x8fd", NULL, 0);
  CHECK_EQ(strtol, "-0x8fd", NULL, 0);
}

TEST(ft_strtol, startWithWhiteSpaces) {
  CHECK_EQ(strtol, "               123", NULL, 10);
  CHECK_EQ(strtol, "\t\t    \t 123", NULL, 10);
  CHECK_EQ(strtol, "\t\n\v\f\r 123", NULL, 10);
}

TEST(ft_strtol, endWithInvalidCharactor) {
  CHECK_EQ(strtol, "81276132abdefzz", NULL, 10);
  CHECK_EQ(strtol, "81276132 ", NULL, 10);
  CHECK_EQ(strtol, "81276132@@@@", NULL, 10);
  CHECK_EQ(strtol, "81276132\t\t\t\t", NULL, 10);
}

TEST(ft_strtol, hasLeadingZeros) {
  CHECK_EQ(strtol, "000000000000123", NULL, 10);
  CHECK_EQ(strtol, "   000000000000123", NULL, 10);
  CHECK_EQ(strtol, " \t  000000000000123", NULL, 10);
}

// errno test
static void check_errno(const char *input, int base) {
  errno = 0;
  long c_result = strtol(input, NULL, base);
  int c_errno = errno;

  errno = 0;
  long ft_result = ft_strtol(input, NULL, base);
  int ft_errno = errno;

  EXPECT_EQ(c_result, ft_result);
  EXPECT_EQ(c_errno, ft_errno);
}

TEST(ft_strtol, errnoValidBase) {
  const char *input = "123";

  check_errno(input, 10);
  check_errno(input, 8);
  check_errno(input, 16);
}

TEST(ft_strtol, errnoInvalidBase) {
  std::vector<int> bases = {-42, -1, 1, 37, 4242};
  const char *input = "123";

  for (int &base : bases) {
    check_errno(input, base);
  }
}

TEST(ft_strtol, errnoValidInput) {
  int base = 10;

  check_errno("0", base);
  check_errno("9223372036854775807", base);
  check_errno("-9223372036854775808", base);
  check_errno("2894723abc", base);
}

TEST(ft_strtol, errnoOverflownInput) {
  int base = 10;

  check_errno("9223372036854775808", base);
  check_errno("298347928374927394792834792928347928374", base);
  check_errno("-9223372036854775809", base);
  check_errno("-39485723874051730487234290384727340374", base);
}

#ifdef __APPLE__
TEST(ft_strtol, errnoStartWithInvalidCharactor) {
  int base = 10;

  check_errno("", base);
  check_errno("abcdef", base);
  check_errno("@![]/.,", base);
}
#endif

// endptr test
static void check_endptr(const char *input, int base) {
  char *c_endptr = nullptr;
  int c_result = strtol(input, &c_endptr, base);

  char *ft_endptr = nullptr;
  int ft_result = strtol(input, &ft_endptr, base);

  EXPECT_EQ(c_result, ft_result);
  EXPECT_EQ(c_endptr, ft_endptr);
}

TEST(ft_strtol, endptrNormal) {
  int base = 10;

  check_endptr("123", base);
  check_endptr("123a123", base);
  check_endptr("    123123   ", base);
}

TEST(ft_strtol, endptrWithPrefix) {
  check_endptr("01235", 8);
  check_endptr("-1235", 8);
  check_endptr("   0xdef", 16);
  check_endptr("   -0xdef", 16);
  check_endptr("   00xdef", 16);
}
