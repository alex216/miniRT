/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stub.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:51:42 by reasuke           #+#    #+#             */
/*   Updated: 2025/05/10 17:56:23 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "scene.h"
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

static int	add_sphere_to_scene(t_scene *scene, t_vec3 center, double radius,
								t_rgb color)
{
	t_sphere	*sphere_data;
	t_object	*sphere_obj;
	t_list		*new_node;

	sphere_data = construct_sphere_data(center, radius, color);
	if (sphere_data == NULL)
		return (0);
	sphere_obj = construct_object(SPHERE, sphere_data);
	if (sphere_obj == NULL)
	{
		free(sphere_data);
		return (0);
	}
	new_node = ft_lstnew(sphere_obj);
	if (new_node == NULL)
	{
		free(sphere_data);
		free(sphere_obj);
		return (0);
	}
	ft_lstadd_back(&(scene->objects), new_node);
	return (1);
}

static int	add_three_spheres(t_scene *scene)
{
	if (add_sphere_to_scene(scene, (t_vec3){{0, 0.2, -1}}, 0.5,
		(t_rgb){{1.0, 0.2, 0.2}}) == 0)
		return (0);
	if (add_sphere_to_scene(scene, (t_vec3){{-1.0, 0, -3}}, 0.5,
		(t_rgb){{0.2, 0.2, 1.0}}) == 0)
		return (0);
	if (add_sphere_to_scene(scene, (t_vec3){{1.0, 0.5, -2}}, 0.5,
		(t_rgb){{0.2, 1.0, 0.2}}) == 0)
		return (0);
	return (1);
}

// TODO: delete this stub
void	stub_init_scene(t_scene *scene)
{
	scene->ambient.ratio = 0.5;
	scene->ambient.color = (t_rgb){{1, 1, 1}};
	scene->camera.position = (t_vec3){{0, 0, 1}};
	scene->camera.orientation = (t_vec3){{0, 0, -1}};
	scene->camera.fov = 70;
	scene->lights = NULL;
	scene->objects = NULL;
	if (add_three_spheres(scene) == 0)
		fatal_error("Failed to add spheres");
}
