/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   component.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 20:14:31 by reasuke           #+#    #+#             */
/*   Updated: 2025/05/17 20:16:39 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/*
** Returns the component of vector `a` that is parallel to vector `b`.
*/
t_vec3	vec3_parallel_component(t_vec3 a, t_vec3 b)
{
	const double	dot = vec3_dot(a, b);
	const double	len_squared = vec3_dot(b, b);

	if (len_squared < EPSILON)
		return ((t_vec3){{0, 0, 0}});
	return (vec3_scale(b, dot / len_squared));
}

/*
** Returns the component of vector `a` that is perpendicular to vector `b`.
*/
t_vec3	vec3_perpendicular_component(t_vec3 a, t_vec3 b)
{
	return (vec3_sub(a, vec3_parallel_component(a, b)));
}
