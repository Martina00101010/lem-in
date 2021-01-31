/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 02:41:32 by pberge            #+#    #+#             */
/*   Updated: 2020/11/23 02:42:44 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Initialisation of SDL video & audio, window, renderer
*/

char	*start_sdl(t_sdl *sdl)
{
	sdl->pitch = WIDTH * 4;
	sdl->running = 1;
	sdl->pause = 1;
	sdl->debug = 1;
	sdl->until = time(NULL);
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
		return ((char *)SDL_GetError());
	return (NULL);
}

char	*init_font(t_sdl *sdl)
{
	if (TTF_Init() == -1)
		return ((char *)TTF_GetError());
	sdl->font = TTF_OpenFont(FONT_FILE, FONT_SIZE);
	if (sdl->font == NULL)
		return ((char *)TTF_GetError());
	sdl->rect = (SDL_Rect){ 0, 0, 0, 0 };
	return (NULL);
}

/*
**   sdl window creation
*/

char	*open_window(t_sdl *sdl)
{
	if (!(sdl->win = SDL_CreateWindow(TITLE,
										SDL_WINDOWPOS_UNDEFINED,
										SDL_WINDOWPOS_UNDEFINED,
										WIDTH,
										HEIGHT,
										SDL_WINDOW_ALLOW_HIGHDPI)))
		return ((char *)SDL_GetError());
	if (!(sdl->ren = SDL_CreateRenderer(sdl->win, RENDERING_DRIVER, NO_FLAGS)))
		return ((char *)SDL_GetError());
	if (!(sdl->tex = SDL_CreateTexture(sdl->ren,
										SDL_PIXELFORMAT_ARGB8888,
										SDL_TEXTUREACCESS_STREAMING,
										WIDTH,
										HEIGHT)))
		return ((char *)SDL_GetError());
	return (init_font(sdl));
}
