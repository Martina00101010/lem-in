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

void	sdl_set_rect(t_room *room, t_lem_in *lemin, t_sdl *sdl)
{
	sdl->rect.x = (room->x - lemin->min.x + 1) * lemin->conv.x - FONT_SHIFT;
	sdl->rect.y = (room->y - lemin->min.y + 1) * lemin->conv.y - FONT_SHIFT;
	if (sdl->rect.x < 0)
		sdl->rect.x = 0;
	if (sdl->rect.y < 0)
		sdl->rect.y = 0;
	sdl->rect.w = FONT_SIZE;
	sdl->rect.h = FONT_SIZE;
}

void	highligh_rooms(t_room *room, t_room *n, t_lem_in *lemin, t_sdl *sdl)
{
	if (!sdl_listen(lemin, sdl))
		sdl_end_lem_in(lemin);
	SDL_UpdateTexture(lemin->sdl->tex, NULL, lemin->sdl->pixels,
		lemin->sdl->pitch);
	sdl_set_rect(room, lemin, sdl);
	sdl_render_text(sdl, room, 1);
	SDL_RenderPresent(lemin->sdl->ren);
	sdl->until = time(NULL) + 1;
	while (sdl->debug && time(NULL) < sdl->until)
		sdl_listen(lemin, sdl);
	if (!sdl_listen(lemin, sdl))
		sdl_end_lem_in(lemin);
	SDL_UpdateTexture(lemin->sdl->tex, NULL, lemin->sdl->pixels,
		lemin->sdl->pitch);
	sdl_set_rect(n, lemin, sdl);
	sdl_render_text(sdl, n, 1);
	SDL_RenderPresent(lemin->sdl->ren);
	sdl->until = time(NULL) + 1;
	while (sdl->debug && time(NULL) < sdl->until)
		sdl_listen(lemin, sdl);
}

void	unhighligh_rooms(t_room *room, t_room *n, t_lem_in *lemin, t_sdl *sdl)
{
	if (!sdl_listen(lemin, sdl))
		sdl_end_lem_in(lemin);
	SDL_UpdateTexture(lemin->sdl->tex, NULL, lemin->sdl->pixels,
		lemin->sdl->pitch);
	sdl_set_rect(room, lemin, sdl);
	sdl_render_text(sdl, room, 0);
	SDL_RenderPresent(lemin->sdl->ren);
	sdl->until = time(NULL) + 1;
	while (sdl->debug && time(NULL) < sdl->until)
		sdl_listen(lemin, sdl);
	if (!sdl_listen(lemin, sdl))
		sdl_end_lem_in(lemin);
	SDL_UpdateTexture(lemin->sdl->tex, NULL, lemin->sdl->pixels,
		lemin->sdl->pitch);
	sdl_set_rect(n, lemin, sdl);
	sdl_render_text(sdl, n, 0);
	SDL_RenderPresent(lemin->sdl->ren);
	sdl->until = time(NULL) + 1;
	while (sdl->debug && time(NULL) < sdl->until)
		sdl_listen(lemin, sdl);
}

void	sdl_draw_ant_move(t_room *dst, t_room *src, t_lem_in *lemin, t_sdl *sdl)
{
	SDL_UpdateTexture(lemin->sdl->tex, NULL, lemin->sdl->pixels,
		lemin->sdl->pitch);
	sdl_set_rect(src, lemin, sdl);
	sdl_render_text(sdl, src, 0);
	sdl_set_rect(dst, lemin, sdl);
	sdl_render_text(sdl, dst, 0);
	SDL_RenderPresent(lemin->sdl->ren);
	sdl->until = time(NULL) + 1;
	while (sdl->debug && time(NULL) < sdl->until)
		sdl_listen(lemin, sdl);
	unhighligh_rooms(src, dst, lemin, sdl);
}
