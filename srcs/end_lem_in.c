/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_lem_in.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 14:24:09 by pberge            #+#    #+#             */
/*   Updated: 2020/12/05 18:12:59 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	print_error(void)
{
	ft_putendl("ERROR");
	exit(1);
}

void	end_links(t_link *link)
{
	t_link	*tmp;

	while (link != NULL)
	{
		tmp = link->next;
		free(link);
		link = tmp;
	}
}

void	end_with_error(char *line, t_lem_in *lemin, t_link *links)
{
	if (line != NULL)
		free(line);
	if (links != NULL)
		end_links(links);
	end_lem_in(lemin);
	print_error();
}

void	end_lem_in(t_lem_in *lemin)
{
	t_room *room;

	room = lemin->rooms;
	while (--lemin->number_of_rooms > -1)
	{
		if (room->name != NULL)
			ft_strdel(&room->name);
		if (room->entrance != NULL)
			free(room->entrance);
		if (room->exit != NULL)
			free(room->exit);
		room += 1;
	}
	free(lemin->rooms);
	ft_bzero(lemin, sizeof(lemin));
}
