/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_closest_hit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasuke <reasuke@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 17:46:34 by reasuke           #+#    #+#             */
/*   Updated: 2025/05/18 17:46:51 by reasuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>

#include "tracer.h"

bool	find_closest_hit(bool hit_results[], t_hit_record temp_records[],
				int count, int *min_index)
{
	bool	hit_found;
	int		i;
	double	min_t;

	hit_found = false;
	*min_index = -1;
	min_t = INFINITY;
	i = 0;
	while (i < count)
	{
		if (hit_results[i] && ft_fchmin(&min_t, temp_records[i].t))
		{
			*min_index = i;
			hit_found = true;
		}
		i++;
	}
	return (hit_found);
}
