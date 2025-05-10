/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 01:44:48 by reasuke           #+#    #+#             */
/*   Updated: 2025/05/10 20:40:31 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACER_H
# define TRACER_H

# include "mlx_utils.h"
# include "scene.h"
# include "vector.h"

# define RAY_T_MIN 0.001

typedef struct s_ray
{
	t_vec3	origin;
	t_vec3	direction;
}	t_ray;

typedef struct s_hit_record
{
	double	t;
	t_vec3	point;
	t_vec3	normal;
	t_rgb	color;
}	t_hit_record;

void	render(t_scene scene, t_mlx_conf *mlx_conf);
bool	intersect_object(t_ray ray, t_object *obj, t_hit_record *hit_record);
t_rgb	trace_ray(t_ray ray, t_scene scene);

#endif
