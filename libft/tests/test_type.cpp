// Copyright 2024, reasuke.

#include "gtest/gtest.h"

extern "C" {
#include "ft_type.h"
}

TEST(ft_isblank, test) {
  EXPECT_TRUE(ft_isblank(' '));
  EXPECT_TRUE(ft_isblank('\t'));

  EXPECT_FALSE(ft_isblank('a'));
  EXPECT_FALSE(ft_isblank('0'));
  EXPECT_FALSE(ft_isblank('\0'));
  EXPECT_FALSE(ft_isblank('<'));
}
