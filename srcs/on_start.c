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

int			get_rev_path_len(t_room *room)
{
	int len_path;

	len_path = 0;
	while (room->bfs_level != 1)
	{
		room = room->entrance[0];
		len_path++;
	}
	return (len_path);
}

int		*get_paths(t_room *room, short rev)
{
	int	*paths;
	int	i;

	i = -1;
	if (rev)
	{
		paths = (int *)ft_memalloc(sizeof(int) * room->entrance_count);
		while (++i < room->entrance_count)
		{
			paths[i] = get_path_len(room->entrance[i]) + 1;
		}
	}
	else
	{
		paths = (int *)ft_memalloc(sizeof(int) * room->exit_count);
		while (++i < room->exit_count)
		{
			paths[i] = get_path_len(room->exit[i]) + 1;
		}
	}
	return (paths);
}

void	choose_paths(t_lem_in *lemin)
{
	if (lemin->flag == DRAW)
	{
		lemin->paths = get_paths(lemin->end_room, 1);
		sort_paths(lemin->paths, lemin->end_room->exit_count,
					lemin->end_room->entrance);
	}
	else
	{
		lemin->paths = get_paths(lemin->start_room, 0);
		sort_paths(lemin->paths, lemin->start_room->exit_count,
					lemin->start_room->exit);
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
