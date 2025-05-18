/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 16:55:58 by reasuke           #+#    #+#             */
/*   Updated: 2025/05/18 18:00:55 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tracer.h"

#define CONE_COMPONENTS 2
#define SIDE 0
#define BASE 1

static t_disk	create_disk_from_cone(t_cone *cone)
{
	return ((t_disk){
		.center = vec3_add(cone->apex, vec3_scale(cone->axis, cone->height)),
		.normal = vec3_negate(cone->axis),
		.radius = cone->radius,
		.color = cone->color,
	});
}

bool	intersect_cone(t_ray ray, t_cone *cone, t_hit_record *hit_record)
{
	t_hit_record	temp_records[CONE_COMPONENTS];
	bool			hit_results[CONE_COMPONENTS];
	int				min_index;
	t_disk			base_disk;

	cone->axis = vec3_normalize(cone->axis);
	base_disk = create_disk_from_cone(cone);
	ft_bzero(temp_records, sizeof(temp_records));
	hit_results[SIDE] = intersect_cone_side(ray, cone, &temp_records[SIDE]);
	hit_results[BASE] = intersect_disk(ray, base_disk, &temp_records[BASE]);
	if (find_closest_hit(
			hit_results, temp_records, CONE_COMPONENTS, &min_index))
	{
		*hit_record = temp_records[min_index];
		return (true);
	}
	return (false);
}
