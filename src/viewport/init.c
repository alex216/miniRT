/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 20:10:32 by reasuke           #+#    #+#             */
/*   Updated: 2025/05/09 00:40:01 by reasuke          ###   ########.fr       */
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
	t_vec3	fwd;
	t_vec3	center;
	double	aspect_ratio;
	t_vec3	right_dir;
	t_vec3	down_dir;

	fwd = vec3_normalize(camera.orientation);
	center = vec3_add(camera.position, fwd);
	aspect_ratio = (double)WINDOW_WIDTH / WINDOW_HEIGHT;
	vp->width = 2 * tan(degree_to_rad(camera.fov) / 2);
	vp->height = vp->width / aspect_ratio;
	right_dir = vec3_normalize(vec3_cross(fwd, select_world_up(camera)));
	down_dir = vec3_normalize(vec3_cross(fwd, right_dir));
	vp->origin = vec3_add(center, vec3_add(
				vec3_scale(right_dir, -vp->width / 2),
				vec3_scale(down_dir, -vp->height / 2)));
	vp->right = vec3_scale(right_dir, vp->width / (WINDOW_WIDTH - 1));
	vp->down = vec3_scale(down_dir, vp->height / (WINDOW_HEIGHT - 1));
}
