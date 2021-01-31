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

void	sdl_move_one_ant(t_room *dst, t_room *src, t_lem_in *lemin)
{
	highligh_rooms(src, dst, lemin, lemin->sdl);
	if (dst->bfs_level == MAX_SHORT)
	{
		dst->ant += 1;
		src->ant = 0;
	}
	else if (src->bfs_level == 1)
	{
		src->ant -= 1;
		dst->ant = lemin->ants_at_start - src->ant;
	}
	else
	{
		dst->ant = src->ant;
		src->ant = 0;
	}
	sdl_draw_ant_move(dst, src, lemin, lemin->sdl);
}

void	choose_next_ant(t_move *move, t_lem_in *lemin)
{
	short	index;

	while (1)
	{
		if (move->room->bfs_level > 2)
		{
			index = move->room->bfs_level == MAX_SHORT ?
											move->path_index : 0;
			move->next = move->room->entrance[index];
			if (move->next->ant != 0)
				return ;
			move->room = move->next;
		}
		else if (move->path_index + 1 < lemin->end_room->entrance_count)
		{
			move->path_index++;
			move->room = lemin->end_room;
		}
		else
		{
			ft_bzero(move, sizeof(t_move));
			move->next = lemin->start_room->exit[0];
			return ;
		}
	}
}

void	sdl_move_on_graph(t_move *move, t_lem_in *lemin)
{
	choose_next_ant(move, lemin);
	if (move->on_graph)
		sdl_move_one_ant(move->room, move->next, lemin);
	move->room = move->next;
}

void	sdl_move_on_start(t_move *move, t_lem_in *lemin)
{
	short	found;

	found = 0;
	while (lemin->start_room->ant > 0 && !found)
	{
		if (move->room->ant == 0 &&
			go(lemin->start_room->ant, move->path_index, lemin->paths))
		{
			sdl_move_one_ant(move->room, lemin->start_room, lemin);
			found = 1;
		}
		if (move->path_index + 1 < lemin->start_room->exit_count)
		{
			move->path_index++;
			move->room = lemin->start_room->exit[move->path_index];
		}
		else
		{
			move->path_index = 0;
			move->room = lemin->end_room;
			move->on_graph = 1;
			return ;
		}
	}
}

void	sdl_move_ants(t_lem_in *lemin)
{
	if (lemin->end_room->ant < lemin->ants_at_start)
	{
		if (lemin->move.on_graph)
			sdl_move_on_graph(&lemin->move, lemin);
		if (!lemin->move.on_graph)
			sdl_move_on_start(&lemin->move, lemin);
		if (lemin->start_room->ant == 0)
		{
			lemin->move.path_index = 0;
			lemin->move.room = lemin->end_room;
			lemin->move.on_graph = 1;
		}
	}
}
