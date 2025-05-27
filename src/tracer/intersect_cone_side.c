/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cone_side.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 17:26:31 by reasuke           #+#    #+#             */
/*   Updated: 2025/05/27 22:17:49 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "tracer.h"

static bool	is_intersection_in_cone_height(t_ray ray, t_cone *cone, double t)
{
	const t_vec3	intersection
		= vec3_add(ray.origin, vec3_scale(ray.direction, t));
	const t_vec3	v = vec3_sub(intersection, cone->apex);
	const double	height_proj = vec3_dot(v, cone->axis);

	return (0 <= height_proj && height_proj <= cone->height);
}

static void	set_cone_side_record(
				t_ray ray, t_cone *cone, double t, t_hit_record *record)
{
	t_vec3	ap;
	double	proj_len;
	t_vec3	proj_point;
	t_vec3	radius_vec;
	t_vec3	g_hat;

	record->t = t;
	record->point = vec3_add(ray.origin, vec3_scale(ray.direction, t));
	record->color = cone->color;
	ap = vec3_sub(record->point, cone->apex);
	proj_len = vec3_dot(ap, cone->axis);
	proj_point = vec3_add(cone->apex, vec3_scale(cone->axis, proj_len));
	radius_vec = vec3_sub(record->point, proj_point);
	g_hat = vec3_normalize(ap);
	record->normal
		= vec3_normalize(vec3_perpendicular_component(radius_vec, g_hat));
}

static t_quadratic_coef	calc_cone_quadratic_coef(t_ray ray, t_cone *cone)
{
	const t_vec3	oc = vec3_sub(ray.origin, cone->apex);
	const double	cos2_theta = cone->height * cone->height
		/ (cone->height * cone->height + cone->radius * cone->radius);
	const double	dot_d_axis = vec3_dot(ray.direction, cone->axis);
	const double	dot_oc_axis = vec3_dot(oc, cone->axis);

	return ((t_quadratic_coef){
		.a = dot_d_axis * dot_d_axis
		- cos2_theta * vec3_dot(ray.direction, ray.direction),
		.b = 2.0 * (dot_d_axis * dot_oc_axis
			- cos2_theta * vec3_dot(ray.direction, oc)),
		.c = dot_oc_axis * dot_oc_axis - cos2_theta * vec3_dot(oc, oc)
	});
}

bool	intersect_cone_side(t_ray ray, t_cone *cone, t_hit_record *record)
{
	const t_quadratic_coef	qcoef = calc_cone_quadratic_coef(ray, cone);
	t_quadratic_result		qresult;

	if (fabs(qcoef.a) < EPSILON)
		return (false);
	if (!solve_quadratic(qcoef, &qresult))
		return (false);
	if (qresult.s1 >= RAY_T_MIN
		&& is_intersection_in_cone_height(ray, cone, qresult.s1))
	{
		set_cone_side_record(ray, cone, qresult.s1, record);
		return (true);
	}
	if (qresult.s2 >= RAY_T_MIN
		&& is_intersection_in_cone_height(ray, cone, qresult.s2))
	{
		set_cone_side_record(ray, cone, qresult.s2, record);
		return (true);
	}
	return (false);
}
