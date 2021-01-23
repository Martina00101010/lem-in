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

void	move_on_start(t_room *start, int *paths, int *ant_number,
												t_lem_in *lemin)
{
	int	i;

	i = -1;
	while (++i < start->exit_count)
	{
		if ((start->exit[i]->ant == 0 || start->exit[0]->bfs_level == MAX_SHORT)
			&& go(start->ant, i, paths))
		{
			if (lemin->sdl != NULL)
				highligh_rooms(start, start->exit[i], lemin, lemin->sdl);
			start->exit[i]->ant = ++(*ant_number);
			if (lemin->sdl == NULL)
				print_ant_move(start->exit[i]->name, *ant_number);
			start->ant--;
			if (lemin->sdl != NULL)
				draw_ant_start_move(start->exit[i], lemin, lemin->sdl);
		}
	}
}

void	move_one_ant(t_room *room, t_sdl *sdl, t_lem_in *lemin)
{
	if (room->ant != 0)
	{
		if (room->exit[0]->bfs_level == MAX_SHORT)
		{
			if (sdl != NULL)
				highligh_rooms(room, room->exit[0], lemin, sdl);
			room->exit[0]->ant++;
			if (sdl == NULL)
				print_ant_move(room->exit[0]->name, room->ant);
			room->ant = 0;
			if (sdl != NULL)
				draw_ant_move(room, lemin, lemin->sdl);
		}
		else if (room->exit[0]->ant == 0)
		{
			if (sdl != NULL)
				highligh_rooms(room, room->exit[0], lemin, sdl);
			room->exit[0]->ant = room->ant;
			if (sdl == NULL)
				print_ant_move(room->exit[0]->name, room->ant);
			room->ant = 0;
			if (sdl != NULL)
				draw_ant_move(room, lemin, lemin->sdl);
		}
	}
}

void	move_on_graph(t_room *end, t_sdl *sdl, t_lem_in *lemin)
{
	t_room	*room;
	int		i;

	i = -1;
	while (++i < end->entrance_count)
	{
		room = end->entrance[i];
		while (room->bfs_level != 1)
		{
			move_one_ant(room, sdl, lemin);
			room = room->entrance[0];
		}
	}
}

void	move_ants(t_lem_in *lemin, int *paths, int *ant_number)
{
	move_on_graph(lemin->end_room, lemin->sdl, lemin);
	move_on_start(lemin->start_room, paths, ant_number, lemin);
	if (lemin->flag != DRAW)
		ft_putchar('\n');
}
