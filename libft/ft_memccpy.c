/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koparker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:39:58 by koparker          #+#    #+#             */
/*   Updated: 2019/02/01 17:03:27 by koparker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t		i;
	char		*chdst;
	const char	*chsrc;

	i = 0;
	chdst = (char *)dst;
	chsrc = (const char *)src;
	while (i < n)
	{
		chdst[i] = chsrc[i];
		if (chsrc[i] == (char)c)
			return ((void *)&chdst[i + 1]);
		i++;
	}
	return (NULL);
}
