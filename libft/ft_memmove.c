/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koparker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 17:50:15 by koparker          #+#    #+#             */
/*   Updated: 2019/02/01 17:04:39 by koparker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*chsrc;
	char		*chdst;

	chsrc = src;
	chdst = dst;
	if (chdst > chsrc)
		return ((void *)ft_memcpy_backwards(chdst, chsrc, len));
	if (chdst < chsrc)
		return ((void *)ft_memcpy(chdst, chsrc, len));
	else
		return (dst);
}
