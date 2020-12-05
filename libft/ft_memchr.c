/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koparker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:16:00 by koparker          #+#    #+#             */
/*   Updated: 2019/02/01 17:03:40 by koparker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned const char	*chs;

	i = 0;
	chs = s;
	while (i < n)
	{
		if (chs[i] == (unsigned char)c)
			return ((void *)&chs[i]);
		i++;
	}
	return (NULL);
}
