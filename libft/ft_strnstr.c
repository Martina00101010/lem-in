/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koparker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 20:19:59 by koparker          #+#    #+#             */
/*   Updated: 2019/02/06 16:22:24 by koparker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;
	size_t k;

	k = 0;
	if (needle[k] == '\0')
		return ((char *)haystack);
	while (haystack[k])
	{
		j = 0;
		i = k;
		while (haystack[i] == needle[j] && needle[j] != '\0' && i < len)
		{
			i++;
			j++;
		}
		if (needle[j] == '\0')
			return ((char *)&haystack[k]);
		k++;
	}
	return (NULL);
}
