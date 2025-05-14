/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:17:12 by yliu              #+#    #+#             */
/*   Updated: 2025/05/14 15:02:24 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"
#include "scene.h"
#include "tracer.h"
#include "parser.h"

static void	init_scene(t_scene *scene)
{
	scene->lights = NULL;
	scene->objects = NULL;
}

int	main(int argc, char **argv)
{
	t_mlx_conf	*mlx_conf;
	t_scene		scene;

	(void)argc;
	(void)argv;
	mlx_conf = construct_mlx_conf();
	init_scene(&scene);
	parse_scene(&scene, argv[1]);
	handle_events(mlx_conf);
	render(scene, mlx_conf);
	mlx_loop(mlx_conf->mlx);
	return (0);
}
