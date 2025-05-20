/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 20:23:49 by yliu              #+#    #+#             */
/*   Updated: 2025/05/18 19:58:06 by yliu             ###   ########.fr       */
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

void	parse_scene(t_scene *scene, const char *filename)
{
	int				fd;
	char			*line;
	t_object_count	object_count;

	object_count = (t_object_count){0, 0, 0};
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		fatal_error("Error: Failed to open file");
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
	return ;
}
