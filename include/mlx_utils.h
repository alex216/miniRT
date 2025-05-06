/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:28:52 by reasuke           #+#    #+#             */
/*   Updated: 2025/05/06 18:40:25 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS
# define MLX_UTILS

# include "mlx.h"

#define WINDOW_TITLE "MiniRT"
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

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

#endif
