/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 20:23:49 by yliu              #+#    #+#             */
/*   Updated: 2025/05/08 21:38:02 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

t_scene	*parse_scene(const char *filename)
{
	t_scene			*scene;
	int				fd;
	char			*line;
	t_object_count	object_count;

	object_count = (t_object_count){0, 0, 0};
	scene = ft_xmalloc(sizeof(t_scene));
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		parse_line(line, scene, &object_count);
		free(line);
	}
	close(fd);
	return (scene);
}
