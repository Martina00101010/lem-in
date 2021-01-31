/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <pberge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 05:08:21 by pberge            #+#    #+#             */
/*   Updated: 2021/01/26 13:01:36 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		sdl_hook(t_sdl *sdl, SDL_Scancode scode)
{
	if (scode == SDL_SCANCODE_S)
		sdl->pause = 1;
	if (scode == SDL_SCANCODE_G)
		sdl->pause = 0;
	if (scode == SDL_SCANCODE_D)
		sdl->debug = 1;
	if (scode == SDL_SCANCODE_F)
		sdl->debug = 0;
}

void		sdl_end_lem_in(t_lem_in *lemin)
{
	end_lem_in(lemin);
	exit(0);
}

int			sdl_listen(t_lem_in *lemin, t_sdl *sdl)
{
	SDL_Event	e;

	if (SDL_PollEvent(&e))
	{
		if (e.key.keysym.scancode == SDL_SCANCODE_ESCAPE ||
			(e.type == SDL_WINDOWEVENT &&
				e.window.event == SDL_WINDOWEVENT_CLOSE))
		{
			lemin->sdl->running = 0;
			sdl_end_lem_in(lemin);
		}
		if (e.type == SDL_KEYDOWN)
			sdl_hook(sdl, e.key.keysym.scancode);
	}
	return (1);
}

void		sdl_loop(t_lem_in *lemin, t_sdl *sdl)
{
	while (sdl->running)
	{
		if (!sdl_listen(lemin, sdl))
			break ;
		if (lemin->end_room->ant < lemin->ants_at_start &&
			!sdl->pause
		)
		{
			sdl->pause = sdl->debug ? 1 : 0;
			sdl_move_ants(lemin);
		}
	}
}
