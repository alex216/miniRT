// Copyright 2024, reasuke.

#include "gtest/gtest.h"
#include "unit_test_utils.hpp"

extern "C" {
#include "ft_file.h"
}

TEST(file_to_lines, normal) {
  const char *file_path = "./tests/fixture/normal.txt";
  char **lines = file_to_lines(const_cast<char *>(file_path));
  std::vector<char const *> ans = {"abc\n", "def\n", "123\n"};

  for (int i = 0; i < (int)ans.size(); ++i) {
    EXPECT_EQ(strcmp(ans[i], lines[i]), 0);
  }
}

TEST(file_to_lines, empty) {
  const char *file_path = "./tests/fixture/empty.txt";
  char **lines = file_to_lines(const_cast<char *>(file_path));

  EXPECT_EQ(lines[0], nullptr);
}

TEST(file_to_lines, noNewline) {
  const char *file_path = "./tests/fixture/one_line_with_no_newline.txt";
  char **lines = file_to_lines(const_cast<char *>(file_path));

  EXPECT_EQ(
      strcmp(lines[0], "abslkadjflsdjf;lsjdl;fkjsadl;fjsldjflsdjflsjdfksjldfj"),
      0);
}

TEST(file_to_lines, lineNoTrailingNewline) {
  const char *file_path = "./tests/fixture/lines_no_trailing_newline.txt";
  char **lines = file_to_lines(const_cast<char *>(file_path));
  std::vector<char const *> ans = {"hello\n", "world\n", "42\n", "tokyo"};

  for (int i = 0; i < (int)ans.size(); ++i) {
    EXPECT_EQ(strcmp(ans[i], lines[i]), 0);
  }
}
