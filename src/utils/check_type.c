/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 16:30:08 by yliu              #+#    #+#             */
/*   Updated: 2025/05/11 17:09:02 by yliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

bool	is_three_integer(const char *str)
{
	int	i;
	int	comma_count;

	i = 0;
	comma_count = 0;
	while (str[i])
	{
		if (str[i] == ',')
			comma_count++;
		else if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (comma_count == 2);
}

bool	is_double(const char *str)
{
	int	i;
	int	dot_count;

	i = 0;
	dot_count = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] == '.')
			dot_count++;
		else if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (dot_count <= 1);
}

bool	is_vec3(const char *str)
{
	int		i;
	int		comma_count;
	char	**result;

	i = 0;
	comma_count = 0;
	while (str[i])
	{
		if (str[i] == ',')
			comma_count++;
		i++;
	}
	if (comma_count != 2)
		return (false);
	result = ft_split(str, ',');
	if (!result)
		fatal_error("Memory allocation failed");
	if (!is_double(result[0]) || !is_double(result[1]) || !is_double(result[2]))
	{
		free(result);
		return (false);
	}
	free(result);
	return (true);
}
