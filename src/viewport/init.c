/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 20:10:32 by reasuke           #+#    #+#             */
/*   Updated: 2025/05/10 15:32:46 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "mlx_utils.h"
#include "scene.h"
#include "viewport.h"

static t_vec3	select_world_up(t_camera camera)
{
	t_vec3	world_up;

	world_up = (t_vec3){{0, 1, 0}};
	if (vec3_is_parallel(camera.orientation, world_up))
		world_up = (t_vec3){{0, 0, 1}};
	return (world_up);
}

static double	degree_to_rad(t_degree deg)
{
	return (deg * M_PI / 180);
}

void	init_viewport(t_viewport *vp, t_camera camera)
{
	const t_vec3	fwd = vec3_normalize(camera.orientation);
	const t_vec3	center = vec3_add(camera.position, fwd);
	const double	aspect_ratio = (double)WINDOW_WIDTH / WINDOW_HEIGHT;
	const double	width = 2 * tan(degree_to_rad(camera.fov) / 2);
	const double	height = width / aspect_ratio;

	vp->dx = vec3_scale(
			vec3_normalize(vec3_cross(fwd, select_world_up(camera))),
			width / (WINDOW_WIDTH - 1)
			);
	vp->dy = vec3_scale(
			vec3_normalize(vec3_cross(fwd, vec3_normalize(vp->dx))),
			height / (WINDOW_HEIGHT - 1)
			);
	vp->origin = vec3_add(
			center, vec3_add(
				vec3_scale(vec3_normalize(vp->dx), -width / 2),
				vec3_scale(vec3_normalize(vp->dy), -height / 2)
				)
			);
}
