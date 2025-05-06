/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:30:40 by reasuke           #+#    #+#             */
/*   Updated: 2025/05/06 18:54:24 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include <string.h>

#include "mlx_utils.h"
#include "utils.h"

static void	init_mlx(t_mlx_conf *mlx_conf)
{
	mlx_conf->mlx = mlx_init();
	if (mlx_conf->mlx == NULL)
		fatal_error("mlx_init() failed");
}

static void	init_window(t_mlx_conf *mlx_conf)
{
	mlx_conf->win = mlx_new_window(mlx_conf->mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
	if (mlx_conf->win == NULL)
		fatal_error("mlx_new_window() failed");
}

static void	init_image(t_mlx_conf *mlx_conf)
{
	mlx_conf->img = mlx_new_image(mlx_conf->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (mlx_conf->img == NULL)
		fatal_error("mlx_new_image() failed");
}

static void	init_data(t_mlx_conf *mlx_conf)
{
	mlx_conf->data = mlx_get_data_addr(mlx_conf->img,
			&mlx_conf->bits_per_pixel, &mlx_conf->line_length,
			&mlx_conf->endian);
	if (mlx_conf->data == NULL)
		fatal_error("mlx_get_data_addr() failed");
}

t_mlx_conf	*construct_mlx_conf(void)
{
	t_mlx_conf	*mlx_conf;

	mlx_conf = malloc(sizeof(t_mlx_conf));
	if (mlx_conf == NULL)
		fatal_error(strerror(errno));
	init_mlx(mlx_conf);
	init_window(mlx_conf);
	init_image(mlx_conf);
	init_data(mlx_conf);
	return (mlx_conf);
}
