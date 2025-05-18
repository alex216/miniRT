/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:17:12 by yliu              #+#    #+#             */
/*   Updated: 2025/05/18 14:03:10 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"
#include "scene.h"
#include "tracer.h"
#include "parser.h"


void add_emmisive_material(t_scene *scene, t_sphere *data)
{
	double theta;
	double phi;

	theta = 0;
	while (theta < 360)
	{
		phi = 0;
		while (phi < 180)
		{
			double sin_theta = sin(theta * M_PI / 180.0);
			double cos_theta = cos(theta * M_PI / 180.0);
			double sin_phi = sin(phi * M_PI / 180.0);
			double cos_phi = cos(phi * M_PI / 180.0);

			t_vec3 position = vec3_normalize((t_vec3){{
				data->radius * sin_theta * cos_phi,
				data->radius * sin_theta * sin_phi,
				data->radius * cos_theta
			}});

			t_light *light = ft_xmalloc(sizeof(t_light));
			light->position = vec3_add(data->center, vec3_scale(position, 1.11 * data->radius));
			light->color = data->color;
			light->brightness = 0.01;
			ft_lstadd_back(&scene->lights, ft_lstnew(light));
			phi += 10;
		}
		theta += 10;
	}
}

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
	add_emmisive_material(&scene, (t_sphere *)((t_object *)((scene.objects)->next->next->content))->data);
	handle_events(mlx_conf);
	render(scene, mlx_conf);
	mlx_loop(mlx_conf->mlx);
	return (0);
}
