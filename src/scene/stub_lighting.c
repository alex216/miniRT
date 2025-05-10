/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stub_lighting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 21:44:35 by reasuke           #+#    #+#             */
/*   Updated: 2025/05/10 21:52:21 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

#include "scene.h"

static t_light	*construct_light_data(t_vec3 position, t_rgb color,
								double brightness)
{
	t_light	*light;

	light = (t_light *)malloc(sizeof(t_light));
	if (light == NULL)
		return (NULL);
	light->position = position;
	light->color = color;
	light->brightness = brightness;
	return (light);
}

static int	add_light_to_scene(t_scene *scene, t_vec3 position, t_rgb color,
								double brightness)
{
	t_light	*light_data;
	t_list	*new_node;

	light_data = construct_light_data(position, color, brightness);
	if (light_data == NULL)
		return (0);
	new_node = ft_lstnew(light_data);
	if (new_node == NULL)
	{
		free(light_data);
		return (0);
	}
	ft_lstadd_back(&(scene->lights), new_node);
	return (1);
}

int	stub_add_lights(t_scene *scene)
{
	if (add_light_to_scene(scene, (t_vec3){{2.0, 2.0, 0.0}},
		(t_rgb){{1.0, 1.0, 1.0}}, 1.0) == 0)
		return (0);
	if (add_light_to_scene(scene, (t_vec3){{-2.0, 1.0, 2.0}},
		(t_rgb){{0.4, 0.4, 1.0}}, 0.6) == 0)
		return (0);
	if (add_light_to_scene(scene, (t_vec3){{0.0, -1.0, -2.0}},
		(t_rgb){{1.0, 0.8, 0.5}}, 0.4) == 0)
		return (0);
	return (1);
}
