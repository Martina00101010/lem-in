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

// void		sdl_hook(t_wolf *wolf, t_sdl *sdl, SDL_Scancode scode)
// {
// 	if (scode == SDL_SCANCODE_3)
// 		change_textures_pack(wolf, sdl);
// 	if (scode == SDL_SCANCODE_1)
// 		sdl_play_audio(sdl);
// 	if (scode == SDL_SCANCODE_2)
// 		sdl_stop_audio(sdl);
// 	if (scode == SDL_SCANCODE_S)
// 	{
// 		sdl_play_effect(sdl);
// 		change_level(wolf);
// 	}
// }

void		sdl_loop(t_lem_in *lemin, t_sdl *sdl)
{
	SDL_Event	e;

	(void)lemin;
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
			// if (e.type == SDL_KEYDOWN)
			// 	sdl_hook(lemin, sdl, e.key.keysym.scancode);
		}
	}
}
