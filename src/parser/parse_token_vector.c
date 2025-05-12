/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_token_vector.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:13:55 by yliu              #+#    #+#             */
/*   Updated: 2025/05/12 16:14:39 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_rgb	parse_color(const char *str)
{
	t_rgb	color;
	char	**result;

	if (!is_three_integer(str))
		fatal_error("Invalid color vector");
	result = ft_split(str, ',');
	if (!result)
		fatal_error("Memory allocation failed");
	color.x = ft_strtol(result[0], NULL, 10);
	color.y = ft_strtol(result[1], NULL, 10);
	color.z = ft_strtol(result[2], NULL, 10);
	if (color.x < 0 || color.x > 255 || color.y < 0 || color.y > 255
		|| color.z < 0 || color.z > 255)
		fatal_error("Color values must be in the range [0, 255]");
	free(result);
	return (color);
}

static t_vec3	parse_vector_internal(const char *str, const double min,
		const double max)
{
	t_vec3	vector;
	char	**result;

	if (!is_vec3(str))
		fatal_error("Invalid vector");
	result = ft_split(str, ',');
	if (!result)
		fatal_error("Memory allocation failed");
	vector.x = ft_atof(result[0]);
	if (errno == ERANGE || vector.x < min || vector.x > max)
		fatal_error("Vector value out of range");
	vector.y = ft_atof(result[1]);
	if (errno == ERANGE || vector.y < min || vector.y > max)
		fatal_error("Vector value out of range");
	vector.z = ft_atof(result[2]);
	if (errno == ERANGE || vector.z < min || vector.z > max)
		fatal_error("Vector value out of range");
	free(result);
	return (vector);
}

t_vec3	parse_vector_direction(const char *str)
{
	return (parse_vector_internal(str, -1.0, 1.0));
}

t_vec3	parse_vector_position(const char *str)
{
	return (parse_vector_internal(str, -INFINITY, INFINITY));
}
