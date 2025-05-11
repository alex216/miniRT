/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_lighting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 20:21:34 by reasuke           #+#    #+#             */
/*   Updated: 2025/05/11 22:10:36 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>

#include "tracer.h"
#include "scene.h"
#include "vector.h"

/*
** Note: The RAY_T_MIN offset is necessary to prevent the "shadow acne" problem.
** Due to floating-point precision errors, without this small offset,
** the ray would incorrectly self-intersect with the surface it originated from.
*/
static bool	is_illuminated(t_vec3 hit_point, t_vec3 light_pos, t_scene scene)
{
	t_ray			light_ray;
	t_hit_record	tmp_rec;
	double			light_distance;
	t_list			*current_obj;

	light_ray.direction = vec3_normalize(vec3_sub(light_pos, hit_point));
	light_ray.origin = vec3_add(hit_point,
			vec3_scale(light_ray.direction, RAY_T_MIN)
			);
	light_distance = vec3_length(vec3_sub(light_pos, hit_point));
	current_obj = scene.objects;
	while (current_obj)
	{
		if (intersect_object(light_ray, current_obj->content, &tmp_rec))
		{
			if (tmp_rec.t < light_distance)
				return (false);
		}
		current_obj = current_obj->next;
	}
	return (true);
}

static t_rgb	calc_diffuse_contribution(t_hit_record hit_record,
											t_light *light)
{
	const t_vec3	light_dir
		= vec3_normalize(vec3_sub(light->position, hit_record.point));
	const double	diffuse_factor
		= fmax(0.0, vec3_dot(hit_record.normal, light_dir));

	return (vec3_scale(
			vec3_hadamard(hit_record.color, light->color),
			diffuse_factor * light->brightness
		));
}

static t_rgb	calc_ambient_contribution(t_hit_record hit_record,
											t_scene scene)
{
	return (vec3_scale(
			vec3_hadamard(hit_record.color, scene.ambient.color),
			scene.ambient.ratio
		));
}

static t_rgb	calc_specular_contribution(t_hit_record hit_record,
											t_light *light, t_ray ray)
{
	const t_vec3	light_dir
		= vec3_normalize(vec3_sub(light->position, hit_record.point));
	const t_vec3	view_dir
		= vec3_normalize(vec3_sub(ray.origin, hit_record.point));
	const t_vec3	reflect_dir
		= vec3_reflect(vec3_negate(light_dir), hit_record.normal);
	const double	specular_factor
		= pow(fmax(0.0, vec3_dot(view_dir, reflect_dir)), SPECULAR_POWER);

	return (vec3_scale(
			light->color,
			specular_factor * light->brightness
		));
}

t_rgb	calc_lighting(t_hit_record hit_record, t_scene scene, t_ray ray)
{
	t_rgb	diffuse;
	t_rgb	specular;
	t_list	*current_light;
	t_light	*light;
	t_rgb	color;

	color = calc_ambient_contribution(hit_record, scene);
	current_light = scene.lights;
	while (current_light)
	{
		light = current_light->content;
		if (is_illuminated(hit_record.point, light->position, scene))
		{
			diffuse = calc_diffuse_contribution(hit_record, light);
			color = vec3_add(color, diffuse);
			specular = calc_specular_contribution(hit_record, light, ray);
			color = vec3_add(color, specular);
		}
		current_light = current_light->next;
	}
	color = vec3_clamp(color, 0, 1);
	return (color);
}
