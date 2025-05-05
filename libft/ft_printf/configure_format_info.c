/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configure_format_info.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:17:21 by reasuke           #+#    #+#             */
/*   Updated: 2024/03/30 16:03:31 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_module.h"
#include "ft_string.h"
#include "ft_type.h"

static void	_set_flags(t_format_info *fi, t_format_result *fr)
{
	char		*ptr;
	ptrdiff_t	index;

	while (true)
	{
		ptr = ft_strchr(FLAGS, *fr->format);
		if (!ptr)
			break ;
		index = ptr - FLAGS;
		fi->flags |= 1 << index;
		fr->format++;
	}
}

static void	_set_width(t_format_info *fi, t_format_result *fr, va_list *ap)
{
	if (*fr->format == '*')
	{
		fi->width = va_arg(*ap, int);
		if (fi->width < 0)
		{
			fi->width = -fi->width;
			fi->flags |= FLAG_MINUS;
		}
		fr->format++;
	}
	else
	{
		fi->width = ft_atoi(fr->format);
		while (ft_isdigit(*fr->format))
			fr->format++;
	}
}

static void	_set_precision(t_format_info *fi, t_format_result *fr,
		va_list *ap)
{
	if (*fr->format == '.')
	{
		fr->format++;
		if (*fr->format == '*')
		{
			fi->prec = va_arg(*ap, int);
			fr->format++;
		}
		else
		{
			fi->prec = ft_atoi(fr->format);
			while (ft_isdigit(*fr->format))
				fr->format++;
		}
		if (fi->prec < 0)
			fi->prec = PREC_NONE;
	}
}

static void	_set_length_and_conversion(t_format_info *fi, t_format_result *fr)
{
	if (!ft_strncmp(fr->format, "ll", 2))
		fi->length = LENGTH_LL;
	else if (!ft_strncmp(fr->format, "l", 1))
		fi->length = LENGTH_L;
	else if (!ft_strncmp(fr->format, "hh", 2))
		fi->length = LENGTH_HH;
	else if (!ft_strncmp(fr->format, "h", 1))
		fi->length = LENGTH_H;
	else if (!ft_strncmp(fr->format, "j", 1))
		fi->length = LENGTH_J;
	else if (!ft_strncmp(fr->format, "t", 1))
		fi->length = LENGTH_T;
	else if (!ft_strncmp(fr->format, "z", 1))
		fi->length = LENGTH_Z;
	while (ft_strchr("lhjtz", *fr->format))
		fr->format++;
	fi->conv = *fr->format;
}

void	fp_configure_format_info(t_format_info *fi, t_format_result *fr,
			va_list *ap)
{
	fr->format++;
	_set_flags(fi, fr);
	_set_width(fi, fr, ap);
	if (fi->flags & FLAG_MINUS && fi->flags & FLAG_ZERO)
		fi->flags &= ~FLAG_ZERO;
	_set_precision(fi, fr, ap);
	_set_length_and_conversion(fi, fr);
	fr->format++;
}
