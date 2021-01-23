/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:51:54 by pberge            #+#    #+#             */
/*   Updated: 2021/01/21 17:52:27 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	sdl_destroy(t_sdl *sdl)
{
	if (sdl == NULL)
		return ;
	if (sdl->pixels != NULL)
		free(sdl->pixels);
	if (sdl->tex != NULL)
		SDL_DestroyTexture(sdl->tex);
	if (sdl->ren != NULL)
		SDL_DestroyRenderer(sdl->ren);
	if (sdl->win != NULL)
		SDL_DestroyWindow(sdl->win);
	TTF_CloseFont(sdl->font);
	TTF_Quit();
	SDL_Quit();
	free(sdl);
	ft_bzero(sdl, sizeof(t_sdl));
}
