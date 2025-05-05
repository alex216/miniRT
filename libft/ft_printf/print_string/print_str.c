/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:02:59 by reasuke           #+#    #+#             */
/*   Updated: 2024/03/30 16:05:39 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../ft_printf_module.h"
#include "ft_math.h"
#include "ft_string.h"

void	fp_print_str(char *str, t_format_info *fi, t_format_result *fr, int fd)
{
	int	str_len;

	if (!str)
		str = STR_NULL;
	str_len = ft_strlen(str);
	if (fi->prec != PREC_NONE && fi->prec < str_len)
		str_len = fi->prec;
	if (fi->width && !(fi->flags & FLAG_MINUS) && !(fi->flags & FLAG_ZERO))
		fp_print_padding(' ', fi->width - str_len, fd);
	else if (fi->width && !(fi->flags & FLAG_MINUS) && fi->flags & FLAG_ZERO)
		fp_print_padding('0', fi->width - str_len, fd);
	write(fd, str, str_len);
	if (fi->width && fi->flags & FLAG_MINUS)
		fp_print_padding(' ', fi->width - str_len, fd);
	fr->cnt += ft_max(fi->width, str_len);
}
