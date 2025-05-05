// Copyright 2024, reasuke.

#include <string>

#include "gtest/gtest.h"
#include "unit_test_utils.hpp"

extern "C" {
#include <string.h>

#include "ft_string.h"
}

TEST(ft_strndup, test) {
  std::string s1("Hello World");
  char *ret;
  char *ft_ret;

  for (int i = 0; i < 10; ++i) {
    ret = strndup(s1.c_str(), i);
    ft_ret = ft_strndup(s1.c_str(), i);

    EXPECT_EQ(strcmp(ret, ft_ret), 0);
  }
}
