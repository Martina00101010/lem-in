/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 14:55:59 by pberge            #+#    #+#             */
/*   Updated: 2020/11/23 02:13:55 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SDL_H
# define FT_SDL_H

/*
**	SDL
*/

# if defined __APPLE__
#  include "SDL.h"
#  include "SDL_ttf.h"
#  include "SDL_image.h"
# elif __linux__
#  include <SDL2/SDL.h>
#  include <SDL2/SDL_ttf.h>
#  include <SDL2/SDL_image.h>
# endif

# define TITLE				"Lem-in"
# define NO_FLAGS			0
# define RENDERING_DRIVER	0
# define SILENT_EXIT		NULL
# define WIDTH				600
# define HEIGHT				600
# define DS					WIDTH * HEIGHT

typedef struct	s_sdl
{
	SDL_Window			*win;
	SDL_Renderer		*ren;
	SDL_Texture			*tex;
	TTF_Font			*font;
	SDL_Rect			rect;
	int					pitch;
	int					*pixels;
	char				running;
	char				pause;
	char				debug;
}				t_sdl;

char			*start_sdl(t_sdl *sdl);
char			*open_window(t_sdl *sdl);
void			sdl_destroy(t_sdl *sdl);
void			sdl_render(t_sdl *sdl);

#endif
