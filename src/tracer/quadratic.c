/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadratic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 20:04:19 by reasuke           #+#    #+#             */
/*   Updated: 2025/05/27 21:24:31 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <math.h>

#include "libft.h"
#include "tracer.h"

bool	solve_quadratic(t_quadratic_coef coef, t_quadratic_result *result)
{
	double	discriminant;

	discriminant = coef.b * coef.b - 4.0 * coef.a * coef.c;
	if (discriminant < EPSILON)
		return (false);
	result->s1 = (-coef.b - sqrt(discriminant)) / (2.0 * coef.a);
	result->s2 = (-coef.b + sqrt(discriminant)) / (2.0 * coef.a);
	if (result->s1 > result->s2)
		ft_fswap(&result->s1, &result->s2);
	return (true);
}
