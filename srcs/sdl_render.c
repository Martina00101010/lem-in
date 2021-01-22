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
	char		o;

	o = (room->bfs_level == MAX_SHORT ? 1 : 0);
	if (!highlight)
		c = o ? MAG_ : GREEN_;
	num = room->ant == 0 ? ft_strdup(" ") : ft_itoa(room->ant);
	sur = TTF_RenderText_Shaded(sdl->font, num, highlight ? WHI_ : BLACK_, c);
	tex = SDL_CreateTextureFromSurface(sdl->ren, sur);
	SDL_RenderCopy(sdl->ren, tex, NULL, &(sdl->rect));
	SDL_FreeSurface(sur);
	SDL_DestroyTexture(tex);
	free(num);
}
