/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 22:09:19 by reasuke           #+#    #+#             */
/*   Updated: 2024/03/30 15:33:16 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"

static char	*ft_strdup_with_delimiter(const char *s1, char c)
{
	char	*ret;
	size_t	len;

	len = 0;
	while (s1[len] && s1[len] != c)
		len++;
	ret = malloc(len + 1);
	if (!ret)
		return (ret);
	ft_strlcpy(ret, s1, len + 1);
	return (ret);
}

static size_t	count_words(const char *s, char c)
{
	size_t	words;
	int		is_prev_delimiter;

	words = 0;
	is_prev_delimiter = 1;
	while (*s)
	{
		if (is_prev_delimiter && *s != c)
			words++;
		is_prev_delimiter = *s == c;
		s++;
	}
	return (words);
}

static char	**free_strs(char **strs, size_t n)
{
	while (n--)
		free(strs[n]);
	free(strs);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	char	**ret;
	size_t	words;
	size_t	offset;
	size_t	i;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	ret = malloc(sizeof(char *) * (words + 1));
	if (!ret)
		return (NULL);
	i = 0;
	offset = 0;
	while (i < words)
	{
		while (s[offset] == c)
			offset++;
		ret[i] = ft_strdup_with_delimiter(s + offset, c);
		if (!ret[i])
			return (free_strs(ret, i));
		offset += ft_strlen(ret[i]);
		i++;
	}
	ret[words] = NULL;
	return (ret);
}
