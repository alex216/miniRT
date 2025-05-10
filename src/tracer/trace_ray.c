/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:59:52 by reasuke           #+#    #+#             */
/*   Updated: 2025/05/10 17:47:32 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <math.h>

#include "tracer.h"

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

static bool	intersect_object(t_ray ray, t_object *obj, t_hit_record *hit_record)
{
	if (obj->type == SPHERE)
		return (intersect_sphere(ray, obj->data, hit_record));
	return (false);
}

t_rgb	trace_ray(t_ray ray, t_scene scene)
{
	t_list			*list_obj;
	t_hit_record	hit_record;
	t_rgb			color;
	double			min_t;

	list_obj = scene.objects;
	color = (t_rgb){{0, 0, 0}};
	min_t = INFINITY;
	while (list_obj)
	{
		if (intersect_object(ray, list_obj->content, &hit_record))
		{
			if (ft_fchmin(&min_t, hit_record.t))
				color = hit_record.color;
		}
		list_obj = list_obj->next;
	}
	return (color);
}
