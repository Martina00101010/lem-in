/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 12:38:19 by pberge            #+#    #+#             */
/*   Updated: 2020/11/23 23:44:58 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	sdl_render_paths(t_sdl *sdl)
{
	SDL_UpdateTexture(sdl->tex, NULL, sdl->pixels, sdl->pitch);
	SDL_RenderCopy(sdl->ren, sdl->tex, NULL, NULL);
	SDL_RenderPresent(sdl->ren);
}

void	sdl_render_text(t_sdl *sdl, t_room *room, char highlight)
{
	SDL_Surface *sur;
	SDL_Texture *tex;
	SDL_Color	c;
	char		*num;

	if (room->bfs_level == MAX_SHORT)
		c = BLUE_;
	else
		c = highlight ? MAG_ : GREEN_;
	num = room->ant == 0 ? ft_strdup(" ") : ft_itoa(room->ant);
	sur = TTF_RenderText(sdl->font, num, BLACK_, c);
	tex = SDL_CreateTextureFromSurface(sdl->ren, sur);
	SDL_RenderCopy(sdl->ren, tex, NULL, &(sdl->rect));
	SDL_FreeSurface(sur);
	SDL_DestroyTexture(tex);
	free(num);
}

void	draw_start_end(t_lem_in *lemin, t_sdl *sdl)
{
	t_room		*room;
	int			i;
	t_dpoint	convert;

	i = -1;
	SDL_UpdateTexture(sdl->tex, NULL, sdl->pixels, sdl->pitch);
	sdl_set_rect(lemin->start_room, lemin, sdl);
	sdl_render_text(sdl, lemin->start_room, 0);
	while (++i < lemin->start_room->exit_count)
	{
		room = lemin->start_room->exit[i];
		while (room->bfs_level != MAX_SHORT)
		{
			sdl_set_rect(room, lemin, sdl);
			sdl_render_text(sdl, room, 0);
			room = room->exit[0];
		}
	}
	sdl_set_rect(lemin->end_room, lemin, sdl);
	sdl_render_text(sdl, lemin->end_room, 0);
	SDL_RenderPresent(sdl->ren);
}
