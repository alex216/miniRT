/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 19:03:52 by yliu              #+#    #+#             */
/*   Updated: 2025/05/11 17:09:02 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// syntax: sp [point] [normal] [color]
void	parse_plane(const char **line, t_scene *scene)
{
	char	*token;
	t_plane	*plane;

	token = next_token(line, ft_isspace);
	if (!token)
		fatal_error("Missing plane position");
	plane = ft_xmalloc(sizeof(t_plane));
	plane->point = parse_vector(token);
	free(token);
	token = next_token(line, ft_isspace);
	if (!token)
		fatal_error("Missing plane normal");
	plane->normal = parse_vector(token);
	free(token);
	token = next_token(line, ft_isspace);
	if (!token)
		fatal_error("Missing plane color");
	plane->color = parse_color(token);
	free(token);
	token = next_token(line, ft_isspace);
	if (token)
		fatal_error("Too many arguments for plane");
	ft_lstadd_back(&scene->objects, ft_xlstnew(plane));
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
	sphere->center = parse_vector(token);
	free(token);
	token = next_token(line, ft_isspace);
	if (!token)
		fatal_error("Missing sphere diameter");
	sphere->radius = parse_positive_double(token) / 2.0;
	free(token);
	token = next_token(line, ft_isspace);
	if (!token)
		fatal_error("Missing sphere color");
	sphere->color = parse_color(token);
	free(token);
	token = next_token(line, ft_isspace);
	if (token)
		fatal_error("Too many arguments for sphere");
	ft_lstadd_back(&scene->objects, ft_xlstnew(sphere));
}
