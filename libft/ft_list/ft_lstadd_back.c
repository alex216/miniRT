/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:22:37 by reasuke           #+#    #+#             */
/*   Updated: 2024/02/24 12:16:29 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_lstadd_back(t_list **lst, t_list *new_lst)
{
	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new_lst;
		return ;
	}
	ft_lstlast(*lst)->next = new_lst;
}
