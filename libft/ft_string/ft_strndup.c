/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:02:03 by reasuke           #+#    #+#             */
/*   Updated: 2024/03/30 15:01:46 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*ret;
	size_t	s1_len;
	size_t	ret_len;

	ret_len = n;
	s1_len = ft_strlen(s1);
	if (n > s1_len)
		ret_len = s1_len;
	ret = malloc(ret_len + 1);
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, s1, ret_len + 1);
	return (ret);
}
