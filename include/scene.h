/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 23:34:31 by yliu              #+#    #+#             */
/*   Updated: 2025/05/06 22:09:58 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "objects.h"
# include "libft.h"

typedef double	t_degree;

// ratio : 0.0 - 1.0
typedef struct s_ambient
{
	t_vec3		color;
	double		ratio;
}				t_ambient;

// fov : 0.0 - 180.0
typedef struct s_camera
{
	t_vec3		position;
	t_vec3		orientation;
	t_degree	fov;
}				t_camera;

// brightness : 0.0 - 1.0
typedef struct s_light
{
	t_vec3	position;
	t_rgb	color;
	double	brightness;
}			t_light;

typedef struct s_object
{
	t_object_type	type;
	void			*data;
}					t_object;

typedef struct s_scene
{
	t_ambient		ambient;
	t_camera		camera;
	t_list			*lights;
	t_list			*objects;
}					t_scene;

#endif
