/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 14:22:26 by pberge            #+#    #+#             */
/*   Updated: 2021/01/16 14:22:41 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

/**
 * prepare ants paths
 * sort paths
 * move ants
 * 		move ants from graph (if there are any)
 * 		move ants from start
 * 			for each ant make decision if do move and in which path
 * show states
*/

void	sort_paths(int *path, int count, t_room **exit)
{
	int		i;
	int		k;
	int		swap;
	t_room	*rswap;

	i = -1;
	while (++i < count)
	{
		k = i;
		while (++k < count)
		{
			if (path[i] > path[k])
			{
				swap = path[k];
				rswap = exit[k];
				path[k] = path[i];
				exit[k] = exit[i];
				path[i] = swap;
				exit[i] = rswap;
			}
		}
	}
}

int		*get_paths(t_room *start)
{
	int	*paths;
	int	i;

	i = -1;
	paths = (int *)ft_memalloc(sizeof(int) * start->exit_count);
	while (++i < start->exit_count)
	{
		paths[i] = get_path_len(start->exit[i]) + 1;
	}
	return (paths);
}

void	ready(t_lem_in *lemin)
{
	int	*paths;
	int	ant_number;

	ant_number = 0;
	paths = get_paths(lemin->start_room);
	sort_paths(paths, lemin->start_room->exit_count, lemin->start_room->exit);
	lemin->start_room->ant = lemin->ants_at_start;
	while (lemin->end_room->ant < lemin->ants_at_start)
		move_ants(lemin->start_room, lemin->end_room, paths, &ant_number);
	free(paths);
}
