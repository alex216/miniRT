/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 01:44:48 by reasuke           #+#    #+#             */
/*   Updated: 2025/05/17 21:04:27 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACER_H
# define TRACER_H

# include "mlx_utils.h"
# include "scene.h"
# include "vector.h"

# define RAY_T_MIN 0.001
# define SPECULAR_POWER 100

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

typedef struct s_disk
{
	t_vec3	center;
	t_vec3	normal;
	double	radius;
	t_rgb	color;
}	t_disk;

typedef struct s_quadratic_coef
{
	double	a;
	double	b;
	double	c;
}	t_quadratic_coef;

typedef struct s_quadratic_result
{
	double	s1;
	double	s2;
}	t_quadratic_result;

void	render(t_scene scene, t_mlx_conf *mlx_conf);

bool	intersect_object(t_ray ray, t_object *obj, t_hit_record *hit_record);
bool	intersect_plane(t_ray ray, t_plane *plane, t_hit_record *hit_record);
bool	intersect_disk(t_ray ray, t_disk disk, t_hit_record *record);

t_rgb	calc_lighting(t_hit_record hit_record, t_scene scene, t_ray ray);
t_rgb	trace_ray(t_ray ray, t_scene scene);

bool	solve_quadratic(t_quadratic_coef coef, t_quadratic_result *result);

#endif
