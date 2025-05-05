/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:42:38 by reasuke           #+#    #+#             */
/*   Updated: 2024/03/30 14:59:36 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <limits.h>
#include "ft_string.h"
#include "ft_type.h"
#include "ft_strtol.h"

static int	_parse_prefix(t_tol_info *info)
{
	ptrdiff_t	index;
	char		*ptr;

	if (!ft_strncmp(info->str, "0x", 2))
	{
		index = -1;
		ptr = ft_strchr(UPPER_BASE, info->str[2]);
		if (ptr)
			index = ptr - UPPER_BASE;
		ptr = ft_strchr(LOWER_BASE, info->str[2]);
		if (ptr)
			index = ptr - LOWER_BASE;
		if (index < 0 || info->base <= index)
		{
			info->digit_cnt++;
			info->str++;
			return (0);
		}
		info->digit_cnt++;
		info->str += 2;
	}
	return (1);
}

static void	_convert_str_to_long(t_tol_info *in)
{
	ptrdiff_t	index;
	char		*ptr;

	if (in->base == 16 && !_parse_prefix(in))
		return ;
	while (1)
	{
		index = -1;
		ptr = ft_strchr(UPPER_BASE, *in->str);
		if (ptr)
			index = ptr - UPPER_BASE;
		ptr = ft_strchr(LOWER_BASE, *in->str);
		if (ptr)
			index = ptr - LOWER_BASE;
		if (index < 0 || in->base <= index)
			break ;
		if (in->sign * in->nb > (LONG_MAX - index) / in->base && !in->overflow)
			in->overflow = MAX_OVERFLOW;
		if (in->sign * in->nb < (LONG_MIN + index) / in->base && !in->overflow)
			in->overflow = MIN_OVERFLOW;
		in->nb = in->nb * in->base + index;
		in->digit_cnt++;
		in->str++;
	}
}

static void	_set_base(t_tol_info *info, int base)
{
	if (base)
		info->base = base;
	else if (*info->str == '0' && (info->str[1] == 'x' || info->str[1] == 'X'))
		info->base = 16;
	else if (*info->str == '0')
		info->base = 8;
	else
		info->base = 10;
}

static void	_configure_tol_info(t_tol_info *info,
				const char *str, char **endptr, int base)
{
	info->str = str;
	info->endptr = endptr;
	if (info->endptr)
		*info->endptr = (char *)str;
	info->nb = 0;
	info->sign = 1;
	info->digit_cnt = 0;
	info->overflow = 0b00;
	while (ft_isspace(*info->str))
		info->str++;
	if (*info->str == '+' || *info->str == '-')
	{
		if (*info->str++ == '-')
			info->sign *= -1;
	}
	_set_base(info, base);
}

long	ft_strtol(const char *str, char **endptr, int base)
{
	t_tol_info	info;

	if (!(base == 0 || (2 <= base && base <= 36)))
	{
		errno = EINVAL;
		return (0);
	}
	_configure_tol_info(&info, str, endptr, base);
	_convert_str_to_long(&info);
	if (info.endptr && info.digit_cnt)
		*info.endptr = (char *)(info.str);
	if (info.digit_cnt == 0)
	{
		errno = EINVAL;
		return (0);
	}
	if (info.overflow)
	{
		errno = ERANGE;
		if (info.overflow == MAX_OVERFLOW)
			return (LONG_MAX);
		else if (info.overflow == MIN_OVERFLOW)
			return (LONG_MIN);
	}
	return (info.sign * info.nb);
}
