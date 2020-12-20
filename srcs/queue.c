/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 17:33:15 by pberge            #+#    #+#             */
/*   Updated: 2020/12/20 17:34:52 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

short	push(t_queue **last, t_room *room)
{
	t_queue *new;

	new = (t_queue *)malloc(sizeof(t_queue));
	if (!new)
		return (0);
	ft_bzero(new, sizeof(t_queue));
	new->room = room;
	if (*last != NULL)
		(*last)->next = new;
	(*last) = new;
	return (1);
}

void 	pop(t_queue **queue, t_queue **last)
{
	t_queue *next;

	if (*queue != NULL)
	{
		next = (*queue)->next;
		free(*queue);
		*queue = next;
	}
	else
		*last = NULL;
}

short   add_exits_to_queue(t_room *room, t_queue **last)
{
	short	i;

	i = -1;
	while (++i < room->exit_count)
	{
		if (room->exit[i]->bfs_level == 0)
		{
			room->exit[i]->bfs_level = room->bfs_level + 1;
			if (!push(last, room->exit[i]))
				return (0);
		}
	}
	return (1);
}
