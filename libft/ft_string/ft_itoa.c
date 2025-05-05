/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 01:28:34 by reasuke           #+#    #+#             */
/*   Updated: 2024/03/30 15:33:03 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

static int	calc_digits(unsigned int n)
{
	int	digits;

	if (n == 0)
		return (1);
	digits = 0;
	while (n)
	{
		digits++;
		n /= 10;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	char			*ret;
	unsigned int	un;
	int				digits;
	bool			is_negative;

	is_negative = n < 0;
	if (is_negative)
		un = -n;
	else
		un = n;
	digits = calc_digits(un);
	ret = malloc(digits + is_negative + 1);
	if (!ret)
		return (NULL);
	if (is_negative)
		ret[0] = '-';
	ret[digits + is_negative] = '\0';
	while (digits--)
	{
		ret[digits + is_negative] = '0' + un % 10;
		un /= 10;
	}
	return (ret);
}
