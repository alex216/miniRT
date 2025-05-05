/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstbefore.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:54:29 by reasuke           #+#    #+#             */
/*   Updated: 2024/03/30 15:21:57 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_list.h"

t_list	*ft_lst_before(t_list *lst, t_list *trg)
{
	t_list	*before;

	if (!lst)
		return (NULL);
	before = lst;
	while (before->next && before->next != trg)
		before = before->next;
	if (before->next != trg)
		return (NULL);
	return (before);
}
