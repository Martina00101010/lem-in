/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <pberge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 05:08:21 by pberge            #+#    #+#             */
/*   Updated: 2020/11/23 23:19:08 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		sdl_hook(t_lem_in *lemin, t_sdl *sdl, SDL_Scancode scode)
{
	if (scode == SDL_SCANCODE_S)
		sdl->pause ^= 1;
	if (scode == SDL_SCANCODE_D)
		sdl->debug ^= 1;
}

void		sdl_loop(t_lem_in *lemin, t_sdl *sdl, int *paths, int *ant_number)
{
	SDL_Event	e;

	while (sdl->running)
	{
		if (SDL_PollEvent(&e))
		{
			if (e.key.keysym.scancode == SDL_SCANCODE_ESCAPE ||
				(e.type == SDL_WINDOWEVENT &&
					e.window.event == SDL_WINDOWEVENT_CLOSE))
			{
				sdl->running = 0;
				break ;
			}
			if (e.type = SDL_KEYDOWN)
				sdl_hook(lemin, sdl, e.key.keysym.scancode);
		}
		if (lemin->end_room->ant < lemin->ants_at_start && !sdl->pause)
		{
			sdl->pause = sdl->debug ? 1 : 0;
			move_ants(lemin, paths, ant_number);
		}
	}
}
