/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 14:22:26 by pberge            #+#    #+#             */
/*   Updated: 2021/01/16 14:22:41 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	find_coors_range(t_lem_in *lemin)
{
	t_room *room;
	int		i;

	i = lemin->number_of_rooms;
	room = lemin->rooms;
	lemin->x_min = MAX_INT;
	lemin->y_min = MAX_INT;
	while (--i > -1)
	{
		if ((double)room->x > lemin->x_max)
			lemin->x_max = (double)room->x;
		if ((double)room->y > lemin->y_max)
			lemin->y_max = (double)room->y;
		if ((double)room->x < lemin->x_min)
			lemin->x_min = (double)room->x;
		if ((double)room->y < lemin->y_min)
			lemin->y_min = (double)room->y;
		room = lemin->rooms + i;
	}
}

int		*get_pixels(int size, t_lem_in *lemin, t_link *links)
{
	int	*pixels;

	pixels = (int *)ft_memalloc(sizeof(int) * size);
	if (pixels == NULL)
		end_with_error(NULL, lemin, links);
	return (pixels);
}

void	draw_full_graph(t_link *link, t_lem_in *lemin)
{
	t_point	beg;
	t_point	end;
	double	convert_x;
	double	convert_y;

	find_coors_range(lemin);
	convert_x = (double)WIDTH / ((double)(lemin->x_max - lemin->x_min + 2));
	convert_y = (double)HEIGHT / ((double)(lemin->y_max - lemin->y_min + 2));
	lemin->sdl = (t_sdl *)ft_memalloc(sizeof(t_sdl));
	lemin->sdl->pixels = get_pixels(DS, lemin, link);
	while (link != NULL)
	{
		beg = (t_point){
			(link->one->x - lemin->x_min + 1) * convert_x,
			(link->one->y - lemin->y_min + 1) * convert_y };
		end = (t_point){
			(link->two->x - lemin->x_min + 1) * convert_x,
			(link->two->y - lemin->y_min + 1) * convert_y };
		line(beg, end, lemin->sdl->pixels);
		link = link->next;
	}
}

void	get_first_image(t_lem_in *lemin)
{
	char	*msg;
	msg = start_sdl(lemin->sdl);
	if (msg != NULL)
	{
		ft_putendl(msg);
		end_with_error(NULL, lemin, NULL);
	}
	msg = open_window(lemin->sdl);
	if (msg != NULL)
	{
		ft_putendl(msg);
		end_with_error(NULL, lemin, NULL);
	}
	lemin->sdl->running = 1;
}
