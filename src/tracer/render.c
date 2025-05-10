/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 01:46:44 by reasuke           #+#    #+#             */
/*   Updated: 2025/05/10 16:35:10 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "mlx_utils.h"
#include "tracer.h"
#include "scene.h"
#include "viewport.h"

static t_vec3	calc_pixel_position(t_viewport vp, int x, int y)
{
	return (vec3_add(vp.origin, vec3_add(
				vec3_scale(vp.dx, x),
				vec3_scale(vp.dy, y)
			)));
}

t_ray	create_ray(t_camera cam, t_vec3 pixel)
{
	t_ray	ray;

	ray.origin = cam.position;
	ray.direction = vec3_normalize(vec3_sub(pixel, cam.position));
	return (ray);
}

void	render(t_scene scene, t_mlx_conf *mlx_conf)
{
	t_viewport	vp;
	t_ray		ray;
	int			x;
	int			y;

	init_viewport(&vp, scene.camera);
	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			ray = create_ray(scene.camera, calc_pixel_position(vp, x, y));
			(void)ray;
			plot_pixel(mlx_conf, x, y, 0x00FF00); // Placeholder color
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx_conf->mlx, mlx_conf->win, mlx_conf->img, 0, 0);
}
