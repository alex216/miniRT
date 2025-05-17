/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 19:03:52 by yliu              #+#    #+#             */
/*   Updated: 2025/05/14 15:32:00 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_object	*create_plane_obj(t_plane *plane)
{
	t_object	*object;

	object = ft_xmalloc(sizeof(t_object));
	object->type = PLANE;
	object->data = plane;
	return (object);
}

// syntax: sp [point] [normal] [color]
void	parse_plane(const char **line, t_scene *scene)
{
	char		*token;
	t_plane		*plane;

	token = next_token(line, ft_isspace);
	if (!token)
		fatal_error("Missing plane position");
	plane = ft_xmalloc(sizeof(t_plane));
	plane->point = parse_vector_position(token);
	free(token);
	token = next_token(line, ft_isspace);
	if (!token)
		fatal_error("Missing plane normal");
	plane->normal = parse_vector_direction(token);
	free(token);
	token = next_token(line, ft_isspace);
	if (!token)
		fatal_error("Missing plane color");
	plane->color = vec3_scale(parse_color(token), 1.0 / 255.0);
	free(token);
	token = next_token(line, ft_isspace);
	if (token)
		fatal_error("Too many arguments for plane");
	ft_lstadd_back(&scene->objects, ft_lstnew(create_plane_obj(plane)));
}
