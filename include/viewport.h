/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 19:58:04 by reasuke           #+#    #+#             */
/*   Updated: 2025/05/10 01:29:20 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEWPORT_H
# define VIEWPORT_H

# include "vector.h"

typedef struct s_viewport
{
	t_vec3	origin;
	t_vec3	dx;
	t_vec3	dy;
}	t_viewport;

void	init_viewport(t_viewport *vp, t_camera camera);

#endif
