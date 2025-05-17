#include "gtest/gtest.h"

extern "C"
{
#include "scene.h"
#include "parser.h"
}

TEST(IS_THREE_INTEGER_TEST, IsThreeInteger)
{
	EXPECT_TRUE(is_three_integer("123,456,789"));
	EXPECT_FALSE(is_three_integer("123,456"));
	EXPECT_FALSE(is_three_integer("123,,456"));
	EXPECT_FALSE(is_three_integer("123,,456,"));
	EXPECT_FALSE(is_three_integer(",,456,"));
	EXPECT_FALSE(is_three_integer("123,456,789,0"));
	EXPECT_FALSE(is_three_integer("123.456,789"));
	EXPECT_FALSE(is_three_integer("abc,def,ghi"));
	EXPECT_FALSE(is_three_integer("123,456abc789"));
	EXPECT_FALSE(is_three_integer("123456789"));
}

TEST(IS_VEC3_TEST, IsVec3)
{
	EXPECT_TRUE(is_vec3("1.0,2.0,3.0"));
	EXPECT_FALSE(is_vec3("1.0,2.0,3.0,4.0"));
	EXPECT_FALSE(is_vec3("1.0,2.0"));
	EXPECT_FALSE(is_vec3("1.0,,3.0"));
	EXPECT_FALSE(is_vec3("1.0,,3.0,4.0"));
	EXPECT_FALSE(is_vec3(",,2.0,3.0"));
	EXPECT_FALSE(is_vec3("1.0,2.03"));
	EXPECT_FALSE(is_vec3("abc,def,ghi"));
	EXPECT_FALSE(is_vec3("1.0,2abc,3.0"));
	EXPECT_FALSE(is_vec3("123456789"));
}

TEST(ParseRatioTest, ValidInput)
{
	EXPECT_DOUBLE_EQ(parse_ratio("0.5"), 0.5);
	EXPECT_DOUBLE_EQ(parse_ratio("1.0"), 1.0);
	EXPECT_DOUBLE_EQ(parse_ratio("0.0"), 0.0);
}

TEST(ParseRatioTest, InvalidInput)
{
	EXPECT_EXIT(parse_ratio("1.5"), ::testing::ExitedWithCode(EXIT_FAILURE), "Invalid ratio value");
	EXPECT_EXIT(parse_ratio("-0.5"), ::testing::ExitedWithCode(EXIT_FAILURE), "Invalid ratio value");
	EXPECT_EXIT(parse_ratio("abc"), ::testing::ExitedWithCode(EXIT_FAILURE), "Invalid format");
	EXPECT_EXIT(parse_ratio("1,0"), ::testing::ExitedWithCode(EXIT_FAILURE), "Invalid format");
}

TEST(ParseColorTest, ValidInput)
{
	t_rgb color = parse_color("255,255,255");
	EXPECT_EQ(color.r, 255);
	EXPECT_EQ(color.g, 255);
	EXPECT_EQ(color.b, 255);

	color = parse_color("0,0,0");
	EXPECT_EQ(color.r, 0);
	EXPECT_EQ(color.g, 0);
	EXPECT_EQ(color.b, 0);

	color = parse_color("128,128,128");
	EXPECT_EQ(color.r, 128);
	EXPECT_EQ(color.g, 128);
	EXPECT_EQ(color.b, 128);
}

TEST(ParseColorErrTEST, InvalidInput)
{
	EXPECT_EXIT(parse_color("256,0,0"), ::testing::ExitedWithCode(EXIT_FAILURE), "Color values must be in the range \\[0, 255\\]");
	EXPECT_EXIT(parse_color("0,256,0"), ::testing::ExitedWithCode(EXIT_FAILURE), "Color values must be in the range \\[0, 255\\]");
	EXPECT_EXIT(parse_color("0,0,256"), ::testing::ExitedWithCode(EXIT_FAILURE), "Color values must be in the range \\[0, 255\\]");
	EXPECT_EXIT(parse_color("4222222222222222222222222,255,255"), ::testing::ExitedWithCode(EXIT_FAILURE), "Color values must be in the range \\[0, 255\\]");
	EXPECT_EXIT(parse_color("abc"), ::testing::ExitedWithCode(EXIT_FAILURE), "Invalid color vector");
	EXPECT_EXIT(parse_color("255,255"), ::testing::ExitedWithCode(EXIT_FAILURE), "Invalid color vector");
	EXPECT_EXIT(parse_color("255,255,255,255"), ::testing::ExitedWithCode(EXIT_FAILURE), "Invalid color vector");
	EXPECT_EXIT(parse_color("abc,255,255"), ::testing::ExitedWithCode(EXIT_FAILURE), "Invalid color vector");
	EXPECT_EXIT(parse_color("255,abc,255"), ::testing::ExitedWithCode(EXIT_FAILURE), "Invalid color vector");
	EXPECT_EXIT(parse_color("255,255,abc"), ::testing::ExitedWithCode(EXIT_FAILURE), "Invalid color vector");
}

TEST(ParseVectorTest, ValidInput)
{
	t_vec3 vector = parse_vector_position("1.0,2.0,3.0");
	EXPECT_DOUBLE_EQ(vector.x, 1.0);
	EXPECT_DOUBLE_EQ(vector.y, 2.0);
	EXPECT_DOUBLE_EQ(vector.z, 3.0);

	vector = parse_vector_position("0.0,0.0,0.0");
	EXPECT_DOUBLE_EQ(vector.x, 0.0);
	EXPECT_DOUBLE_EQ(vector.y, 0.0);
	EXPECT_DOUBLE_EQ(vector.z, 0.0);

	vector = parse_vector_position("-1.5,-2.5,-3.5");
	EXPECT_DOUBLE_EQ(vector.x, -1.5);
	EXPECT_DOUBLE_EQ(vector.y, -2.5);
	EXPECT_DOUBLE_EQ(vector.z, -3.5);
}

TEST(ParseVectorErrTest, InvalidInput)
{
	EXPECT_EXIT(parse_vector_position("1.0,2.0"), ::testing::ExitedWithCode(EXIT_FAILURE), "Invalid vector");
	EXPECT_EXIT(parse_vector_position("1.0,2.0,3.0,4.0"), ::testing::ExitedWithCode(EXIT_FAILURE), "Invalid vector");
}

TEST(ParseVectorDirectionErrTest, InvalidInput)
{
	EXPECT_EXIT(parse_vector_direction("1.0,2.0,3.0"), ::testing::ExitedWithCode(EXIT_FAILURE), "Vector value out of range");
}

TEST(ParsePositiveDoubleTest, ValidInput)
{
	EXPECT_DOUBLE_EQ(parse_positive_double("1.0"), 1.0);
	EXPECT_DOUBLE_EQ(parse_positive_double("0.5"), 0.5);
}

TEST(ParsePositiveDoubleErrTest, InvalidInput)
{
	EXPECT_EXIT(parse_positive_double("-1.0"), ::testing::ExitedWithCode(EXIT_FAILURE), "Invalid positive value");
	EXPECT_EXIT(parse_positive_double("-0.0"), ::testing::ExitedWithCode(EXIT_FAILURE), "Invalid positive value");
	EXPECT_EXIT(parse_positive_double("+0.0"), ::testing::ExitedWithCode(EXIT_FAILURE), "Invalid positive value");
}

TEST(ParseDegreeTest, ValidInput)
{
	EXPECT_DOUBLE_EQ(parse_degree("45.0"), 45.0);
	EXPECT_DOUBLE_EQ(parse_degree("180.0"), 180.0);
	EXPECT_DOUBLE_EQ(parse_degree("0.0"), 0.0);
}

TEST(ParseDegreeErrTest, InvalidInput)
{
	EXPECT_EXIT(parse_degree("190.0"), ::testing::ExitedWithCode(EXIT_FAILURE), "Invalid degree value");
	EXPECT_EXIT(parse_degree("-10.0"), ::testing::ExitedWithCode(EXIT_FAILURE), "Invalid degree value");
}
