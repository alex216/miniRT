/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basename.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 22:52:31 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/20 20:51:49 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "ft_string.h"

static bool	is_only_slashes(const char *pathname)
{
	while (*pathname)
	{
		if (*pathname != '/')
			return (false);
		pathname++;
	}
	return (true);
}

char	*ft_basename(char *pathname)
{
	char	*base;
	size_t	len;

	if (pathname == NULL || *pathname == '\0')
		return (".");
	len = ft_strlen(pathname);
	if (is_only_slashes(pathname))
		return (pathname + len - 1);
	while (len > 1 && pathname[len - 1] == '/')
		pathname[--len] = '\0';
	base = ft_strrchr(pathname, '/');
	if (base == NULL)
		return (pathname);
	return (base + 1);
}
