/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:06:27 by reasuke           #+#    #+#             */
/*   Updated: 2025/05/18 17:44:33 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "libft.h"
#include "tracer.h"

#define SIDE 0
#define BOTTOM 1
#define TOP 2
#define CYLINDER_COMPONENTS 3

static t_disk	create_disk_from_cylinder(t_cylinder *cy, bool is_top)
{
	t_disk	disk;

	if (is_top)
	{
		disk.center = vec3_add(cy->center, vec3_scale(cy->axis, cy->height));
		disk.normal = cy->axis;
	}
	else
	{
		disk.center = cy->center;
		disk.normal = vec3_negate(cy->axis);
	}
	disk.normal = cy->axis;
	disk.radius = cy->radius;
	disk.color = cy->color;
	return (disk);
}

static bool	find_closest_hit( bool hit_results[], t_hit_record temp_records[],
				int count, int *min_index)
{
	bool	hit_found;
	int		i;
	double	min_t;

	hit_found = false;
	*min_index = -1;
	min_t = INFINITY;
	i = 0;
	while (i < count)
	{
		if (hit_results[i] && ft_fchmin(&min_t, temp_records[i].t))
		{
			*min_index = i;
			hit_found = true;
		}
		i++;
	}
	return (hit_found);
}

bool	intersect_cylinder(t_ray ray, t_cylinder *cy, t_hit_record *hit_record)
{
	t_hit_record	temp_records[CYLINDER_COMPONENTS];
	bool			hit_results[CYLINDER_COMPONENTS];
	int				min_index;

	ft_bzero(temp_records, sizeof(temp_records));
	cy->axis = vec3_normalize(cy->axis);
	hit_results[SIDE] = intersect_cylinder_side(ray, cy, &temp_records[SIDE]);
	hit_results[BOTTOM] = intersect_disk(ray,
			create_disk_from_cylinder(cy, false), &temp_records[BOTTOM]);
	hit_results[TOP] = intersect_disk(ray,
			create_disk_from_cylinder(cy, true), &temp_records[TOP]);
	if (find_closest_hit(
			hit_results, temp_records, CYLINDER_COMPONENTS, &min_index))
	{
		*hit_record = temp_records[min_index];
		return (true);
	}
	return (false);
}
