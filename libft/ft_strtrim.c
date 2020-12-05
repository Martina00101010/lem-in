/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koparker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 20:14:14 by koparker          #+#    #+#             */
/*   Updated: 2019/02/06 16:24:01 by koparker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_skip_start(char const *s)
{
	size_t i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	return (i);
}

static size_t	ft_skip_end(char const *s)
{
	size_t i;

	i = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i--;
	return (i);
}

char			*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	size_t	n;
	char	*res;

	if (s == NULL)
		return (NULL);
	i = ft_skip_start(s);
	if (i == ft_strlen(s))
	{
		if (!(res = ft_strnew(0)))
			return (NULL);
		return (res);
	}
	j = ft_skip_end(s);
	n = j - i + 1;
	if (!(res = ft_strnew(n)))
		return (NULL);
	j = 0;
	while (j < n)
		res[j++] = s[i++];
	return (res);
}
