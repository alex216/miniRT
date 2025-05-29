/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:59:52 by reasuke           #+#    #+#             */
/*   Updated: 2025/05/29 16:46:32 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "libft.h"
#include "tracer.h"
#define RADIUS 0.6

__attribute__((unused))
static void update_ray(t_ray *ray, t_hit_record *hit_record)
{

	ray->direction = vec3_reflect(ray->direction, hit_record->normal);
	ray->origin = hit_record->point;
}

#include <stdlib.h>
t_rgb	trace_ray(t_ray ray, t_scene scene)
{
	t_list			*list_obj;
	t_hit_record	hit_record;
	t_hit_record	closest_hit;
	bool			hit_anything;
	double			min_t;
	t_sphere		*sphere;

	list_obj = scene.objects;
	min_t = INFINITY;
	hit_anything = false;
	while (list_obj)
	{
		if (intersect_object(ray, list_obj->content, &hit_record))
		{
			if (get_object_type(list_obj) == SPHERE)
			{
				sphere = get_sphere_data(list_obj);
				if (sphere->radius == RADIUS)
				{
					update_ray(&ray, &hit_record);
					return (trace_ray(ray, scene));
				}
			}
			if (ft_fchmin(&min_t, hit_record.t))
			{
				hit_anything = true;
				closest_hit = hit_record;
			}
		}
		list_obj = list_obj->next;
	}
	if (hit_anything)
		return (calc_lighting(closest_hit, scene, ray));
	else
		return ((t_rgb){{0, 0, 0}});
}
