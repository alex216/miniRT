// Copyright 2024, reasuke.

#ifndef UNIT_TEST_UTILS_H
#define UNIT_TEST_UTILS_H

#define CHECK_EQ(func, ...) EXPECT_EQ(ft_##func(__VA_ARGS__), func(__VA_ARGS__))

#endif
