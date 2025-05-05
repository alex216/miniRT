/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:02:52 by reasuke           #+#    #+#             */
/*   Updated: 2024/03/30 15:38:02 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

static char	*append_to_save(char **save, int fd)
{
	char		*buffer;
	ssize_t		read_size;
	char		*nl_ptr;

	buffer = malloc(BUFFER_SIZE + 1);
	while (buffer)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size <= 0)
			break ;
		buffer[read_size] = '\0';
		*save = gnl_strjoin_with_free(save, &buffer, 0b10);
		nl_ptr = gnl_strchr(*save, '\n');
		if (nl_ptr)
		{
			free(buffer);
			return (nl_ptr + 1);
		}
	}
	free(buffer);
	if (read_size == 0 && *save)
		return (gnl_strchr(*save, '\0'));
	free(*save);
	*save = NULL;
	return (NULL);
}

static char	*get_end_ptr(char **save, int fd)
{
	char	*end_ptr;

	end_ptr = gnl_strchr(*save, '\n');
	if (end_ptr)
		return (end_ptr + 1);
	else
		return (append_to_save(save, fd));
}

char	*get_next_line(int fd)
{
	static char	*save[FD_MAX + 1];
	char		*line;
	char		*tmp;
	char		*end_ptr;

	if (BUFFER_SIZE <= 0 || fd < 0 || FD_MAX < fd)
		return (NULL);
	end_ptr = get_end_ptr(&save[fd], fd);
	if (!end_ptr)
		return (NULL);
	line = gnl_strndup(save[fd], end_ptr - save[fd]);
	if (!line)
	{
		free(save[fd]);
		save[fd] = NULL;
		return (NULL);
	}
	tmp = save[fd];
	if (*end_ptr)
		save[fd] = gnl_strndup(end_ptr, gnl_strlen(end_ptr));
	else
		save[fd] = NULL;
	free(tmp);
	return (line);
}
