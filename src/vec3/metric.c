/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metric.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 23:40:06 by reasuke           #+#    #+#             */
/*   Updated: 2025/05/10 23:41:04 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "vector.h"

bool	vec3_is_parallel(t_vec3 a, t_vec3 b)
{
	t_vec3	cross;

	cross = vec3_cross(a, b);
	return (vec3_length(cross) < EPSILON);
}

double	vec3_length(t_vec3 a)
{
	return (sqrt(vec3_dot(a, a)));
}
