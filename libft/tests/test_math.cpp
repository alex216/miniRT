// Copyright 2024, reasuke.

#include "gtest/gtest.h"
#include "unit_test_utils.hpp"

extern "C" {
#include "ft_math.h"
}

TEST(ft_abs, test) {
  EXPECT_EQ(ft_abs(42), 42);
  EXPECT_EQ(ft_abs(0), 0);
  EXPECT_EQ(ft_abs(-42), 42);
}

TEST(ft_chmax, chooseMax) {
  int a = 0;
  int b = 42;

  EXPECT_TRUE(ft_chmax(&a, b));
  EXPECT_EQ(a, 42);
}

TEST(ft_chmax, notChooseMax) {
  int a = 42;
  int b = 0;

  EXPECT_FALSE(ft_chmax(&a, b));
  EXPECT_EQ(a, 42);
}

TEST(ft_chmin, chooseMin) {
  int a = 42;
  int b = 0;

  EXPECT_TRUE(ft_chmin(&a, b));
  EXPECT_EQ(a, b);
}

TEST(ft_chmin, notChooseMin) {
  int a = 0;
  int b = 42;

  EXPECT_FALSE(ft_chmin(&a, b));
  EXPECT_EQ(a, 0);
}

TEST(ft_max, test) {
  EXPECT_EQ(ft_max(0, 0), 0);
  EXPECT_EQ(ft_max(42, 0), 42);
  EXPECT_EQ(ft_max(0, 42), 42);
}

TEST(ft_min, test) {
  EXPECT_EQ(ft_min(0, 0), 0);
  EXPECT_EQ(ft_min(42, 0), 0);
  EXPECT_EQ(ft_min(0, 42), 0);
}

TEST(ft_swap, test) {
  int a = 42;
  int b = 0;

  ft_swap(&a, &b);
  EXPECT_EQ(a, 0);
  EXPECT_EQ(b, 42);
}

TEST(ft_fabs, test) {
  EXPECT_EQ(ft_fabs(4.2), 4.2);
  EXPECT_EQ(ft_fabs(0), 0);
  EXPECT_EQ(ft_fabs(-4.2), 4.2);
}

TEST(ft_fchmax, chooseMax) {
  double a = 0;
  double b = 4.2;

  EXPECT_TRUE(ft_fchmax(&a, b));
  EXPECT_EQ(a, 4.2);
}

TEST(ft_fchmax, notChooseMax) {
  double a = 4.2;
  double b = 0;

  EXPECT_FALSE(ft_fchmax(&a, b));
  EXPECT_EQ(a, 4.2);
}

TEST(ft_fchmin, chooseMin) {
  double a = 4.2;
  double b = 0;

  EXPECT_TRUE(ft_fchmin(&a, b));
  EXPECT_EQ(a, b);
}

TEST(ft_fchmin, notChooseMin) {
  double a = 0;
  double b = 4.2;

  EXPECT_FALSE(ft_fchmin(&a, b));
  EXPECT_EQ(a, 0);
}

TEST(ft_fmax, test) {
  EXPECT_EQ(ft_fmax(0, 0), 0);
  EXPECT_EQ(ft_fmax(4.2, 0), 4.2);
  EXPECT_EQ(ft_fmax(0, 4.2), 4.2);
}

TEST(ft_fmin, test) {
  EXPECT_EQ(ft_fmin(0, 0), 0);
  EXPECT_EQ(ft_fmin(4.2, 0), 0);
  EXPECT_EQ(ft_fmin(0, 4.2), 0);
}

TEST(ft_fswap, test) {
  double a = 4.2;
  double b = 0;

  ft_fswap(&a, &b);
  EXPECT_EQ(a, 0);
  EXPECT_EQ(b, 4.2);
}