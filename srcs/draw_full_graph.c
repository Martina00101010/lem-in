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
	t_room	*room;
	int		i;

	i = lemin->number_of_rooms;
	room = lemin->rooms;
	lemin->min.x = MAX_INT;
	lemin->min.y = MAX_INT;
	while (--i > -1)
	{
		if ((double)room->x > lemin->max.x)
			lemin->max.x = (double)room->x;
		if ((double)room->y > lemin->max.y)
			lemin->max.y = (double)room->y;
		if ((double)room->x < lemin->min.x)
			lemin->min.x = (double)room->x;
		if ((double)room->y < lemin->min.y)
			lemin->min.y = (double)room->y;
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
	t_point		beg;
	t_point		end;
	t_dpoint	conv;

	find_coors_range(lemin);
	conv.x = WIDTH / ((double)(lemin->max.x - lemin->min.x + 2));
	conv.y = HEIGHT / ((double)(lemin->max.y - lemin->min.y + 2));
	lemin->sdl = (t_sdl *)ft_memalloc(sizeof(t_sdl));
	lemin->sdl->pixels = get_pixels(DS, lemin, link);
	while (link != NULL)
	{
		beg = (t_point){
			(link->one->x - lemin->min.x + 1) * conv.x,
			(link->one->y - lemin->min.y + 1) * conv.y };
		end = (t_point){
			(link->two->x - lemin->min.x + 1) * conv.x,
			(link->two->y - lemin->min.y + 1) * conv.y };
		line(beg, end, lemin->sdl->pixels, GREY);
		link = link->next;
	}
	lemin->conv.x = conv.x;
	lemin->conv.y = conv.y;
}

void	draw_best_paths(t_lem_in *lemin)
{
	t_point		p;
	t_point		beg;
	t_point		end;
	t_room		*room;
	t_dpoint	conv;

	p.x = -1;
	conv.x = lemin->conv.x;
	conv.y = lemin->conv.y;
	while (++p.x < lemin->end_room->entrance_count)
	{
		room = lemin->start_room;
		while (1)
		{
			p.y = room->bfs_level == 1 ? p.x : 0;
			beg = (t_point){ (room->x - lemin->min.x + 1) * conv.x,
				(room->y - lemin->min.y + 1) * conv.y };
			end = (t_point){ (room->exit[p.y]->x - lemin->min.x + 1) * conv.x,
				(room->exit[p.y]->y - lemin->min.y + 1) * conv.y };
			line(beg, end, lemin->sdl->pixels, GREEN);
			room = room->exit[p.y];
			if (room->exit == NULL)
				break ;
		}
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
	sdl_render_paths(lemin->sdl);
}
