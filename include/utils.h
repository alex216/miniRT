/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:28:53 by yliu              #+#    #+#             */
/*   Updated: 2025/05/06 18:46:23 by yliu             ###   ########.fr       */
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
void	exit_with_errmsg(const char *msg);
char	*next_token(const char **head, int is_delimiter(int c));
bool	is_three_integer(const char *str);
bool	is_double(const char *str);
bool	is_vec3(const char *str);

#endif
