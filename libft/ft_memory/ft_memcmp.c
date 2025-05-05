/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 01:01:03 by reasuke           #+#    #+#             */
/*   Updated: 2024/03/30 15:28:29 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*u_s1;
	const unsigned char	*u_s2;

	u_s1 = (const unsigned char *)s1;
	u_s2 = (const unsigned char *)s2;
	while (n--)
	{
		if (*u_s1 != *u_s2)
			return (*u_s1 - *u_s2);
		u_s1++;
		u_s2++;
	}
	return (0);
}
