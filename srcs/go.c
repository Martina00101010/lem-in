/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 14:22:26 by pberge            #+#    #+#             */
/*   Updated: 2021/01/16 14:22:41 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

short	go(int ants_on_start, int chosen, int *path)
{
	int	i;
	int	sum;

	i = -1;
	sum = 0;
	while (++i < chosen)
		sum += (path[chosen] - path[i]);
	return (sum < ants_on_start ? 1 : 0);
}

void	move_on_start(t_room *start, int *paths, int *ant_number)
{
	int	i;

	i = -1;
	while (++i < start->exit_count)
	{
		if (start->exit[i]->ant == 0 && go(start->ant, i, paths))
		{
			start->exit[i]->ant = ++(*ant_number);
			print_ant_move(start->exit[i]->name, *ant_number);
			start->ant--;
		}
	}
}

void	move_one_ant(t_room *room)
{
	if (room->ant != 0)
	{
		if (room->exit[0]->bfs_level == MAX_SHORT)
		{
			room->exit[0]->ant++;
			print_ant_move(room->exit[0]->name, room->ant);
			room->ant = 0;
		}
		else if (room->exit[0]->ant == 0)
		{
			room->exit[0]->ant = room->ant;
			print_ant_move(room->exit[0]->name, room->ant);
			room->ant = 0;
		}
	}
}

void	move_on_graph(t_room *end)
{
	t_room	*room;
	int		i;

	i = -1;
	while (++i < end->entrance_count)
	{
		room = end->entrance[i];
		while (room->bfs_level != 1)
		{
			move_one_ant(room);
			room = room->entrance[0];
		}
	}
}

void	move_ants(t_room *start, t_room *end, int *paths, int *ant_number)
{
	move_on_graph(end);
	move_on_start(start, paths, ant_number);
	ft_putchar('\n');
}
