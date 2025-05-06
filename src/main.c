/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:17:12 by yliu              #+#    #+#             */
/*   Updated: 2025/05/06 20:16:26 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "mlx_utils.h"

// TODO delete
static void	draw_circle(t_mlx_conf *mlx_conf)
{
	int	x;
	int	y;
	int	center_x;
	int	center_y;
	int	radius;

	radius = 50;
	center_x = WINDOW_WIDTH / 2;
	center_y = WINDOW_HEIGHT / 2;
	x = 0;
	while (x < WINDOW_WIDTH)
	{
		y = 0;
		while (y < WINDOW_HEIGHT)
		{
			if (pow(x - center_x, 2) + pow(y - center_y, 2) <= pow(radius, 2))
				plot_pixel(mlx_conf, x, y, 0xFF0000);
			y++;
		}
		x++;
	}
}

// TODO: delete
static void	draw_rectangle(t_mlx_conf *mlx_conf)
{
	int	x;
	int	y;

	x = 0;
	while (x < WINDOW_WIDTH)
	{
		y = 0;
		while (y < WINDOW_HEIGHT)
		{
			if (100 <= x && x <= 200 && 100 <= y && y <= 200)
				plot_pixel(mlx_conf, x, y, 0x00FF00);
			y++;
		}
		x++;
	}
}

// TODO: delete
void	draw_shapes(t_mlx_conf *mlx_conf)
{
	draw_circle(mlx_conf);
	draw_rectangle(mlx_conf);
	mlx_put_image_to_window(mlx_conf->mlx, mlx_conf->win, mlx_conf->img, 0, 0);
}

int	main(int argc, char **argv)
{
	t_mlx_conf	*mlx_conf;

	(void)argc;
	(void)argv;
	mlx_conf = construct_mlx_conf();
	handle_events(mlx_conf);
	draw_shapes(mlx_conf);
	mlx_loop(mlx_conf->mlx);
	return (0);
}
