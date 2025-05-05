// Copyright 2024, reasuke.

#include <iostream>
#include <string>

#include "gtest/gtest.h"

extern "C" {
#include "ft_string.h"
}

TEST(ft_basename, emptyString) {
  char path[] = "";
  EXPECT_EQ(std::string(ft_basename(path)), std::string("."));
}

TEST(ft_basename, null) {
  char *path = nullptr;
  EXPECT_EQ(std::string(ft_basename(path)), std::string("."));
}

TEST(ft_basename, root) {
  char path[] = "/";
  EXPECT_EQ(std::string(ft_basename(path)), std::string("/"));
}

TEST(ft_basename, twoRoots) {
  char path[] = "//";
  EXPECT_EQ(std::string(ft_basename(path)), std::string("/"));
}

TEST(ft_basename, absolutePath) {
  char path[] = "/usr/lib";
  EXPECT_EQ(std::string(ft_basename(path)), std::string("lib"));
}

TEST(ft_basename, slashedAbsolutePath) {
  char path[] = "/usr/";
  EXPECT_EQ(std::string(ft_basename(path)), std::string("usr"));
}

TEST(ft_basename, relativePath) {
  char path[] = "./usr/lib";
  EXPECT_EQ(std::string(ft_basename(path)), std::string("lib"));
}

TEST(ft_basename, slashedRelativePath) {
  char path[] = "./usr/";
  EXPECT_EQ(std::string(ft_basename(path)), std::string("usr"));
}

TEST(ft_basename, oneSlash) {
  char path[] = "abc/";
  EXPECT_EQ(std::string(ft_basename(path)), std::string("abc"));
}

TEST(ft_basename, twoSlashes) {
  char path[] = "abc//";
  EXPECT_EQ(std::string(ft_basename(path)), std::string("abc"));
}

TEST(ft_basename, threeSlashes) {
  char path[] = "abc///";
  EXPECT_EQ(std::string(ft_basename(path)), std::string("abc"));
}

TEST(ft_basename, dot) {
  char path[] = ".";
  EXPECT_EQ(std::string(ft_basename(path)), std::string("."));
}

TEST(ft_basename, dotDot) {
  char path[] = "..";
  EXPECT_EQ(std::string(ft_basename(path)), std::string(".."));
}

TEST(ft_basename, dotSlash) {
  char path[] = "./";
  EXPECT_EQ(std::string(ft_basename(path)), std::string("."));
}

TEST(ft_basename, fdfFile) {
  char path1[] = ".fdf";
  char path2[] = "42.fdf";
  char path3[] = "42.fdf/";
  char path4[] = "./42.fdf";
  char path5[] = "../42.fdf";
  char path6[] = "./maps/42.fdf";
  char path7[] = "maps/42.fdf";

  EXPECT_EQ(std::string(ft_basename(path1)), std::string(".fdf"));
  EXPECT_EQ(std::string(ft_basename(path2)), std::string("42.fdf"));
  EXPECT_EQ(std::string(ft_basename(path3)), std::string("42.fdf"));
  EXPECT_EQ(std::string(ft_basename(path4)), std::string("42.fdf"));
  EXPECT_EQ(std::string(ft_basename(path5)), std::string("42.fdf"));
  EXPECT_EQ(std::string(ft_basename(path6)), std::string("42.fdf"));
  EXPECT_EQ(std::string(ft_basename(path7)), std::string("42.fdf"));
}
