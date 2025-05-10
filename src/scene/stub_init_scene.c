/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stub_init_scene.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:51:42 by reasuke           #+#    #+#             */
/*   Updated: 2025/05/10 22:02:05 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "scene.h"
#include "utils.h"

// TODO: delete this stub
void	stub_init_scene(t_scene *scene)
{
	scene->ambient.ratio = 0.1;
	scene->ambient.color = (t_rgb){{1, 1, 1}};
	scene->camera.position = (t_vec3){{0, 0, 1}};
	scene->camera.orientation = (t_vec3){{0, 0, -1}};
	scene->camera.fov = 70;
	scene->lights = NULL;
	scene->objects = NULL;
	if (stub_add_three_spheres(scene) == 0)
		fatal_error("Failed to add spheres");
	if (stub_add_lights(scene) == 0)
		fatal_error("Failed to add lights");
}
