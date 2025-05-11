/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 19:24:46 by yliu              #+#    #+#             */
/*   Updated: 2025/05/11 17:09:02 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// syntax: cy [center] [axis] [diameter] [height] [color]
static void	parse_cylinder_properties(const char **line, t_cylinder *cylinder)
{
	char	*token;

	token = next_token(line, ft_isspace);
	if (!token)
		fatal_error("Missing cylinder position");
	cylinder->center = parse_vector(token);
	free(token);
	token = next_token(line, ft_isspace);
	if (!token)
		fatal_error("Missing cylinder orientation");
	cylinder->axis = parse_vector(token);
	free(token);
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
	token = next_token(line, ft_isspace);
	if (!token)
		fatal_error("Missing cylinder color");
	cylinder->color = parse_color(token);
	free(token);
}

void	parse_cylinder(const char **line, t_scene *scene)
{
	t_cylinder	*cylinder;

	cylinder = malloc(sizeof(t_cylinder));
	if (!cylinder)
		fatal_error("Memory allocation failed for cylinder");
	parse_cylinder_properties(line, cylinder);
	if (next_token(line, ft_isspace))
		fatal_error("Too many arguments for cylinder");
	ft_lstadd_back(&scene->objects, ft_xlstnew(cylinder));
}

// syntax: co [apex] [axis] [diameter] [height] [color]
static void	parse_cone_properties(const char **line, t_cone *cone)
{
	char	*token;

	token = next_token(line, ft_isspace);
	if (!token)
		fatal_error("Missing cone position");
	cone->apex = parse_vector(token);
	free(token);
	token = next_token(line, ft_isspace);
	if (!token)
		fatal_error("Missing cone orientation");
	cone->axis = parse_vector(token);
	free(token);
	token = next_token(line, ft_isspace);
	if (!token)
		fatal_error("Missing cone diameter");
	cone->radius = parse_positive_double(token) / 2.0;
	free(token);
	token = next_token(line, ft_isspace);
	if (!token)
		fatal_error("Missing cone height");
	cone->height = parse_positive_double(token);
	free(token);
	token = next_token(line, ft_isspace);
	if (!token)
		fatal_error("Missing cone color");
	cone->color = parse_color(token);
	free(token);
}

void	parse_cone(const char **line, t_scene *scene)
{
	t_cone	*cone;

	cone = malloc(sizeof(t_cone));
	if (!cone)
		fatal_error("Memory allocation failed for cone");
	parse_cone_properties(line, cone);
	if (next_token(line, ft_isspace))
		fatal_error("Too many arguments for cone");
	ft_lstadd_back(&scene->objects, ft_xlstnew(cone));
}
