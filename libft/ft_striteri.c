/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koparker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 21:19:07 by koparker          #+#    #+#             */
/*   Updated: 2019/02/06 16:19:44 by koparker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t i;
	size_t len;

	if (s != NULL && f != NULL)
	{
		i = 0;
		len = ft_strlen(s);
		while (i < len)
		{
			f(i, &(s[i]));
			i++;
		}
	}
}
