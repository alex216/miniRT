/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 23:34:31 by yliu              #+#    #+#             */
/*   Updated: 2025/05/06 21:40:43 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "vector.h"

typedef enum e_object_type
{
	SPHERE,
	CIRCLE,
	PLANE,
	CYLINDER,
	CONE
}						t_object_type;

typedef struct s_sphere
{
	t_vec3	center;
	double	radius;
	t_rgb	color;
}			t_sphere;

typedef struct s_circle
{
	t_vec3	center;
	t_vec3	normal;
	double	radius;
	t_rgb	color;
}			t_circle;

typedef struct s_plane
{
	t_vec3	point;
	t_vec3	normal;
	t_rgb	color;
}			t_plane;

typedef struct s_cylinder
{
	t_vec3	center;
	t_vec3	axis;
	double	radius;
	double	height;
	t_rgb	color;
}			t_cylinder;

typedef struct s_cone
{
	t_vec3	apex;
	t_vec3	axis;
	double	radius;
	double	height;
	t_rgb	color;
}			t_cone;
#endif
