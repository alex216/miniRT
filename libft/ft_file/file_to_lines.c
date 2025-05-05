/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_lines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:22:21 by reasuke           #+#    #+#             */
/*   Updated: 2024/06/28 02:40:47 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_file.h"
#include "ft_string.h"
#include "get_next_line.h"

static int	_count_lines(char *file_path)
{
	int		fd;
	int		n;
	char	*line;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (ERROR);
	n = 0;
	errno = 0;
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
		{
			close(fd);
			if (errno != 0)
				return (ERROR);
			break ;
		}
		free(line);
		n++;
	}
	return (n);
}

static int	_fill_lines(char **lines, int n, char *file_path)
{
	int		fd;
	char	*line;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (ERROR);
	errno = 0;
	while (n--)
	{
		line = get_next_line(fd);
		if (errno)
		{
			ft_free_strs(lines);
			close(fd);
			return (ERROR);
		}
		*lines++ = line;
	}
	*lines = NULL;
	close(fd);
	return (OK);
}

char	**file_to_lines(char *file_path)
{
	int		n;
	char	**lines;

	n = _count_lines(file_path);
	if (n == ERROR)
		return (NULL);
	lines = malloc(sizeof(char *) * (n + 1));
	if (!lines)
		return (NULL);
	if (_fill_lines(lines, n, file_path) == ERROR)
		return (NULL);
	return (lines);
}
