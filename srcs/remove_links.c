/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_links.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 14:22:26 by pberge            #+#    #+#             */
/*   Updated: 2021/01/16 14:22:41 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	remove_entrance(t_room *room, t_room *entrance, t_lem_in *lemin)
{
	t_room	**links;
	int		i;
	int		k;

	i = 0;
	k = 0;
	links = (t_room **)ft_memalloc(sizeof(t_room *) *
									(room->entrance_count - 1));
	if (!links)
		end_with_error(NULL, lemin, NULL);
	while (i < room->entrance_count)
	{
		if (room->entrance[i] != entrance)
		{
			links[k] = room->entrance[i];
			k++;
		}
		i++;
	}
	room->entrance = links;
	room->entrance_count--;
	printf("removed entrance %s from %s\n", entrance->name, room->name);
}
// должен остаться хотя бы один выход из комнаты, поэтому проверки на количество выходов нет
void	remove_exit(t_room *room, t_room *exit, t_lem_in *lemin)
{
	t_room	**links;
	int		i;
	int		k;

	i = 0;
	k = 0;
	links = (t_room **)ft_memalloc(sizeof(t_room *) *
									(room->exit_count - 1));
	if (!links)
		end_with_error(NULL, lemin, NULL);
	while (i < room->exit_count)
	{
		if (room->exit[i] != exit)
		{
			links[k] = room->exit[i];
			k++;
		}
		i++;
	}
	room->exit_count--;
	room->exit = links;
	printf("removed exit %s from %s\n", exit->name, room->name);
}

void	remove_other_links(t_room *room, t_room *save, t_lem_in *lemin)
{
	int	i;

	i = 0;
	while (i < room->entrance_count && room->entrance[i] != save)
	{
		remove_exit(room->entrance[i], room, lemin);
		i++;
	}
	free(room->entrance);
	room->entrance = (t_room **)ft_memalloc(sizeof(t_room *));
	if (!room->entrance)
		end_with_error(NULL, lemin, NULL);
	room->entrance[0] = save;
	room->entrance_count = 1;
}