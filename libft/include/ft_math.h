/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 12:09:36 by reasuke           #+#    #+#             */
/*   Updated: 2024/03/30 15:24:25 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

# include <stdbool.h>

int		ft_abs(int a);
int		ft_max(int a, int b);
int		ft_min(int a, int b);
bool	ft_chmax(int *a, int b);
bool	ft_chmin(int *a, int b);
void	ft_swap(int *a, int *b);

double	ft_fabs(double a);
double	ft_fmax(double a, double b);
double	ft_fmin(double a, double b);
bool	ft_fchmax(double *a, double b);
bool	ft_fchmin(double *a, double b);
void	ft_fswap(double *a, double *b);

#endif
