/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_by_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:13:31 by reasuke           #+#    #+#             */
/*   Updated: 2024/03/30 16:04:18 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf_module.h"
#include "ft_string.h"

static void	_print_string_by_format(t_format_info *fi,
				t_format_result *fr, va_list *ap, int fd)
{
	if (fi->conv == '%')
		fp_print_char('%', fi, fr, fd);
	else if (fi->conv == 'c')
		fp_print_char(va_arg(*ap, int), fi, fr, fd);
	else if (fi->conv == 's')
		fp_print_str(va_arg(*ap, char *), fi, fr, fd);
}

static void	_print_signed_integer_by_format(t_format_info *fi,
				t_format_result *fr, va_list *ap, int fd)
{
	if (fi->length == LENGTH_NONE)
		fpf_print_integer(va_arg(*ap, int), fi, fr, fd);
	else if (fi->length == LENGTH_L)
		fpf_print_integer(va_arg(*ap, long), fi, fr, fd);
	else if (fi->length == LENGTH_LL)
		fpf_print_integer(va_arg(*ap, long long), fi, fr, fd);
	else if (fi->length == LENGTH_H)
		fpf_print_integer((short)va_arg(*ap, int), fi, fr, fd);
	else if (fi->length == LENGTH_HH)
		fpf_print_integer((signed char)va_arg(*ap, int), fi, fr, fd);
	else if (fi->length == LENGTH_J)
		fpf_print_integer(va_arg(*ap, intmax_t), fi, fr, fd);
	else if (fi->length == LENGTH_T)
		fpf_print_integer(va_arg(*ap, ptrdiff_t), fi, fr, fd);
	else if (fi->length == LENGTH_Z)
		fpf_print_integer(va_arg(*ap, ssize_t), fi, fr, fd);
}

static void	_print_unsigned_integer_by_format(t_format_info *fi,
				t_format_result *fr, va_list *ap, int fd)
{
	if (fi->length == LENGTH_NONE)
		fpf_print_integer(va_arg(*ap, unsigned int), fi, fr, fd);
	else if (fi->length == LENGTH_L)
		fpf_print_integer(va_arg(*ap, unsigned long), fi, fr, fd);
	else if (fi->length == LENGTH_LL)
		fpf_print_integer(va_arg(*ap, unsigned long long), fi, fr, fd);
	else if (fi->length == LENGTH_H)
		fpf_print_integer((unsigned short)va_arg(*ap, int), fi, fr, fd);
	else if (fi->length == LENGTH_HH)
		fpf_print_integer((unsigned char)va_arg(*ap, int), fi, fr, fd);
	else if (fi->length == LENGTH_J)
		fpf_print_integer(va_arg(*ap, uintmax_t), fi, fr, fd);
	else if (fi->length == LENGTH_T)
		fpf_print_integer(va_arg(*ap, ptrdiff_t), fi, fr, fd);
	else if (fi->length == LENGTH_Z)
		fpf_print_integer(va_arg(*ap, size_t), fi, fr, fd);
}

static void	_set_count_by_format(t_format_info *fi, t_format_result *fr,
									va_list *ap)
{
	if (fi->length == LENGTH_NONE)
		*va_arg(*ap, int *) = fr->cnt;
	else if (fi->length == LENGTH_L)
		*va_arg(*ap, long *) = fr->cnt;
	else if (fi->length == LENGTH_LL)
		*va_arg(*ap, long long *) = fr->cnt;
	else if (fi->length == LENGTH_H)
		*va_arg(*ap, short *) = fr->cnt;
	else if (fi->length == LENGTH_HH)
		*va_arg(*ap, signed char *) = fr->cnt;
	else if (fi->length == LENGTH_J)
		*va_arg(*ap, intmax_t *) = fr->cnt;
	else if (fi->length == LENGTH_T)
		*va_arg(*ap, ptrdiff_t *) = fr->cnt;
	else if (fi->length == LENGTH_Z)
		*va_arg(*ap, ssize_t *) = fr->cnt;
}

void	fp_print_by_format(t_format_info *fi, t_format_result *fr,
			va_list *ap, int fd)
{
	if (ft_strchr("%cs", fi->conv))
		_print_string_by_format(fi, fr, ap, fd);
	else if (fi->conv == 'd' || fi->conv == 'i')
		_print_signed_integer_by_format(fi, fr, ap, fd);
	else if (ft_strchr("uxXo", fi->conv))
		_print_unsigned_integer_by_format(fi, fr, ap, fd);
	else if (fi->conv == 'p')
		fpf_print_integer(va_arg(*ap, uintptr_t), fi, fr, fd);
	else if (fi->conv == 'n')
		_set_count_by_format(fi, fr, ap);
}
