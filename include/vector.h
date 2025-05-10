/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 11:00:30 by yliu              #+#    #+#             */
/*   Updated: 2025/05/10 21:55:33 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <stdbool.h>

# define EPSILON 1e-6

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

// arithmetic.c
t_vec3	vec3_add(t_vec3 a, t_vec3 b);
t_vec3	vec3_sub(t_vec3 a, t_vec3 b);
t_vec3	vec3_hadamard(t_vec3 a, t_vec3 b);
t_vec3	vec3_scale(t_vec3 a, double s);
t_vec3	vec3_clump(t_vec3 a, double min, double max);

// geometric.c
double	vec3_dot(t_vec3 a, t_vec3 b);
t_vec3	vec3_cross(t_vec3 a, t_vec3 b);
double	vec3_length(t_vec3 a);
t_vec3	vec3_normalize(t_vec3 a);
bool	vec3_is_parallel(t_vec3 a, t_vec3 b);

#endif
