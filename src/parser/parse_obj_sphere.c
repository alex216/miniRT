/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:51:42 by yliu              #+#    #+#             */
/*   Updated: 2025/05/14 15:30:47 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_object	*create_sphere_obj(t_sphere *sphere)
{
	t_object	*object;

	object = ft_xmalloc(sizeof(t_object));
	object->type = SPHERE;
	object->data = sphere;
	return (object);
}

// syntax: sp [center] [diameter] [color]
void	parse_sphere(const char **line, t_scene *scene)
{
	char		*token;
	t_sphere	*sphere;

	token = next_token(line, ft_isspace);
	if (!token)
		fatal_error("Missing sphere position");
	sphere = ft_xmalloc(sizeof(t_sphere));
	sphere->center = parse_vector_position(token);
	free(token);
	token = next_token(line, ft_isspace);
	if (!token)
		fatal_error("Missing sphere diameter");
	sphere->radius = parse_positive_double(token) / 2.0;
	free(token);
	token = next_token(line, ft_isspace);
	if (!token)
		fatal_error("Missing sphere color");
	sphere->color = vec3_scale(parse_color(token), 1.0 / 255.0);
	free(token);
	token = next_token(line, ft_isspace);
	if (token)
		fatal_error("Too many arguments for sphere");
	ft_lstadd_back(&scene->objects, ft_lstnew(create_sphere_obj(sphere)));
}
