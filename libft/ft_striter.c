/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koparker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 20:51:56 by koparker          #+#    #+#             */
/*   Updated: 2019/02/01 17:11:07 by koparker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	size_t i;
	size_t len;

	if (s != NULL && f != NULL)
	{
		i = 0;
		len = ft_strlen(s);
		while (i < len)
		{
			f(&s[i]);
			i++;
		}
	}
}
