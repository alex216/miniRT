/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:31:53 by yliu              #+#    #+#             */
/*   Updated: 2025/05/13 21:58:09 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

static void	*get_object_data(t_list *object)
{
	return (((t_object *)object->content)->data);
}

t_plane	*get_plane_data(t_list *object)
{
	return ((t_plane *)get_object_data(object));
}

t_sphere	*get_sphere_data(t_list *object)
{
	return ((t_sphere *)get_object_data(object));
}

t_cylinder	*get_cylinder_data(t_list *object)
{
	return ((t_cylinder *)get_object_data(object));
}

t_cone	*get_cone_data(t_list *object)
{
	return ((t_cone *)get_object_data(object));
}
