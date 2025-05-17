/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:45:23 by yliu              #+#    #+#             */
/*   Updated: 2025/05/11 17:09:02 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_list	*ft_xlstnew(void *content)
{
	t_list	*new_node;

	new_node = ft_lstnew(content);
	if (!new_node)
		fatal_error("Failed to allocate memory for new list node");
	return (new_node);
}
