/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 23:34:31 by yliu              #+#    #+#             */
/*   Updated: 2025/05/29 16:02:16 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "libft.h"
# include "objects.h"

typedef double		t_degree;

// ratio : 0.0 - 1.0
typedef struct s_ambient
{
	t_vec3			color;
	double			ratio;
}					t_ambient;

// fov : 0.0 - 180.0
typedef struct s_camera
{
	t_vec3			position;
	t_vec3			orientation;
	t_degree		fov;
}					t_camera;

// brightness : 0.0 - 1.0
typedef struct s_light
{
	t_vec3			position;
	t_rgb			color;
	double			brightness;
}					t_light;

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

t_sphere			*construct_sphere_data(t_vec3 center, double radius,
						t_rgb color);
t_plane				*construct_plane_data(t_vec3 point, t_vec3 normal,
						t_rgb color);
t_object			*construct_object(t_object_type type, void *data);

t_object_type		get_object_type(t_list *object);

t_plane				*get_plane_data(t_list *object);
t_sphere			*get_sphere_data(t_list *object);
t_cylinder			*get_cylinder_data(t_list *object);
t_cone				*get_cone_data(t_list *object);
#endif
