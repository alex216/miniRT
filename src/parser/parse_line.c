/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:39:40 by yliu              #+#    #+#             */
/*   Updated: 2025/05/12 16:38:30 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parser.h"
#include "scene.h"
#include "utils.h"

// syntax: A [ratio] [color]
static void	parse_ambient(const char **line, t_scene *scene)
{
	char	*token;

	token = next_token(line, ft_isspace);
	if (!token)
		fatal_error("Missing ambient light ratio");
	scene->ambient.ratio = parse_ratio(token);
	free(token);
	token = next_token(line, ft_isspace);
	if (!token)
		fatal_error("Missing ambient light color");
	scene->ambient.color = parse_color(token);
	free(token);
	token = next_token(line, ft_isspace);
	if (token)
		fatal_error("Too many arguments for ambient light");
}

// syntax: C [position] [orientation] [fov]
static void	parse_camera(const char **line, t_scene *scene)
{
	char	*token;

	token = next_token(line, ft_isspace);
	if (!token)
		fatal_error("Missing camera position");
	scene->camera.position = parse_vector_position(token);
	free(token);
	token = next_token(line, ft_isspace);
	if (!token)
		fatal_error("Missing camera orientation");
	scene->camera.orientation = parse_vector_direction(token);
	free(token);
	token = next_token(line, ft_isspace);
	if (!token)
		fatal_error("Missing camera field of view");
	scene->camera.fov = parse_degree(token);
	free(token);
	token = next_token(line, ft_isspace);
	if (token)
		fatal_error("Too many arguments for camera");
}

// syntax: L [position] [brightness] [color]
static void	parse_light(const char **line, t_scene *scene)
{
	char	*token;
	t_light	*light;

	token = next_token(line, ft_isspace);
	if (!token)
		fatal_error("Missing light position");
	light = ft_xmalloc(sizeof(t_light));
	light->position = parse_vector_position(token);
	free(token);
	token = next_token(line, ft_isspace);
	if (!token)
		fatal_error("Missing light brightness");
	light->brightness = parse_positive_double(token);
	free(token);
	token = next_token(line, ft_isspace);
	if (!token)
		fatal_error("Missing light color");
	light->color = parse_color(token);
	free(token);
	token = next_token(line, ft_isspace);
	if (token)
		fatal_error("Too many arguments for light");
	ft_lstadd_back(&scene->lights, ft_xlstnew(light));
}

static void	parse_objects(const char *token, const char *line, t_scene *scene)
{
	if (ft_strcmp(token, "sp") == 0)
		parse_sphere(&line, scene);
	else if (ft_strcmp(token, "pl") == 0)
		parse_plane(&line, scene);
	else if (ft_strcmp(token, "cy") == 0)
		parse_cylinder(&line, scene);
	else if (ft_strcmp(token, "co") == 0)
		parse_cone(&line, scene);
	else
		fatal_error("Unknown object type");
}

void	parse_line(const char *line, t_scene *scene,
		t_object_count *object_count)
{
	char	*token;

	token = next_token(&line, ft_isspace);
	if (!token)
		return ;
	if (ft_strcmp(token, "A") == 0)
	{
		parse_ambient(&line, scene);
		object_count->ambient++;
	}
	else if (ft_strcmp(token, "C") == 0)
	{
		parse_camera(&line, scene);
		object_count->camera++;
	}
	else if (ft_strcmp(token, "L") == 0)
	{
		parse_light(&line, scene);
		object_count->light++;
	}
	else
		parse_objects(token, line, scene);
	free(token);
}
