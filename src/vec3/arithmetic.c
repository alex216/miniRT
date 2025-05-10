/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arithmetic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 00:13:53 by reasuke           #+#    #+#             */
/*   Updated: 2025/05/10 21:55:51 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <math.h>

#include "vector.h"

t_vec3	vec3_add(t_vec3 a, t_vec3 b)
{
	return ((t_vec3){{a.x + b.x, a.y + b.y, a.z + b.z}});
}

t_vec3	vec3_sub(t_vec3 a, t_vec3 b)
{
	return ((t_vec3){{a.x - b.x, a.y - b.y, a.z - b.z}});
}

t_vec3	vec3_hadamard(t_vec3 a, t_vec3 b)
{
	return ((t_vec3){{a.x * b.x, a.y * b.y, a.z * b.z}});
}

t_vec3	vec3_scale(t_vec3 a, double s)
{
	return ((t_vec3){{a.x * s, a.y * s, a.z * s}});
}

t_vec3	vec3_clump(t_vec3 a, double min, double max)
{
	return ((t_vec3){{fmax(min, fmin(a.x, max)),
			fmax(min, fmin(a.y, max)),
			fmax(min, fmin(a.z, max))}});
}
