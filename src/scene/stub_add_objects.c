/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stub_add_objects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 21:42:25 by reasuke           #+#    #+#             */
/*   Updated: 2025/05/11 00:12:28 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "scene.h"
#include "utils.h"

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

static int	add_plane_to_scene(t_scene *scene, t_vec3 point, t_vec3 normal,
							t_rgb color)
{
	t_plane		*plane_data;
	t_object	*plane_obj;
	t_list		*new_node;

	plane_data = construct_plane_data(point, normal, color);
	if (plane_data == NULL)
		return (0);
	plane_obj = construct_object(PLANE, plane_data);
	if (plane_obj == NULL)
	{
		free(plane_data);
		return (0);
	}
	new_node = ft_lstnew(plane_obj);
	if (new_node == NULL)
	{
		free(plane_data);
		free(plane_obj);
		return (0);
	}
	ft_lstadd_back(&(scene->objects), new_node);
	return (1);
}

int	stub_add_objects(t_scene *scene)
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
	if (add_plane_to_scene(scene, (t_vec3){{0, -0.5, 0}}, (t_vec3){{0, 1, 0}},
		(t_rgb){{0.8, 0.8, 0.8}}) == 0)
		return (0);
	if (add_plane_to_scene(scene, (t_vec3){{0, 0, -5}}, (t_vec3){{0, 0, 1}},
		(t_rgb){{0.7, 0.7, 0.9}}) == 0)
		return (0);
	return (1);
}
