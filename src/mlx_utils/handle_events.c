/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:56:17 by reasuke           #+#    #+#             */
/*   Updated: 2025/05/06 19:29:15 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "mlx.h"
#include "mlx_utils.h"
#include "libft.h"

int	terminate_mlx(t_mlx_conf *mlx_conf)
{
	destroy_mlx_conf(mlx_conf);
	exit(EXIT_SUCCESS);
}

int	handle_keydown(int keycode, t_mlx_conf *mlx_conf)
{
	if (keycode == KEY_ESCAPE)
		terminate_mlx(mlx_conf);
	return (EXIT_SUCCESS);
}

void	handle_events(t_mlx_conf *mlx_conf)
{
	mlx_hook(mlx_conf->win, ON_KEYDOWN, KEY_PRESS_MASK, handle_keydown,
		mlx_conf);
	mlx_hook(mlx_conf->win, ON_DESTROY, NO_EVENT_MASK, terminate_mlx, mlx_conf);
}
