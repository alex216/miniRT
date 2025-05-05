/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configure_integer_info.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:12:55 by reasuke           #+#    #+#             */
/*   Updated: 2024/03/30 16:04:44 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_module.h"
#include "ft_math.h"
#include "ft_string.h"

static void	_set_base(t_integer_info *info, t_format_info *fi)
{
	if (fi->conv == 'x' || fi->conv == 'p')
		info->base = LOWER_HEX_BASE;
	else if (fi->conv == 'X')
		info->base = UPPER_HEX_BASE;
	else if (fi->conv == 'o')
		info->base = OCT_BASE;
	else
		info->base = DEC_BASE;
}

static void	_set_prefix(t_integer_info *info, intmax_t nb, t_format_info *fi)
{
	info->prefix = "";
	if (info->is_signed && nb < 0)
		info->prefix = "-";
	else if (info->is_signed && fi->flags & FLAG_PLUS)
		info->prefix = "+";
	else if (info->is_signed && fi->flags & FLAG_SPACE)
		info->prefix = " ";
	else if (fi->flags & FLAG_HASH && fi->conv == 'x' && nb)
		info->prefix = LOEWR_HEX_PREFIX;
	else if (fi->flags & FLAG_HASH && fi->conv == 'X' && nb)
		info->prefix = UPPER_HEX_PREFIX;
	else if (fi->conv == 'p')
		info->prefix = LOEWR_HEX_PREFIX;
}

static void	_set_width(t_integer_info *info, intmax_t nb, t_format_info *fi)
{
	info->prefix_width = ft_strlen(info->prefix);
	if (nb == 0 && fi->prec == 0)
		info->digits = 0;
	else
		info->digits = fp_calc_digits_base(nb, ft_strlen(info->base),
				info->is_signed);
	if (fi->width && fi->prec == PREC_NONE && fi->flags & FLAG_ZERO)
	{
		info->space_width = 0;
		info->zero_width = ft_max(fi->width - info->digits
				- info->prefix_width, 0);
	}
	else
	{
		info->space_width = ft_max(fi->width - ft_max(fi->prec,
					info->digits) - info->prefix_width, 0);
		info->zero_width = ft_max(fi->prec - info->digits, 0);
	}
}

static void	_adjust_for_oct_prefix(t_integer_info *info, intmax_t nb,
				t_format_info *fi)
{
	if (fi->flags & FLAG_HASH && !info->is_signed && fi->conv == 'o'
		&& !info->zero_width && (nb || fi->prec == 0))
	{
		info->prefix = OCT_PREFIX;
		info->prefix_width = 1;
		if (info->space_width)
			info->space_width--;
	}
}

void	fp_configure_integer_info(t_integer_info *info, intmax_t nb,
			t_format_info *fi)
{
	info->is_signed = (fi->conv == 'd' || fi->conv == 'i');
	_set_base(info, fi);
	_set_prefix(info, nb, fi);
	_set_width(info, nb, fi);
	_adjust_for_oct_prefix(info, nb, fi);
}
