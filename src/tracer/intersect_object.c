/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_object.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 20:39:24 by reasuke           #+#    #+#             */
/*   Updated: 2025/05/10 20:40:23 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>

#include "tracer.h"
#include "vector.h"

static bool	intersect_sphere(t_ray ray, t_sphere *sphere,
								t_hit_record *hit_record)
{
	const t_vec3	oc = vec3_sub(ray.origin, sphere->center);
	const double	a = vec3_dot(ray.direction, ray.direction);
	const double	half_b = vec3_dot(oc, ray.direction);
	const double	c = vec3_dot(oc, oc) - sphere->radius * sphere->radius;
	double			root;

	if (half_b * half_b - a * c < 0)
		return (false);
	root = (-half_b - sqrt(half_b * half_b - a * c)) / a;
	if (root < RAY_T_MIN)
		return (false);
	hit_record->t = root;
	hit_record->color = sphere->color;
	hit_record->point = vec3_add(ray.origin, vec3_scale(ray.direction, root));
	hit_record->normal = vec3_normalize(vec3_sub(hit_record->point,
				sphere->center));
	return (true);
}

bool	intersect_object(t_ray ray, t_object *obj, t_hit_record *hit_record)
{
	if (obj->type == SPHERE)
		return (intersect_sphere(ray, obj->data, hit_record));
	return (false);
}
