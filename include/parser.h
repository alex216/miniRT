/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 22:54:47 by yliu              #+#    #+#             */
/*   Updated: 2025/05/12 15:08:03 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "scene.h"
# include "utils.h"
# include <errno.h>
# include <math.h>

# define MAX_LIGHTS 10

typedef struct t_object_count
{
	unsigned int	ambient;
	unsigned int	camera;
	unsigned int	light;
}					t_object_count;

double				parse_ratio(const char *str);
t_rgb				parse_color(const char *str);
t_vec3				parse_vector_position(const char *str);
t_vec3				parse_vector_direction(const char *str);
double				parse_positive_double(const char *str);
double				parse_degree(const char *str);

void				parse_plane(const char **line, t_scene *scene);
void				parse_sphere(const char **line, t_scene *scene);
void				parse_cylinder(const char **line, t_scene *scene);
void				parse_cone(const char **line, t_scene *scene);

void				parse_line(const char *line, t_scene *scene,
						t_object_count *object_count);
t_scene				*parse_scene(const char *filename);

#endif
