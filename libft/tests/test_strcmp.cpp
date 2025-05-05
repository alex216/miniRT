// Copyright 2024, reasuke.

#include <string>

#include "gtest/gtest.h"
#include "unit_test_utils.hpp"

extern "C" {
#include <string.h>

#include "ft_string.h"
}

TEST(ft_strcmp, test) {
  std::string s1("Hello World");
  std::string s2("Hello:World");

  CHECK_EQ(strcmp, s1.c_str(), s1.c_str());
  CHECK_EQ(strcmp, s2.c_str(), s2.c_str());
  CHECK_EQ(strcmp, s1.c_str(), s2.c_str());
  CHECK_EQ(strcmp, s2.c_str(), s1.c_str());
}
