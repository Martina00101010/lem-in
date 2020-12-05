/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koparker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 11:41:27 by koparker          #+#    #+#             */
/*   Updated: 2019/02/12 16:10:27 by koparker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	void	*res;

	i = 0;
	res = b;
	while (i < len)
	{
		*(unsigned char *)b = (unsigned char)c;
		i++;
		b++;
	}
	return (res);
}
