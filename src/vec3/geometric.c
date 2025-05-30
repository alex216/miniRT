/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 00:14:16 by reasuke           #+#    #+#             */
/*   Updated: 2025/05/11 22:10:04 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "vector.h"

double	vec3_dot(t_vec3 a, t_vec3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vec3	vec3_cross(t_vec3 a, t_vec3 b)
{
	return ((t_vec3){{a.y * b.z - a.z * b.y,
			a.z * b.x - a.x * b.z,
			a.x * b.y - a.y * b.x}});
}

t_vec3	vec3_normalize(t_vec3 a)
{
	double	len;

	len = vec3_length(a);
	if (len < EPSILON)
		return ((t_vec3){{0, 0, 0}});
	return (vec3_scale(a, 1 / len));
}

t_vec3	vec3_negate(t_vec3 a)
{
	return ((t_vec3){{-a.x, -a.y, -a.z}});
}

/*
** Reflects a vector `incident` off a surface with the given `normal`.
** Direction convention:
**
**           normal
**             ^
**  incident   |    reflected
**      \      |      ^
**       \     |     /
**        \    |    /
**         \   |   /
**          \  |  /
**           \ | /
**            v|/
** ------------------------- surface
*/
t_vec3	vec3_reflect(t_vec3 incident, t_vec3 normal)
{
	double	dot_product;

	dot_product = vec3_dot(incident, normal);
	return (vec3_sub(incident, vec3_scale(normal, 2 * dot_product)));
}
