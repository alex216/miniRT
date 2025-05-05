/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 01:41:16 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/24 12:21:21 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_output.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	un;

	if (n < 0)
	{
		un = -n;
		ft_putchar_fd('-', fd);
	}
	else
		un = n;
	if (un / 10)
		ft_putnbr_fd(un / 10, fd);
	ft_putchar_fd('0' + un % 10, fd);
}
