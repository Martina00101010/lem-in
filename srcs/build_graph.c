/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   build_graph.c									  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: pberge <marvin@42.fr>					  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/12/20 12:33:27 by pberge			#+#	#+#			 */
/*   Updated: 2020/12/20 12:33:38 by pberge		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "lem-in.h"

short	build_link(t_room ***room_links, t_room *new_link, short links_count)
{
	t_room	**new;

	new = (t_room **)malloc(sizeof(t_room *) * (links_count + 1));
	if (!new)
		return (0);
	if (*room_links != NULL)
	{
		ft_memcpy((void *)new, (void *)(*room_links), sizeof(t_room *) * links_count);
		free(*room_links);
	}
	new[links_count] = new_link;
	*room_links = new;
	links_count++;
	return (links_count);
}

void	delete_link(t_link *link)
{
	if (link->prev != NULL)
		link->prev->next = link->next;
	if (link->next != NULL)
		link->next->prev = link->prev;
	link->prev = NULL;
	link->next = NULL;
	free(link);
}

short	link_rooms(t_room *from, t_room *to, t_link *link, t_link **head)
{
	t_link	*next;
	short	count;

	next = link->next;
	if (to->bfs_level > from->bfs_level ||
		to->bfs_level == 0 ||
		to->bfs_level == MAX_SHORT)
	{
		count = build_link(&(from->exit), to, from->exit_count);
		if (count == 0)
			return (1);
		from->exit_count = count;
		count = build_link(&(to->entrance), from, to->entrance_count);
		if (count == 0)
			return (1);
		to->entrance_count = count;
	}
	if (link->prev == NULL)
		*head = next;
	delete_link(link);
	return (0);
}

short	find_exits(t_link **head, t_room *from)
{
	t_link	*link;
	t_link	*next;
	short	error;

	error = 0;
	link = *head;
	while (link != NULL)
	{
		next = link->next;
		if (ft_strcmp(link->one->name, from->name) == 0)
			error = link_rooms(from, link->two, link, head);
		else if (ft_strcmp(link->two->name, from->name) == 0)
			error = link_rooms(from, link->one, link, head);
		if (error)
			return (0);
		link = next;
	}
	return (1);
}

void	build_graph(t_lem_in *lemin, t_link **links)
{
	t_queue	*queue;
	t_queue	*last;
	t_room	*room;

	queue = NULL;
	lemin->start_room->bfs_level = 1;
	lemin->end_room->bfs_level = MAX_SHORT;
	push(&queue, lemin->start_room);
	last = queue;
	while (queue != NULL)
	{
		room = queue->room;
		if (!find_exits(links, room))
			end_with_error(NULL, lemin, *links);
		if (!add_exits_to_queue(room, &last))
			end_with_error(NULL, lemin, *links);
		pop(&queue, &last);
	}
}
