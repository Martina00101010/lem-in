/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines_with_links.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 15:16:41 by pberge            #+#    #+#             */
/*   Updated: 2020/12/06 15:16:43 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_room	*find_room(t_room *room, char *name, short index)
{
	while (--index > -1)
	{
		if (ft_strcmp(room->name, name) == 0)
			return (room);
		room += 1;
	}
	return (NULL);
}

t_room	*get_pointer_of_room(t_lem_in *lemin, char **line, char delimiter)
{
	char	*name;
	t_room	*room;
	short	len;

	len = ft_strchr(*line, delimiter) - *line;
	name = get_room_name(line, len);
	if (name == NULL || **line != delimiter)
		return (NULL);
	room = find_room(lemin->rooms, name, lemin->number_of_rooms);
	free(name);
	if (delimiter == '-')
		(*line)++;
	return (room);
}

t_link	*create_link(t_link **links, t_link **last, t_room *one, t_room *two)
{
	t_link	*new;

	new = (t_link *)malloc(sizeof(t_link));
	if (new == NULL)
		return (NULL);
	ft_bzero(new, sizeof(t_link));
	new->one = one;
	new->two = two;
	return (new);
}

short	save_link(t_link **links, t_link **last, t_room *one, t_room *two)
{
	t_link	*new;

	new = create_link(links, last, one, two);
	if (new == NULL)
		return (0);
	if (*links == NULL)
	{
		*links = new;
		*last = new;
	}
	else
	{
		(*last)->next = new;
		new->prev = *last;
		*last = new;
	}
	return (1);
}

void    lines_with_links(t_lem_in *lemin, char *line, t_link **links)
{
    int		num_bytes;
	t_room	*one;
	t_room	*two;
	char	*to_free;
	t_link	*last;

	last = NULL;
	num_bytes = 1;
    while (num_bytes > 0)
    {
		if (!skip_comments(&line, lemin))
			return ;
		to_free = line;
		one = get_pointer_of_room(lemin, &line, '-');
		two = get_pointer_of_room(lemin, &line, '\0');
		if (one == NULL || two == NULL || one == two)
			end_with_error(to_free, lemin, NULL);
		if (!save_link(links, &last, one, two))
			end_with_error(to_free, lemin, NULL);
		free(to_free);
	    num_bytes = get_next_line(0, &line);
		if (num_bytes == -1)
			end_with_error(NULL, lemin, NULL);
    }
}
