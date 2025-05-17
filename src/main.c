/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:17:12 by yliu              #+#    #+#             */
/*   Updated: 2025/05/17 22:10:34 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"
#include "scene.h"
#include "tracer.h"
#include "parser.h"

int	main(int argc, char **argv)
{
	t_mlx_conf	*mlx_conf;
	t_scene		scene;

	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./miniRT <scene_file>\n", 2);
		return (1);
	}
	mlx_conf = construct_mlx_conf();
	ft_bzero(&scene, sizeof(t_scene));
	parse_scene(&scene, argv[1]);
	handle_events(mlx_conf);
	render(scene, mlx_conf);
	mlx_loop(mlx_conf->mlx);
	return (0);
}
