/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:17:12 by yliu              #+#    #+#             */
/*   Updated: 2025/04/20 16:53:26 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*window;

	(void)argc;
	(void)argv;
	mlx = mlx_init();
	if (!mlx)
		return (1);
	window = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "MiniRT");
	if (!window)
		return (1);
	mlx_loop(mlx);
	return (0);
}
