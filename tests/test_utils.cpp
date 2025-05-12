#include "gtest/gtest.h"

extern "C"
{
#include "scene.h"
#include "parser.h"
#include "utils.h"
}

TEST(FT_ATOF_TEST, CompareWithOriginalATOF_Nullptr)
{
	const char *str = nullptr;
	double expected = 0.0; // atof(NULL) is undefined behavior, but we assume it returns 0.0
	double result = ft_atof(str);
	EXPECT_DOUBLE_EQ(result, expected);
}

TEST(FT_ATOF_TEST, CompareWithOriginalATOF_EmptyString)
{
	const char *str = "";
	double expected = atof(str);
	double result = ft_atof(str);
	EXPECT_DOUBLE_EQ(result, expected);
}

TEST(FT_ATOF_TEST, CompareWithOriginalATOF_OnlySpaces)
{
	const char *str = "     ";
	double expected = atof(str);
	double result = ft_atof(str);
	EXPECT_DOUBLE_EQ(result, expected);
}

TEST(FT_ATOF_TEST, CompareWithOriginalATOF_InvalidInput)
{
	const char *str = "abc";
	double expected = atof(str);
	double result = ft_atof(str);
	EXPECT_DOUBLE_EQ(result, expected);
}

TEST(FT_ATOF_TEST, CompareWithOriginalATOF_Zero)
{
	const char *str = "0.0";
	double expected = atof(str);
	double result = ft_atof(str);
	EXPECT_DOUBLE_EQ(result, expected);
}

TEST(FT_ATOF_TEST, CompareWithOriginalATOF_PositiveNumbers)
{
	const char *str = "123.456";
	double expected = atof(str);
	double result = ft_atof(str);
	EXPECT_DOUBLE_EQ(result, expected);
}

TEST(FT_ATOF_TEST, CompareWithOriginalATOF_NegativeNumbers)
{
	const char *str = "-123.456";
	double expected = atof(str);
	double result = ft_atof(str);
	EXPECT_DOUBLE_EQ(result, expected);
}

// 123abc456 is invalid but it will be parsed as 123
TEST(FT_ATOF_TEST, CompareWithOriginalATOF_MixedAlphanumeric)
{
	const char *str = "123abc456";
	double expected = atof(str);
	double result = ft_atof(str);
	EXPECT_DOUBLE_EQ(result, expected);
}

// 123.45.67 is invalid but it will be parsed as 123.45
TEST(FT_ATOF_TEST, CompareWithOriginalATOF_MultipleDots)
{
	const char *str = "123.45.67";
	double expected = atof(str);
	double result = ft_atof(str);
	EXPECT_DOUBLE_EQ(result, expected);
}

TEST(FT_ATOF_TEST, CompareWithOriginalATOF_LeadingSpaces)
{
	const char *str = "   42.42";
	double expected = atof(str);
	double result = ft_atof(str);
	EXPECT_DOUBLE_EQ(result, expected);
}

TEST(FT_ATOF_TEST, CompareWithOriginalATOF_TrailingSpaces)
{
	const char *str = "42.42   ";
	double expected = atof(str);
	double result = ft_atof(str);
	EXPECT_DOUBLE_EQ(result, expected);
}

TEST(FT_ATOF_TEST, CompareWithOriginalATOF_HighPrecision)
{
	const char *str = "3.14159265358979323846";
	double expected = atof(str);
	double result = ft_atof(str);
	EXPECT_DOUBLE_EQ(result, expected);
}

TEST(FT_ATOF_TEST, CompareWithOriginalATOF_SmallNumbers)
{
	const char *str = "0.000000000123456789";
	double expected = atof(str);
	double result = ft_atof(str);
	EXPECT_DOUBLE_EQ(result, expected);
}

TEST(FT_ATOF_TEST, CompareWithOriginalATOF_LargeNumbers)
{
	const char *str = "12345678901234567890.0";
	double expected = atof(str);
	double result = ft_atof(str);
	EXPECT_DOUBLE_EQ(result, expected);
}

// TEST(FT_ATOF_TEST, CompareWithOriginalATOF_VerySmallNumbers)
// {
// 	const char *str = "0.0000000000000000000000000000000000000000000000000000000042";
// 	double expected = atof(str);
// 	double result = ft_atof(str);
// 	EXPECT_DOUBLE_EQ(result, expected);
// }

// (Smallest normalized positive number): Approximately 2.2×10^-308
// TEST(FT_ATOF_TEST, CompareWithOriginalATOF_MinNormalizedPositive)
// {
// 	// const char *str = "2.2250738585072014e-308";
// 	double expected = atof(str);
// 	double result = ft_atof(str);
// 	EXPECT_DOUBLE_EQ(result, expected);
// }

// (Smallest subnormal positive number): Approximately 4.9×10^-324
// TEST(FT_ATOF_TEST, CompareWithOriginalATOF_MinSubnormalPositive)
// {
// 	// const char *str = "4.94065645841246544176568128e-324";
// 	double expected = atof(str);
// 	double result = ft_atof(str);
// 	EXPECT_DOUBLE_EQ(result, expected);
// }

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
