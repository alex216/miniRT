/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 19:58:04 by reasuke           #+#    #+#             */
/*   Updated: 2025/05/09 00:51:47 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEWPORT_H
# define VIEWPORT_H

# include "vector.h"

typedef struct s_viewport
{
	t_vec3	origin;
	double	width;
	double	height;
	t_vec3	right;
	t_vec3	down;
}	t_viewport;

void	init_viewport(t_viewport *vp, t_camera camera);

#endif
