/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_largest_bfs_level.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 14:22:26 by pberge            #+#    #+#             */
/*   Updated: 2021/01/16 14:22:41 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int	find_largest_bfs_level(t_room *end)
{
	short	i;
	short	largest_bfs;

	largest_bfs = 0;
	i = end->entrance_count;
	while (i-- > 0)
	{
		if (largest_bfs < end->entrance[i]->bfs_level)
			largest_bfs = end->entrance[i]->bfs_level;
	}
	return (largest_bfs);
}
