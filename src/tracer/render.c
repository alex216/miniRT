/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 01:46:44 by reasuke           #+#    #+#             */
/*   Updated: 2025/05/10 17:00:12 by reasuke          ###   ########.fr       */
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

static int	rgb_to_int(t_rgb color)
{
	t_vec3	rgb_255;

	rgb_255 = vec3_scale(color, 255.999);
	return ((int)(rgb_255.x) << 16 | (int)(rgb_255.y) << 8 | (int)(rgb_255.z));
}

void	render(t_scene scene, t_mlx_conf *mlx_conf)
{
	t_viewport	vp;
	t_ray		ray;
	t_rgb		color;
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
			color = trace_ray(ray, scene);
			plot_pixel(mlx_conf, x, y, rgb_to_int(color));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx_conf->mlx, mlx_conf->win, mlx_conf->img, 0, 0);
}
