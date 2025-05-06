/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 19:40:10 by yliu              #+#    #+#             */
/*   Updated: 2025/05/05 17:51:00 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	exit_with_errmsg(const char *msg)
{
	ft_dprintf(STDERR_FILENO, "%s\n", msg);
	exit(EXIT_FAILURE);
}

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
		exit_with_errmsg("Memory allocation failed");
	while (*tail && is_delimiter(*tail))
		tail++;
	*head = tail;
	return (word);
}
