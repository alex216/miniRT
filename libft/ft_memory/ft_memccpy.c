/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 00:13:40 by reasuke           #+#    #+#             */
/*   Updated: 2024/03/30 15:27:24 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*u_dst;
	const unsigned char	*u_src;

	u_dst = (unsigned char *)dst;
	u_src = (const unsigned char *)src;
	while (n--)
	{
		if (*u_src == (unsigned char)c)
		{
			*u_dst++ = *u_src++;
			return ((void *)u_dst);
		}
		*u_dst++ = *u_src++;
	}
	return (NULL);
}
