/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:02:59 by reasuke           #+#    #+#             */
/*   Updated: 2024/03/30 16:06:00 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_module.h"
#include "ft_output.h"

void	fp_print_char(char c, t_format_info *fi, t_format_result *fr, int fd)
{
	if (fi->width && !(fi->flags & FLAG_MINUS) && !(fi->flags & FLAG_ZERO))
		fp_print_padding(' ', fi->width - 1, fd);
	else if (fi->width && !(fi->flags & FLAG_MINUS) && fi->flags & FLAG_ZERO)
		fp_print_padding('0', fi->width - 1, fd);
	ft_putchar_fd(c, fd);
	if (fi->width && fi->flags & FLAG_MINUS)
		fp_print_padding(' ', fi->width - 1, fd);
	if (fi->width)
		fr->cnt += fi->width;
	else
		fr->cnt++;
}
