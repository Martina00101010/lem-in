/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koparker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 19:30:57 by koparker          #+#    #+#             */
/*   Updated: 2019/02/06 16:20:00 by koparker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	len1;
	size_t	len2;
	char	*res;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(res = ft_strnew(len1 + len2 + 2)))
		return (NULL);
	while (i < (len1 + len2))
	{
		if (i < len1)
			res[i] = s1[i];
		else if (i - len1 < len2)
			res[i] = s2[i - len1];
		i++;
	}
	return (res);
}
