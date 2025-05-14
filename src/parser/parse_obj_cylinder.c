/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:14:01 by yliu              #+#    #+#             */
/*   Updated: 2025/05/14 15:31:32 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	parse_cylinder_position(const char **line, t_cylinder *cylinder)
{
	char	*token;

	token = next_token(line, ft_isspace);
	if (!token)
		fatal_error("Missing cylinder position");
	cylinder->center = parse_vector_position(token);
	free(token);
}

static void	parse_cylinder_orientation(const char **line, t_cylinder *cylinder)
{
	char	*token;

	token = next_token(line, ft_isspace);
	if (!token)
		fatal_error("Missing cylinder orientation");
	cylinder->axis = parse_vector_direction(token);
	free(token);
}

static void	parse_cylinder_size(const char **line, t_cylinder *cylinder)
{
	char	*token;

	token = next_token(line, ft_isspace);
	if (!token)
		fatal_error("Missing cylinder diameter");
	cylinder->radius = parse_positive_double(token) / 2.0;
	free(token);
	token = next_token(line, ft_isspace);
	if (!token)
		fatal_error("Missing cylinder height");
	cylinder->height = parse_positive_double(token);
	free(token);
}

static void	parse_cylinder_color(const char **line, t_cylinder *cylinder)
{
	char	*token;

	token = next_token(line, ft_isspace);
	if (!token)
		fatal_error("Missing cylinder color");
	cylinder->color = vec3_scale(parse_color(token), 1.0 / 255.0);
	free(token);
}

// syntax: cy [center] [axis] [diameter] [height] [color]
void	parse_cylinder(const char **line, t_scene *scene)
{
	t_cylinder	*cylinder;
	t_object	*object;

	cylinder = malloc(sizeof(t_cylinder));
	if (!cylinder)
		fatal_error("Memory allocation failed for cylinder");
	parse_cylinder_position(line, cylinder);
	parse_cylinder_orientation(line, cylinder);
	parse_cylinder_size(line, cylinder);
	parse_cylinder_color(line, cylinder);
	if (next_token(line, ft_isspace))
		fatal_error("Too many arguments for cylinder");
	object = ft_xmalloc(sizeof(t_object));
	object->type = CYLINDER;
	object->data = cylinder;
	ft_lstadd_back(&scene->objects, ft_xlstnew(object));
}
