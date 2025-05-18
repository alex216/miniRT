/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:17:12 by yliu              #+#    #+#             */
/*   Updated: 2025/05/18 19:58:39 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"
#include "scene.h"
#include "tracer.h"
#include "parser.h"

static void	validate_input(int argc, char **argv)
{
	if (argc != 2)
		fatal_error("Error: Incorrect number of arguments.\n");
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 3, ".rt", 3) != 0)
		fatal_error("Error: Invalid file extension. Expected .rt\n");
}

int	main(int argc, char **argv)
{
	t_mlx_conf	*mlx_conf;
	t_scene		scene;

	validate_input(argc, argv);
	mlx_conf = construct_mlx_conf();
	ft_bzero(&scene, sizeof(t_scene));
	parse_scene(&scene, argv[1]);
	handle_events(mlx_conf);
	render(scene, mlx_conf);
	mlx_loop(mlx_conf->mlx);
	return (0);
}
