/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:28:52 by reasuke           #+#    #+#             */
/*   Updated: 2025/05/06 20:07:05 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_H
# define MLX_UTILS_H

# include "mlx.h"

# define WINDOW_TITLE "MiniRT"
# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600

typedef enum e_event
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17,
}	t_event;

typedef enum e_mask
{
	NO_EVENT_MASK = 0L,
	KEY_PRESS_MASK = 1L << 0,
}	t_mask;

typedef struct s_mlx_conf
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*data;
	int		line_length;
	int		bits_per_pixel;
	int		endian;
}	t_mlx_conf;

t_mlx_conf	*construct_mlx_conf(void);
void		destroy_mlx_conf(t_mlx_conf *mlx_conf);
void		handle_events(t_mlx_conf *mlx_conf);
void		plot_pixel(t_mlx_conf *mlx_conf, int x, int y, int color);

#endif
