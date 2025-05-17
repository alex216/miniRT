/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj_cone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 19:24:46 by yliu              #+#    #+#             */
/*   Updated: 2025/05/14 15:31:55 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	parse_cone_position_orientation(const char **line, t_cone *cone)
{
	char	*token;

	token = next_token(line, ft_isspace);
	if (!token)
		fatal_error("Missing cone position");
	cone->apex = parse_vector_position(token);
	free(token);
	token = next_token(line, ft_isspace);
	if (!token)
		fatal_error("Missing cone orientation");
	cone->axis = parse_vector_direction(token);
	free(token);
}

static void	parse_cone_dimensions_color(const char **line, t_cone *cone)
{
	char	*token;

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
	cone->color = vec3_scale(parse_color(token), 1.0 / 255.0);
	free(token);
}

// syntax: co [center] [axis] [diameter] [height] [color]
void	parse_cone(const char **line, t_scene *scene)
{
	t_cone		*cone;
	t_object	*object;

	cone = malloc(sizeof(t_cone));
	if (!cone)
		fatal_error("Memory allocation failed for cone");
	parse_cone_position_orientation(line, cone);
	parse_cone_dimensions_color(line, cone);
	if (next_token(line, ft_isspace))
		fatal_error("Too many arguments for cone");
	object = ft_xmalloc(sizeof(t_object));
	object->type = CONE;
	object->data = cone;
	ft_lstadd_back(&scene->objects, ft_xlstnew(object));
}
