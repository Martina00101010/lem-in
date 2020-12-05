/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koparker <koparker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:02:21 by koparker          #+#    #+#             */
/*   Updated: 2019/09/23 19:37:56 by koparker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char *mem;

	if (!(mem = (unsigned char *)malloc(sizeof(*mem) * size)))
		return (NULL);
	ft_bzero(mem, size);
	return (mem);
}
