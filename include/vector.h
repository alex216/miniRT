/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 11:00:30 by yliu              #+#    #+#             */
/*   Updated: 2025/05/05 10:26:16 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef union u_vec3
{
	struct
	{
		double	x;
		double	y;
		double	z;
	};
	struct
	{
		double	r;
		double	g;
		double	b;
	};
}				t_vec3;

typedef t_vec3	t_rgb;

#endif
