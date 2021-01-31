/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_output_forks.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 14:22:26 by pberge            #+#    #+#             */
/*   Updated: 2021/01/16 14:22:41 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			get_path_len(t_room *room)
{
	int len_path;

	len_path = 0;
	while (room->bfs_level != MAX_SHORT)
	{
		room = room->exit[0];
		len_path++;
	}
	return (len_path);
}

t_room		*get_best_exit(t_room *room)
{
	int		i;
	int		path_len;
	int		min_path_len;
	t_room	*best;

	i = -1;
	best = NULL;
	path_len = MAX_INT;
	min_path_len = MAX_INT;
	while (++i < room->exit_count)
	{
		path_len = get_path_len(room->exit[i]);
		if (path_len < min_path_len)
		{
			min_path_len = path_len;
			best = room->exit[i];
		}
	}
	return (best);
}

void		remove_path_from(t_room *room)
{
	t_room	*next;
	int		i;
	int		k;

	while (room->bfs_level != MAX_SHORT)
	{
		next = room->exit[0];
		free(room->name);
		free(room->entrance);
		free(room->exit);
		ft_bzero(room, sizeof(t_room));
		room = next;
	}
	i = 0;
	k = 0;
	while (i < room->entrance_count)
	{
		if (room->entrance[i]->name != NULL)
		{
			room->entrance[k] = room->entrance[i];
			k++;
		}
		i++;
	}
	room->entrance_count--;
}

static void	remove_forks(t_room *room, t_lem_in *lemin)
{
	t_room	*best;
	int		i;

	i = -1;
	best = get_best_exit(room);
	while (++i < room->exit_count)
	{
		if (room->exit[i] != best)
			remove_path_from(room->exit[i]);
	}
	free(room->exit);
	room->exit = (t_room **)ft_memalloc(sizeof(t_room *));
	if (!room->exit)
		end_with_error(NULL, lemin, NULL);
	room->exit[0] = best;
	room->exit_count = 1;
}

void		remove_output_forks(t_lem_in *lemin)
{
	t_room	*room;
	t_queue	*q;

	q = NULL;
	room = lemin->end_room;
	add_entrances_to_queue(&q, room);
	while (q != NULL)
	{
		room = q->room;
		add_entrances_to_queue(&q, room);
		if (room->exit_count > 1)
			remove_forks(room, lemin);
		pop(&q);
	}
}
