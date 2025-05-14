/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_token_scalar.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 10:12:37 by yliu              #+#    #+#             */
/*   Updated: 2025/05/14 15:51:42 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static double	parse_double_internal(const char *str, double min, double max)
{
	double	value;

	if (!is_double(str))
		fatal_error("Invalid format");
	value = ft_atof(str);
	if (value < min || value > max)
	{
		errno = ERANGE;
		return (0.0);
	}
	return (value);
}

double	parse_brightness(const char *str)
{
	double	value;

	value = parse_double_internal(str, 0.0, 1.0);
	if (errno == ERANGE)
		fatal_error("Invalid brightness value");
	return (value);
}

double	parse_ratio(const char *str)
{
	double	value;

	value = parse_double_internal(str, 0.0, 1.0);
	if (errno == ERANGE)
		fatal_error("Invalid ratio value");
	return (value);
}

double	parse_positive_double(const char *str)
{
	double	value;

	value = parse_double_internal(str, 0.0, INFINITY);
	if (errno == ERANGE || value == 0.0)
		fatal_error("Invalid positive value");
	return (value);
}

double	parse_degree(const char *str)
{
	double	value;

	value = parse_double_internal(str, 0.0, 180.0);
	if (errno == ERANGE)
		fatal_error("Invalid degree value");
	return (value);
}
