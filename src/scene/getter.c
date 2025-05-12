/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:31:53 by yliu              #+#    #+#             */
/*   Updated: 2025/05/12 18:33:37 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

enum e_object_type	get_object_type(t_list *object)
{
	return (((t_object *)object->content)->type);
}

void	*get_object_data(t_list *object)
{
	return (((t_object *)object->content)->data);
}
