/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destructor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:42:22 by reasuke           #+#    #+#             */
/*   Updated: 2025/05/06 19:29:17 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "mlx_utils.h"

void	destroy_mlx_conf(t_mlx_conf *mlx_conf)
{
	if (mlx_conf == NULL)
		return ;
	mlx_destroy_image(mlx_conf->mlx, mlx_conf->img);
	mlx_destroy_window(mlx_conf->mlx, mlx_conf->win);
	free(mlx_conf);
}
