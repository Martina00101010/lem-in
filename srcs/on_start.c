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

#include "lem_in.h"

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

int		*get_paths(t_room *end)
{
	int	*paths;
	int	i;

	i = -1;
	paths = (int *)ft_memalloc(sizeof(int) * end->entrance_count);
	while (++i < end->entrance_count)
	{
		paths[i] = get_path_len(end->entrance[i]) + 1;
	}
	return (paths);
}

void	choose_paths(t_lem_in *lemin)
{
	if (lemin->flag == DRAW)
	{
		lemin->paths = get_paths(lemin->end_room);
		sort_paths(lemin->paths, lemin->end_room->exit_count, lemin->end_room->entrance);
	}
	else
	{
		lemin->paths = get_paths(lemin->start_room);
		sort_paths(lemin->paths, lemin->start_room->exit_count, lemin->start_room->exit);
	}
}

void	ready(t_lem_in *lemin)
{
	int	ant_number;

	ant_number = 0;
	choose_paths(lemin);
	lemin->start_room->ant = lemin->ants_at_start;
	if (lemin->flag == DRAW)
	{
		get_first_image(lemin);
		draw_start_end(lemin, lemin->sdl);
		lemin->move.room = lemin->start_room->exit[0];
		lemin->move.path_index = 0;
		sdl_loop(lemin, lemin->sdl);
	}
	else
	{
		while (lemin->end_room->ant < lemin->ants_at_start)
			move_ants(lemin, lemin->paths, &ant_number);
	}
	free(lemin->paths);
	lemin->paths = NULL;
}
