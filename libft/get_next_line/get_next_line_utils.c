/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:03:32 by reasuke           #+#    #+#             */
/*   Updated: 2024/03/30 15:38:11 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"

size_t	gnl_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*gnl_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}

size_t	gnl_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;

	src_len = gnl_strlen(src);
	if (dstsize)
	{
		while (*src && --dstsize)
			*dst++ = *src++;
		*dst = '\0';
	}
	return (src_len);
}

char	*gnl_strndup(const char *s, size_t n)
{
	char	*ret;

	if (!s)
		return (NULL);
	ret = malloc(n + 1);
	if (!ret)
		return (NULL);
	gnl_strlcpy(ret, s, n + 1);
	return (ret);
}

char	*gnl_strjoin_with_free(char **s1, char **s2, int free_flag)
{
	char	*ret;
	size_t	s1_len;
	size_t	s2_len;

	if (!*s1 && !*s2)
		return (NULL);
	s1_len = gnl_strlen(*s1);
	s2_len = gnl_strlen(*s2);
	ret = malloc(s1_len + s2_len + 1);
	if (ret && *s1)
		gnl_strlcpy(ret, *s1, s1_len + 1);
	if (ret && *s2)
		gnl_strlcpy(ret + s1_len, *s2, s2_len + 1);
	if (*s1 && free_flag & 0b10)
	{
		free(*s1);
		*s1 = NULL;
	}
	if (*s2 && free_flag & 0b01)
	{
		free(*s2);
		*s2 = NULL;
	}
	return (ret);
}
