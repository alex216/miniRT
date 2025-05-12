/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:28:53 by yliu              #+#    #+#             */
/*   Updated: 2025/05/12 15:45:55 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "libft.h"
# include "stdlib.h"
# include <stdbool.h>
# include <unistd.h>

t_list	*ft_xlstnew(void *content);
double	ft_atof(const char *str);
char	*next_token(const char **head, int is_delimiter(int c));
void	fatal_error(const char *msg);

#endif
