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
	t_room *start
	short i;

	start = lemin->start_room;
	while (--lemin->number_of_rooms > -1)
	{
		printf("room %s exits:\t", start->name);
		i = start->exit_count;
		while (i-- > 0)
			printf(" %s", start->exit[i]->name);
		printf("\n");
		start += 1;
	}
}

void	debug_queue(t_queue *queue)
{
	printf("*** queue ***\n")
	while (queue != NULL)
	{
		printf(" %s", queue->room->name);
		queue = queue->next;
	}
	printf("\n");
}
