// Copyright 2024, reasuke.

#include <string>

#include "gtest/gtest.h"
#include "unit_test_utils.hpp"

extern "C" {
#include <string.h>

#include "ft_string.h"
}

TEST(ft_strstr, test) {
  std::string s1("abcdefg");
  std::string s2("def");
  std::string s3("dek");
  std::string s4("");

  CHECK_EQ(strstr, s1.c_str(), s2.c_str());
  CHECK_EQ(strstr, s1.c_str(), s3.c_str());
  CHECK_EQ(strstr, s1.c_str(), s4.c_str());
  CHECK_EQ(strstr, s1.c_str(), s1.c_str());
  CHECK_EQ(strstr, s4.c_str(), s4.c_str());
  CHECK_EQ(strstr, s2.c_str(), s1.c_str());
}
