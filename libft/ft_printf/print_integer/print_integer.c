/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:12:55 by reasuke           #+#    #+#             */
/*   Updated: 2024/03/30 16:06:15 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_module.h"
#include "ft_output.h"

void	fpf_print_integer(intmax_t nb, t_format_info *fi, t_format_result *fr,
			int fd)
{
	t_integer_info	info;

	fp_configure_integer_info(&info, nb, fi);
	if (!(fi->flags & FLAG_MINUS) && info.space_width)
		fp_print_padding(' ', info.space_width, fd);
	if (*info.prefix)
		ft_putstr_fd(info.prefix, fd);
	if (info.zero_width)
		fp_print_padding('0', info.zero_width, fd);
	if (info.digits)
		fp_putnbr_base_fd(nb, info.base, info.is_signed, fd);
	if (fi->flags & FLAG_MINUS && info.space_width)
		fp_print_padding(' ', info.space_width, fd);
	fr->cnt += info.space_width + info.prefix_width + info.zero_width
		+ info.digits;
}
