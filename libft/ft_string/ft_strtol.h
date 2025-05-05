/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 14:46:40 by reasuke           #+#    #+#             */
/*   Updated: 2024/03/30 15:04:20 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRTOL_H
# define FT_STRTOL_H

# define LOWER_BASE "0123456789abcdefghijklmnopqrstuvwxyz"
# define UPPER_BASE "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
# define MAX_OVERFLOW 0b01
# define MIN_OVERFLOW 0b10

typedef struct s_tol_info
{
	const char		*str;
	char			**endptr;
	long			nb;
	int				base;
	int				sign;
	int				digit_cnt;
	int				overflow;
}					t_tol_info;

long				ft_strtol(const char *str, char **endptr, int base);

#endif
