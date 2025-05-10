/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 00:10:25 by reasuke           #+#    #+#             */
/*   Updated: 2025/05/11 00:11:32 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "scene.h"

t_sphere	*construct_sphere_data(t_vec3 center, double radius, t_rgb color)
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

t_plane	*construct_plane_data(t_vec3 point, t_vec3 normal, t_rgb color)
{
	t_plane	*plane;

	plane = (t_plane *)malloc(sizeof(t_plane));
	if (plane == NULL)
		return (NULL);
	plane->point = point;
	plane->normal = normal;
	plane->color = color;
	return (plane);
}

t_object	*construct_object(t_object_type type, void *data)
{
	t_object	*obj;

	obj = (t_object *)malloc(sizeof(t_object));
	if (obj == NULL)
		return (NULL);
	obj->type = type;
	obj->data = data;
	return (obj);
}

