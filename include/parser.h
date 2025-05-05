/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 22:54:47 by yliu              #+#    #+#             */
/*   Updated: 2025/05/04 20:23:23 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minirt.h"
# include "utils.h"
# include <errno.h>

t_scene	*parse_scene(const char *filename);
double	parse_ratio(const char *str);
t_rgb	parse_color(const char *str);
t_vec3	parse_vector(const char *str);
double	parse_positive_double(const char *str);
double	parse_degree(const char *str);
void	parse_line(const char *line, t_scene *scene);

#endif
