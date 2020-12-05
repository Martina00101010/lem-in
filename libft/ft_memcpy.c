/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koparker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:30:48 by koparker          #+#    #+#             */
/*   Updated: 2019/02/01 17:04:07 by koparker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	const char	*chsrc;
	char		*chdst;

	i = 0;
	chsrc = src;
	chdst = dst;
	while (i < n)
	{
		chdst[i] = chsrc[i];
		i++;
	}
	return (dst);
}
