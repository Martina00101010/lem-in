/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_backwards.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koparker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 14:59:12 by koparker          #+#    #+#             */
/*   Updated: 2019/02/01 17:04:16 by koparker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy_backwards(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*chdst;
	const char	*chsrc;

	chdst = dst;
	chsrc = src;
	if (n == 0)
		return (dst);
	i = n - 1;
	while (i > 0)
	{
		chdst[i] = chsrc[i];
		i--;
	}
	chdst[i] = chsrc[i];
	return (dst);
}
