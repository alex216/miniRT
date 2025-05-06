/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:28:34 by yliu              #+#    #+#             */
/*   Updated: 2025/05/04 11:43:46 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"
#include "utils.h"
#include <errno.h>

// float.h is not arrowed (norminette 3.3.55)
#ifndef DBL_MAX
# define DBL_MAX __DBL_MAX__
#endif
#ifndef DBL_MIN
# define DBL_MIN __DBL_MIN__
#endif

static double	parse_integer_part(const char **str)
{
	double	result;

	result = 0.0;
	while (ft_isdigit(**str))
	{
		result = result * 10.0 + (**str - '0');
		if (result > (DBL_MAX - **str - '0') / 10)
		{
			errno = ERANGE;
			return (0);
		}
		(*str)++;
	}
	return (result);
}

static double	parse_fractional_part(const char **str)
{
	double	fraction;
	double	divisor;

	fraction = 0.0;
	divisor = 1.0;
	if (**str == '.')
	{
		(*str)++;
		while (ft_isdigit(**str))
		{
			fraction = fraction * 10.0 + (**str - '0');
			divisor *= 10.0;
			(*str)++;
		}
	}
	return (fraction / divisor);
}

static int	parse_sign(char **str)
{
	int	sign;

	sign = 1;
	if (**str == '+' || **str == '-')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	return (sign);
}

// [x] scientific notation
// [x] overflow
// [x] underflow
double	ft_atof(const char *src)
{
	double	result;
	char	*str;
	char	*origin_str;
	int		sign;

	sign = 1;
	str = ft_strtrim(src, " \t\n");
	origin_str = str;
	if (!str)
		return (0.0);
	sign = parse_sign(&str);
	result = parse_integer_part((const char **)&str);
	if (errno == ERANGE)
	{
		free(origin_str);
		return (sign * DBL_MAX);
	}
	result += parse_fractional_part((const char **)&str);
	free(origin_str);
	return (sign * result);
}
