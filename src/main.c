/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:17:12 by yliu              #+#    #+#             */
/*   Updated: 2025/05/10 16:30:14 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "mlx_utils.h"
#include "scene.h"
#include "tracer.h"
#include "utils.h"

static t_sphere	*construct_sphere_data(t_vec3 center, double radius,
										t_rgb color)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	if (sphere == NULL)
		return (NULL);
	sphere->center = center;
	sphere->radius = radius;
	sphere->color = color;
	return (sphere);
}

static t_object	*construct_object(t_object_type type, void *data)
{
	t_object	*obj;

	obj = (t_object *)malloc(sizeof(t_object));
	if (obj == NULL)
		return (NULL);
	obj->type = type;
	obj->data = data;
	return (obj);
}

static int	add_red_sphere(t_scene *scene)
{
	t_sphere	*sphere_data;
	t_object	*sphere_obj;

	sphere_data = construct_sphere_data(
			(t_vec3){{0, 0, -1}},
			0.5,
			(t_rgb){{1.0, 0.2, 0.2}}
			);
	if (sphere_data == NULL)
		return (0);
	sphere_obj = construct_object(SPHERE, sphere_data);
	if (sphere_obj == NULL)
	{
		free(sphere_data);
		return (0);
	}
	scene->objects = ft_lstnew(sphere_obj);
	if (scene->objects == NULL)
	{
		free(sphere_data);
		free(sphere_obj);
		return (0);
	}
	return (1);
}

// TODO: delete this stub
void	stub_init_scene(t_scene *scene)
{
	scene->ambient.ratio = 0.5;
	scene->ambient.color = (t_rgb){{1, 1, 1}};
	scene->camera.position = (t_vec3){{0, 0, 1}};
	scene->camera.orientation = (t_vec3){{0, 0, -1}};
	scene->camera.fov = 90;
	scene->lights = NULL;
	scene->objects = NULL;
	if (add_red_sphere(scene) == 0)
		fatal_error("Failed to add red sphere");
}

int	main(int argc, char **argv)
{
	t_mlx_conf	*mlx_conf;
	t_scene		scene;

	(void)argc;
	(void)argv;
	mlx_conf = construct_mlx_conf();
	stub_init_scene(&scene);
	handle_events(mlx_conf);
	render(scene, mlx_conf);
	mlx_loop(mlx_conf->mlx);
	return (0);
}
