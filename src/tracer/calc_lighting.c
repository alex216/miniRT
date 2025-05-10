/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_lighting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 20:21:34 by reasuke           #+#    #+#             */
/*   Updated: 2025/05/10 20:42:50 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>

#include "tracer.h"
#include "scene.h"
#include "vector.h"

t_rgb	calc_lighting(t_hit_record hit_record, t_scene scene)
{
	t_rgb	color;
	t_list	*current_light;

	color = hit_record.color;
	current_light = scene.lights;
	while (current_light)
	{
		current_light = current_light->next;
	}
	return (color);
}
