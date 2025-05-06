#include "gtest/gtest.h"

extern "C"
{
#include "scene.h"
#include "parser.h"
}

TEST(ParseLineTest, AmbientValidInput)
{
	t_scene scene;
	const char *line = "A 0.2 255,255,255";
	parse_line(line, &scene);
	EXPECT_DOUBLE_EQ(scene.ambient.ratio, 0.2);
	EXPECT_EQ(scene.ambient.color.r, 255);
	EXPECT_EQ(scene.ambient.color.g, 255);
	EXPECT_EQ(scene.ambient.color.b, 255);
}

TEST(ParseLineErrTest, AmbientInvalidInput)
{
	t_scene scene;
	const char *line = "A 0.2";
	EXPECT_EXIT(parse_line(line, &scene), ::testing::ExitedWithCode(EXIT_FAILURE), "Missing ambient light color");
	line = "A 0.2 255,255,255 extra";
	EXPECT_EXIT(parse_line(line, &scene), ::testing::ExitedWithCode(EXIT_FAILURE), "Too many arguments for ambient light");
}

TEST(ParseLineTest, CameraValidInput)
{
	t_scene scene;
	const char *line = "C -50,0,20 0,0,1 70";
	parse_line(line, &scene);
	EXPECT_DOUBLE_EQ(scene.camera.position.x, -50.0);
	EXPECT_DOUBLE_EQ(scene.camera.position.y, 0.0);
	EXPECT_DOUBLE_EQ(scene.camera.position.z, 20.0);
	EXPECT_DOUBLE_EQ(scene.camera.orientation.x, 0.0);
	EXPECT_DOUBLE_EQ(scene.camera.orientation.y, 0.0);
	EXPECT_DOUBLE_EQ(scene.camera.orientation.z, 1.0);
	EXPECT_DOUBLE_EQ(scene.camera.fov, 70.0);
}

TEST(ParseLineErrTest, CameraInvalidInput)
{
	t_scene scene;
	const char *line = "C -50,0,20 0,0,1";
	EXPECT_EXIT(parse_line(line, &scene), ::testing::ExitedWithCode(EXIT_FAILURE), "Missing camera field of view");
	line = "C -50,0,20";
	EXPECT_EXIT(parse_line(line, &scene), ::testing::ExitedWithCode(EXIT_FAILURE), "Missing camera orientation");
	line = "C -50,0,20 0,0,1 70 extra";
	EXPECT_EXIT(parse_line(line, &scene), ::testing::ExitedWithCode(EXIT_FAILURE), "Too many arguments for camera");
}

TEST(ParseLineTest, LightValidInput)
{
	t_scene scene;
	scene.lights = NULL;
	const char *line = "L -40,0,30 0.7 255,255,255";
	parse_line(line, &scene);
	t_light *light = (t_light *)scene.lights->content;
	EXPECT_DOUBLE_EQ(light->position.x, -40.0);
	EXPECT_DOUBLE_EQ(light->position.y, 0.0);
	EXPECT_DOUBLE_EQ(light->position.z, 30.0);
	EXPECT_DOUBLE_EQ(light->brightness, 0.7);
	EXPECT_EQ(light->color.r, 255);
	EXPECT_EQ(light->color.g, 255);
	EXPECT_EQ(light->color.b, 255);
}

TEST(ParseLineErrTest, LightInvalidInput)
{
	t_scene scene;
	scene.lights = NULL;
	const char *line = "L -40,0,30 0.7";
	EXPECT_EXIT(parse_line(line, &scene), ::testing::ExitedWithCode(EXIT_FAILURE), "Missing light color");
	line = "L -40,0,30 0.7 255,255,255 extra";
	EXPECT_EXIT(parse_line(line, &scene), ::testing::ExitedWithCode(EXIT_FAILURE), "Too many arguments for light");
}

TEST(ParseLineTest, PlaneValidInput)
{
	t_scene scene;
	scene.objects = NULL;
	const char *line = "pl 0,0,0 0,1,0 255,255,255";
	parse_line(line, &scene);
	t_plane *plane = (t_plane *)scene.objects->content;
	EXPECT_DOUBLE_EQ(plane->point.x, 0.0);
	EXPECT_DOUBLE_EQ(plane->point.y, 0.0);
	EXPECT_DOUBLE_EQ(plane->point.z, 0.0);
	EXPECT_DOUBLE_EQ(plane->normal.x, 0.0);
	EXPECT_DOUBLE_EQ(plane->normal.y, 1.0);
	EXPECT_DOUBLE_EQ(plane->normal.z, 0.0);
	EXPECT_EQ(plane->color.r, 255);
	EXPECT_EQ(plane->color.g, 255);
	EXPECT_EQ(plane->color.b, 255);
}

TEST(ParseLineErrTest, PlaneInvalidInput)
{
	t_scene scene;
	scene.objects = NULL;
	const char *line = "pl 0,0,0 0,1,0";
	EXPECT_EXIT(parse_line(line, &scene), ::testing::ExitedWithCode(EXIT_FAILURE), "Missing plane color");
	line = "pl 0,0,0 0,1,0 255,255,255 extra";
	EXPECT_EXIT(parse_line(line, &scene), ::testing::ExitedWithCode(EXIT_FAILURE), "Too many arguments for plane");
}

TEST(ParseLineTest, SphereValidInput)
{
	t_scene scene;
	scene.objects = NULL;
	const char *line = "sp 0,0,0 10 255,255,255";
	parse_line(line, &scene);
	t_sphere *sphere = (t_sphere *)scene.objects->content;
	EXPECT_DOUBLE_EQ(sphere->center.x, 0.0);
	EXPECT_DOUBLE_EQ(sphere->center.y, 0.0);
	EXPECT_DOUBLE_EQ(sphere->center.z, 0.0);
	EXPECT_DOUBLE_EQ(sphere->radius, 5.0);
	EXPECT_EQ(sphere->color.r, 255);
	EXPECT_EQ(sphere->color.g, 255);
	EXPECT_EQ(sphere->color.b, 255);
}
TEST(ParseLineErrTest, SphereInvalidInput)
{
	t_scene scene;
	scene.objects = NULL;
	const char *line = "sp 0,0,0 10";
	EXPECT_EXIT(parse_line(line, &scene), ::testing::ExitedWithCode(EXIT_FAILURE), "Missing sphere color");
	line = "sp 0,0,0 10 255,255,255 extra";
	EXPECT_EXIT(parse_line(line, &scene), ::testing::ExitedWithCode(EXIT_FAILURE), "Too many arguments for sphere");
}

TEST(ParseLineTest, CylinderValidInput)
{
	t_scene scene;
	scene.objects = NULL;
	const char *line = "cy 0,0,0 0,1,0 10 20 255,255,255";
	parse_line(line, &scene);
	t_cylinder *cylinder = (t_cylinder *)scene.objects->content;
	EXPECT_DOUBLE_EQ(cylinder->center.x, 0.0);
	EXPECT_DOUBLE_EQ(cylinder->center.y, 0.0);
	EXPECT_DOUBLE_EQ(cylinder->center.z, 0.0);
	EXPECT_DOUBLE_EQ(cylinder->axis.x, 0.0);
	EXPECT_DOUBLE_EQ(cylinder->axis.y, 1.0);
	EXPECT_DOUBLE_EQ(cylinder->axis.z, 0.0);
	EXPECT_DOUBLE_EQ(cylinder->radius, 5.0);
	EXPECT_DOUBLE_EQ(cylinder->height, 20.0);
	EXPECT_EQ(cylinder->color.r, 255);
	EXPECT_EQ(cylinder->color.g, 255);
	EXPECT_EQ(cylinder->color.b, 255);
}

TEST(ParseLineErrTest, CylinderInvalidInput)
{
	t_scene scene;
	scene.objects = NULL;
	const char *line = "cy 0,0,0 0,1,0 10 20";
	EXPECT_EXIT(parse_line(line, &scene), ::testing::ExitedWithCode(EXIT_FAILURE), "Missing cylinder color");
	line = "cy 0,0,0 0,1,0 10 20 255,255,255 extra";
	EXPECT_EXIT(parse_line(line, &scene), ::testing::ExitedWithCode(EXIT_FAILURE), "Too many arguments for cylinder");
}
TEST(ParseLineTest, ConeValidInput)
{
	t_scene scene;
	scene.objects = NULL;
	const char *line = "co 0,0,0 0,1,0 10 20 255,255,255";
	parse_line(line, &scene);
	t_cone *cone = (t_cone *)scene.objects->content;
	EXPECT_DOUBLE_EQ(cone->apex.x, 0.0);
	EXPECT_DOUBLE_EQ(cone->apex.y, 0.0);
	EXPECT_DOUBLE_EQ(cone->apex.z, 0.0);
	EXPECT_DOUBLE_EQ(cone->axis.x, 0.0);
	EXPECT_DOUBLE_EQ(cone->axis.y, 1.0);
	EXPECT_DOUBLE_EQ(cone->axis.z, 0.0);
	EXPECT_DOUBLE_EQ(cone->radius, 5.0);
	EXPECT_DOUBLE_EQ(cone->height, 20.0);
	EXPECT_EQ(cone->color.r, 255);
	EXPECT_EQ(cone->color.g, 255);
	EXPECT_EQ(cone->color.b, 255);
}
TEST(ParseLineErrTest, ConeInvalidInput)
{
	t_scene scene;
	scene.objects = NULL;
	const char *line = "co 0,0,0 0,1,0 10 20";
	EXPECT_EXIT(parse_line(line, &scene), ::testing::ExitedWithCode(EXIT_FAILURE), "Missing cone color");
	line = "co 0,0,0 0,1,0 10 20 255,255,255 extra";
	EXPECT_EXIT(parse_line(line, &scene), ::testing::ExitedWithCode(EXIT_FAILURE), "Too many arguments for cone");
}

TEST(ParseLineErrTest, UnknownIdentifier)
{
	t_scene scene;
	scene.objects = NULL;
	const char *line = "X 0,0,0";
	EXPECT_EXIT(parse_line(line, &scene), ::testing::ExitedWithCode(EXIT_FAILURE), "Unknown identifier 'X'");
}
