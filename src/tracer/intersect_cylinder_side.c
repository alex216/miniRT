/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder_side.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:34:36 by reasuke           #+#    #+#             */
/*   Updated: 2025/05/17 21:18:49 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracer.h"
#include "vector.h"

t_quadratic_coef	calc_quadratic_coef(t_ray ray, t_cylinder *cy)
{
	const t_vec3	w = vec3_sub(ray.origin, cy->center);
	const t_vec3	m = vec3_perpendicular_component(ray.direction, cy->axis);
	const t_vec3	v = vec3_perpendicular_component(w, cy->axis);

	return ((t_quadratic_coef){
		.a = vec3_dot(m, m),
		.b = 2.0 * vec3_dot(v, m),
		.c = vec3_dot(v, v) - cy->radius * cy->radius,
	});
}

bool	is_intersection_in_cylinder_height(t_ray ray, t_cylinder *cy, double t)
{
	const double	dot_d_axis = vec3_dot(ray.direction, cy->axis);
	const double	dot_w_axis
		= vec3_dot(vec3_sub(ray.origin, cy->center), cy->axis);
	const double	height = dot_w_axis + t * dot_d_axis;

	return (0 < height && height < cy->height);
}

void	set_cylinder_side_record(t_ray ray, t_cylinder *cy, double t,
			t_hit_record *record)
{
	record->t = t;
	record->point = vec3_add(ray.origin, vec3_scale(ray.direction, t));
	record->normal = vec3_normalize(vec3_perpendicular_component(
				vec3_sub(record->point, cy->center), cy->axis));
	record->color = cy->color;
}

bool	intersect_cylinder_side(t_ray ray, t_cylinder *cy, t_hit_record *record)
{
	t_quadratic_coef	qcoef;
	t_quadratic_result	qresult;

	qcoef = calc_quadratic_coef(ray, cy);
	if (qcoef.a < EPSILON)
		return (false);
	if (!solve_quadratic(qcoef, &qresult))
		return (false);
	if (qresult.s1 < RAY_T_MIN)
		return (false);
	if (is_intersection_in_cylinder_height(ray, cy, qresult.s1))
	{
		set_cylinder_side_record(ray, cy, qresult.s1, record);
		return (true);
	}
	if (is_intersection_in_cylinder_height(ray, cy, qresult.s2))
	{
		set_cylinder_side_record(ray, cy, qresult.s2, record);
		return (true);
	}
	return (false);
}
