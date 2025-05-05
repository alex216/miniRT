/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:59:33 by reasuke           #+#    #+#             */
/*   Updated: 2024/03/30 16:04:00 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_output.h"
#include "ft_printf_module.h"

int	ft_vdprintf(int fd, const char *format, va_list ap)
{
	va_list			ap_copy;
	t_format_result	fr;
	t_format_info	fi;

	va_copy(ap_copy, ap);
	fr = (t_format_result){format, 0};
	while (*fr.format)
	{
		if (*fr.format == '%')
		{
			fi = (t_format_info){FLAG_NONE, WIDTH_NONE, PREC_NONE, LENGTH_NONE,
				'\0'};
			fp_configure_format_info(&fi, &fr, &ap_copy);
			fp_print_by_format(&fi, &fr, &ap_copy, fd);
		}
		else
		{
			ft_putchar_fd(*fr.format++, fd);
			fr.cnt++;
		}
	}
	va_end(ap_copy);
	return (fr.cnt);
}
