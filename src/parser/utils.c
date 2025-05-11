/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 19:40:10 by yliu              #+#    #+#             */
/*   Updated: 2025/05/11 17:09:17 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*next_token(const char **head, int is_delimiter(int c))
{
	char	*tail;
	char	*word;

	if (**head == '\0')
		return (NULL);
	while (**head && is_delimiter(**head))
		(*head)++;
	tail = (char *)*head;
	while (*tail && !is_delimiter(*tail))
		tail++;
	word = ft_strndup(*head, tail - *head);
	if (!word)
		fatal_error("Memory allocation failed");
	while (*tail && is_delimiter(*tail))
		tail++;
	*head = tail;
	return (word);
}
