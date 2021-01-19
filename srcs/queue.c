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

short	push_by_priority(t_queue **head, t_room *room)
{
	t_queue	*q;
	t_queue *new;

	q = *head;
	new = (t_queue *)malloc(sizeof(t_queue));
	if (!new)
		return (0);
	ft_bzero(new, sizeof(t_queue));
	new->room = room;
	if (q == NULL)
		*head = new;
	else if (q->room->bfs_level < room->bfs_level)
	{
		new->next = q;
		*head = new;
	}
	else
	{
		while (q->next != NULL && q->next->room->bfs_level >= room->bfs_level)
			q = q->next;
		new->next = q->next;
		q->next = new;
	}
	return (1);
}

short	push(t_queue **queue, t_room *room)
{
	t_queue *new;
	t_queue	*q;

	q = *queue;
	new = (t_queue *)malloc(sizeof(t_queue));
	if (!new)
		return (0);
	ft_bzero(new, sizeof(t_queue));
	new->room = room;
	if (q == NULL)
		*queue = new;
	else
	{
		while (q->next != NULL)
			q = q->next;
		q->next = new;
	}
	return (1);
}

void 	pop(t_queue **queue)
{
	t_queue *next;

	if (*queue != NULL)
	{
		next = (*queue)->next;
		free(*queue);
		*queue = next;
	}
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
