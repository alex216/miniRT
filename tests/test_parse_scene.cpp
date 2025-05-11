#include "gtest/gtest.h"

extern "C"
{
#include "scene.h"
#include "parser.h"
}

TEST(ParseSceneTest, ParseFile)
{
	t_scene *scene = parse_scene("./scenes/minimalist.rt");
	ASSERT_NE(scene, nullptr);
	EXPECT_EQ(scene->ambient.ratio, 0.2);
	EXPECT_EQ(scene->camera.fov, 70.0);
}

TEST(ParseSceneErrTest, ParseFileInvalid)
{
	EXPECT_EXIT({
		parse_scene("./scenes/invalid.rt");
		exit(EXIT_FAILURE); }, ::testing::ExitedWithCode(EXIT_FAILURE), ".*");
}

TEST(ParseSceneErrTest, ParseFileInvalidFormat)
{
	EXPECT_EXIT({
		parse_scene("./scenes/minimalist_err.rt");
		exit(EXIT_FAILURE); }, ::testing::ExitedWithCode(EXIT_FAILURE), "Too many ambient lights");
	EXPECT_EXIT({
		parse_scene("./scenes/minimalist_err2.rt");
		exit(EXIT_FAILURE); }, ::testing::ExitedWithCode(EXIT_FAILURE), "Too many cameras");
	EXPECT_EXIT({
		parse_scene("./scenes/minimalist_err3.rt");
		exit(EXIT_FAILURE); }, ::testing::ExitedWithCode(EXIT_FAILURE), "Too many lights");
}
