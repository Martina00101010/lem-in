/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 21:04:50 by pberge            #+#    #+#             */
/*   Updated: 2020/12/20 21:09:57 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	debug_graph(t_lem_in *lemin)
{
	t_room	*room;
	short	i;
	short	k;

	k = -1;
	while (++k < lemin->number_of_rooms)
	{
		room = lemin->rooms + k;
		if (room->bfs_level == 1)
			printf("## start room \n");
		if (room->bfs_level == MAX_SHORT)
			printf("## end room \n");
		if (room->bfs_level == 0)
			continue ;
		printf("room %s exits: ", room->name);
		i = -1;
		while (++i < room->exit_count)
			printf(" %s", room->exit[i]->name);
		printf("\tentrances: ");
		i = -1;
		while (++i < room->entrance_count)
			printf(" %s", room->entrance[i]->name);
		printf("\n");
	}
}

void	debug_path(t_room *room)
{
	short	i;

	i = -1;
	room->ant = -1;
	printf("%s ", room->name);
	if (room->exit_count == 0)
		printf("\n");
	while (++i < room->exit_count)
	{
		debug_path(room->exit[i]);
	}
}

void	debug_queue(t_queue *queue)
{
	printf("*** queue ***\n");
	while (queue != NULL)
	{
		printf(" %s", queue->room->name);
		queue = queue->next;
	}
	printf("\n");
}
