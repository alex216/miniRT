/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 20:23:49 by yliu              #+#    #+#             */
/*   Updated: 2025/05/09 21:26:30 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static void	validate_scene(t_object_count *object_count)
{
	if (object_count->ambient > 1)
		fatal_error("Too many ambient lights");
	if (object_count->camera > 1)
		fatal_error("Too many cameras");
	if (object_count->light > MAX_LIGHTS)
		fatal_error("Too many lights");
}

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
		validate_scene(&object_count);
		free(line);
	}
	close(fd);
	return (scene);
}
