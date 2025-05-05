/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_module.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:01:28 by reasuke           #+#    #+#             */
/*   Updated: 2024/03/30 16:01:58 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_MODULE_H
# define FT_PRINTF_MODULE_H

# include <stdarg.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>

# define OCT_BASE "01234567"
# define DEC_BASE "0123456789"
# define UPPER_HEX_BASE "0123456789ABCDEF"
# define LOWER_HEX_BASE "0123456789abcdef"

# define FLAGS "-+ #0"

typedef enum s_flag_options
{
	FLAG_NONE = 0,
	FLAG_MINUS = 1 << 0,
	FLAG_PLUS = 1 << 1,
	FLAG_SPACE = 1 << 2,
	FLAG_HASH = 1 << 3,
	FLAG_ZERO = 1 << 4,
}				t_flag_options;

# define WIDTH_NONE 0

# define PREC_NONE -1

typedef enum e_length_options
{
	LENGTH_NONE,
	LENGTH_L,
	LENGTH_LL,
	LENGTH_H,
	LENGTH_HH,
	LENGTH_J,
	LENGTH_T,
	LENGTH_Z,
}				t_length_options;

# define STR_NULL "(null)"

# define OCT_PREFIX "0"
# define LOEWR_HEX_PREFIX "0x"
# define UPPER_HEX_PREFIX "0X"

typedef struct s_format_result
{
	const char	*format;
	int			cnt;
}				t_format_result;

typedef struct s_format_info
{
	int			flags;
	int			width;
	int			prec;
	int			length;
	char		conv;
}				t_format_info;

typedef struct s_integer_info
{
	bool		is_signed;
	char		*base;
	char		*prefix;
	int			space_width;
	int			zero_width;
	int			prefix_width;
	int			digits;
}				t_integer_info;

int				ft_printf(const char *format, ...);
int				ft_vprintf(const char *format, va_list ap);
int				ft_dprintf(int fd, const char *format, ...);
int				ft_vdprintf(int fd, const char *format, va_list ap);

void			fp_configure_format_info( t_format_info *fi,
					t_format_result *fr, va_list *ap);
void			fp_print_by_format(t_format_info *fi, t_format_result *fr,
					va_list *ap, int fd);

void			fp_print_char(char c, t_format_info *fi, t_format_result *fr,
					int fd);
void			fp_print_str(char *str, t_format_info *fi,
					t_format_result *fr, int fd);
void			fp_print_padding(char c, int len, int fd);

void			fpf_print_integer(intmax_t nb, t_format_info *fi,
					t_format_result *fr, int fd);
void			fp_configure_integer_info(t_integer_info *info, intmax_t nb,
					t_format_info *fi);
void			fp_putnbr_base_fd(intmax_t nb, const char *base, bool is_signed,
					int fd);
int				fp_calc_digits_base(intmax_t nb, size_t radix, bool is_signed);

#endif
