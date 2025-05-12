/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 10:12:37 by yliu              #+#    #+#             */
/*   Updated: 2025/05/12 16:14:34 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

double	parse_ratio(const char *str)
{
	double	ratio;

	if (!is_double(str))
		fatal_error("Invalid format");
	ratio = ft_atof(str);
	if (ratio < 0.0 || ratio > 1.0)
		fatal_error("Invalid ratio value");
	return (ratio);
}

double	parse_positive_double(const char *str)
{
	double	value;

	if (!is_double(str))
		fatal_error("Invalid format");
	value = ft_atof(str);
	if (value <= 0.0)
		fatal_error("Value must be positive");
	return (value);
}

double	parse_degree(const char *str)
{
	double	degree;

	if (!is_double(str))
		fatal_error("Invalid format");
	degree = ft_atof(str);
	if (degree < 0.0 || degree > 180.0)
		fatal_error("Degree must be in the range [0, 180]");
	return (degree);
}
