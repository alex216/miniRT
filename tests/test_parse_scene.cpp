#include "gtest/gtest.h"

extern "C"
{
#include "scene.h"
#include "parser.h"
}

TEST(ParseSceneErrTest, ParseFileInvalid)
{
	t_scene scene;
	EXPECT_EXIT({
		parse_scene(&scene, "./scenes/invalid.rt");
		exit(EXIT_FAILURE); }, ::testing::ExitedWithCode(EXIT_FAILURE), ".*");
}

TEST(ParseSceneErrTest, ParseFileInvalidFormat)
{
	t_scene scene;
	scene.lights = NULL;
	scene.objects = NULL;
	EXPECT_EXIT({
		parse_scene(&scene, "./scenes/minimalist_err.rt");
		exit(EXIT_FAILURE); }, ::testing::ExitedWithCode(EXIT_FAILURE), "Too many ambient lights");
	EXPECT_EXIT({
		parse_scene(&scene, "./scenes/minimalist_err2.rt");
		exit(EXIT_FAILURE); }, ::testing::ExitedWithCode(EXIT_FAILURE), "Too many cameras");
	EXPECT_EXIT({
		parse_scene(&scene, "./scenes/minimalist_err3.rt");
		exit(EXIT_FAILURE); }, ::testing::ExitedWithCode(EXIT_FAILURE), "Too many lights");
}
