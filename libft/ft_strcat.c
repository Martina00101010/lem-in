/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koparker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 21:15:14 by koparker          #+#    #+#             */
/*   Updated: 2019/02/01 17:08:46 by koparker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t i;
	size_t j;
	size_t len;

	j = 0;
	i = ft_strlen(s1);
	len = ft_strlen(s1) + ft_strlen(s2);
	while (i < len)
		s1[i++] = s2[j++];
	s1[i] = '\0';
	return (s1);
}
