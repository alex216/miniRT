/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:49:07 by reasuke           #+#    #+#             */
/*   Updated: 2025/05/06 18:54:24 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "libft.h"
#include "mlx_utils.h"

void	fatal_error(const char *msg)
{
	ft_dprintf(STDERR_FILENO, "%s: %s\n", WINDOW_TITLE, msg);
	exit(EXIT_FAILURE);
}
