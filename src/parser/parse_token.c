/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 10:12:37 by yliu              #+#    #+#             */
/*   Updated: 2025/05/05 18:29:27 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

double	parse_ratio(const char *str)
{
	double	ratio;

	if (!is_double(str))
		exit_with_errmsg("Invalid format");
	ratio = ft_atof(str);
	if (ratio < 0.0 || ratio > 1.0)
		exit_with_errmsg("Invalid ratio value");
	return (ratio);
}

t_rgb	parse_color(const char *str)
{
	t_rgb	color;
	char	**result;

	if (!is_three_integer(str))
		exit_with_errmsg("Invalid color vector");
	result = ft_split(str, ',');
	if (!result)
		exit_with_errmsg("Memory allocation failed");
	color.x = ft_strtol(result[0], NULL, 10);
	color.y = ft_strtol(result[1], NULL, 10);
	color.z = ft_strtol(result[2], NULL, 10);
	if (color.x < 0 || color.x > 255 || color.y < 0 || color.y > 255
		|| color.z < 0 || color.z > 255)
		exit_with_errmsg("Color values must be in the range [0, 255]");
	free(result);
	return (color);
}

t_vec3	parse_vector(const char *str)
{
	t_vec3	vector;
	char	**result;

	if (!is_vec3(str))
		exit_with_errmsg("Invalid vector");
	result = ft_split(str, ',');
	if (!result)
		exit_with_errmsg("Memory allocation failed");
	vector.x = ft_atof(result[0]);
	if (errno == ERANGE)
		exit_with_errmsg("Vector value out of range");
	vector.y = ft_atof(result[1]);
	if (errno == ERANGE)
		exit_with_errmsg("Vector value out of range");
	vector.z = ft_atof(result[2]);
	if (errno == ERANGE)
		exit_with_errmsg("Vector value out of range");
	free(result);
	return (vector);
}

double	parse_positive_double(const char *str)
{
	double	value;

	if (!is_double(str))
		exit_with_errmsg("Invalid format");
	value = ft_atof(str);
	if (value <= 0.0)
		exit_with_errmsg("Value must be positive");
	return (value);
}

double	parse_degree(const char *str)
{
	double	degree;

	if (!is_double(str))
		exit_with_errmsg("Invalid format");
	degree = ft_atof(str);
	if (degree < 0.0 || degree > 180.0)
		exit_with_errmsg("Degree must be in the range [0, 180]");
	return (degree);
}
