/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:59:52 by reasuke           #+#    #+#             */
/*   Updated: 2025/05/11 22:25:56 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "libft.h"
#include "tracer.h"

t_rgb	trace_ray(t_ray ray, t_scene scene)
{
	t_list			*list_obj;
	t_hit_record	hit_record;
	t_hit_record	closest_hit;
	bool			hit_anything;
	double			min_t;

	list_obj = scene.objects;
	min_t = INFINITY;
	hit_anything = false;
	while (list_obj)
	{
		if (intersect_object(ray, list_obj->content, &hit_record))
		{
			if (ft_fchmin(&min_t, hit_record.t))
			{
				hit_anything = true;
				closest_hit = hit_record;
			}
		}
		list_obj = list_obj->next;
	}
	if (hit_anything)
		return (calc_lighting(closest_hit, scene));
	else
		return ((t_rgb){{0, 0, 0}});
}
