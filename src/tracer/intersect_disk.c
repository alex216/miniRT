/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_disk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 21:02:21 by reasuke           #+#    #+#             */
/*   Updated: 2025/05/17 21:02:31 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracer.h"
#include "vector.h"

/*
** Note: This implementation assumes that the point returned by intersect_plane
** is precisely on the plane. In theory, this means radius_vec should have no
** component in the normal direction. If precision issues arise,
** consider explicitly projecting the vector onto the disk plane.
*/
bool	intersect_disk(t_ray ray, t_disk disk, t_hit_record *record)
{
	t_plane	plane;
	t_vec3	radius_vec;

	plane = (t_plane){disk.center, disk.normal, disk.color};
	if (!intersect_plane(ray, &plane, record))
		return (false);
	radius_vec = vec3_sub(record->point, disk.center);
	if (vec3_dot(radius_vec, radius_vec) > disk.radius * disk.radius)
		return (false);
	return (true);
}
