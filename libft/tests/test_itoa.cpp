// Copyright 2024, reasuke.

#include <string>

#include "gtest/gtest.h"
#include "unit_test_utils.hpp"

extern "C" {
#include "ft_string.h"
}

TEST(ft_itoa, test) {
  EXPECT_EQ(std::string(ft_itoa(0)), std::string("0"));
  EXPECT_EQ(std::string(ft_itoa(42)), std::string("42"));
  EXPECT_EQ(std::string(ft_itoa(-42)), std::string("-42"));
  EXPECT_EQ(std::string(ft_itoa(1000000)), std::string("1000000"));
  EXPECT_EQ(std::string(ft_itoa(-1000000)), std::string("-1000000"));
  EXPECT_EQ(std::string(ft_itoa(2147483647)), std::string("2147483647"));
  EXPECT_EQ(std::string(ft_itoa(-2147483648)), std::string("-2147483648"));
}
