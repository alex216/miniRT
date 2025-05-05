/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 01:21:14 by reasuke           #+#    #+#             */
/*   Updated: 2024/03/30 15:28:45 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*u_dst;
	const unsigned char	*u_src;

	if (!dst && !src)
		return (dst);
	u_dst = (unsigned char *)dst;
	u_src = (const unsigned char *)src;
	if (dst < src)
	{
		while (len--)
			*u_dst++ = *u_src++;
	}
	else
	{
		while (len--)
			u_dst[len] = u_src[len];
	}
	return (dst);
}
