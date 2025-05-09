/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 19:58:04 by reasuke           #+#    #+#             */
/*   Updated: 2025/05/10 01:38:59 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEWPORT_H
# define VIEWPORT_H

# include "vector.h"

/**
 * Viewport Configuration for Ray Tracing
 *
 * This viewport is configured in a right-handed coordinate system where:
 * - The camera is positioned on the positive Z-axis looking toward -Z direction
 * - The viewport plane is parallel to the XY plane
 * - X-axis corresponds to the horizontal direction (right is positive)
 * - Y-axis corresponds to the vertical direction (down is positive)
 *
 * The viewport is represented by:
 * - origin: Top-left corner of the viewport
 * - dx: Unit step vector in the horizontal direction (per pixel)
 * - dy: Unit step vector in the vertical direction (per pixel)
 *
 * These vectors allow for mapping from pixel coordinates (i,j) to
 * world coordinates using: origin + i*dx + j*dy
 */
typedef struct s_viewport
{
	t_vec3	origin;
	t_vec3	dx;
	t_vec3	dy;
}	t_viewport;

void	init_viewport(t_viewport *vp, t_camera camera);

#endif
