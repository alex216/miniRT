/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 22:54:47 by yliu              #+#    #+#             */
/*   Updated: 2025/05/06 21:41:58 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minirt.h"
# include "utils.h"
# include <errno.h>

double	parse_ratio(const char *str);
t_rgb	parse_color(const char *str);
t_vec3	parse_vector(const char *str);
double	parse_positive_double(const char *str);
double	parse_degree(const char *str);

void parse_plane(const char **line, t_scene *scene);
void parse_sphere(const char **line, t_scene *scene);
void parse_cylinder(const char **line, t_scene *scene);
void parse_cone(const char **line, t_scene *scene);

void	parse_line(const char *line, t_scene *scene);
t_scene	*parse_scene(const char *filename);

#endif
