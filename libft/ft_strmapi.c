/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koparker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 17:52:46 by koparker          #+#    #+#             */
/*   Updated: 2019/02/06 16:20:56 by koparker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*res;

	if (s == NULL)
		return (NULL);
	i = 0;
	if (!(res = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (i < ft_strlen(s))
	{
		res[i] = f(i, s[i]);
		i++;
	}
	return (res);
}
