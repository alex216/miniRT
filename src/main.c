/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:17:12 by yliu              #+#    #+#             */
/*   Updated: 2025/05/06 19:22:15 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"

int	main(int argc, char **argv)
{
	t_mlx_conf	*mlx_conf;

	(void)argc;
	(void)argv;
	mlx_conf = construct_mlx_conf();
	handle_events(mlx_conf);
	mlx_loop(mlx_conf->mlx);
	return (0);
}
