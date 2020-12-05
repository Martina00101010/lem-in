/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koparker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 17:35:20 by koparker          #+#    #+#             */
/*   Updated: 2019/02/06 16:23:36 by koparker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t i;
	size_t j;
	size_t k;

	i = 0;
	k = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i])
	{
		j = 0;
		i = k;
		while (haystack[i] == needle[j] && needle[j] != '\0')
		{
			i++;
			j++;
		}
		if (needle[j] == '\0')
			return ((char *)&(haystack[k]));
		k++;
	}
	return (NULL);
}
