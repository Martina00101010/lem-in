/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koparker <koparker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 20:52:16 by koparker          #+#    #+#             */
/*   Updated: 2019/09/23 20:01:15 by koparker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_word(char const *s, char c)
{
	int lenght;

	lenght = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != '\0')
			lenght++;
		while (*s != '\0' && *s != c)
			s++;
	}
	return (lenght + 1);
}

static int		ft_count_letter(char const *s, char c)
{
	int lenght;

	lenght = 0;
	while (*s != c && *s++ != '\0')
		lenght++;
	return (lenght);
}

static char		**ft_delete(char ***a)
{
	int i;

	i = 0;
	while (*a[i] != NULL)
	{
		ft_strdel(&(*a[i]));
		*a[i] = NULL;
		i++;
	}
	ft_memdel((void *)(&(*a)));
	*a = NULL;
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		i;
	int		lenght;

	lenght = 0;
	i = 0;
	if (s == NULL ||
			!(arr = (char **)malloc(sizeof(*arr) * ft_count_word(s, c))))
		return (NULL);
	while (*s != '\0')
	{
		if (*s != c)
		{
			lenght = ft_count_letter(s, c);
			if ((arr[i] = ft_strnew(lenght)) == NULL)
				return (ft_delete(&arr));
			arr[i] = ft_strncpy(arr[i], s, lenght);
			arr[i][lenght] = '\0';
			i++;
			s += lenght - 1;
		}
		s++;
	}
	arr[i] = 0;
	return (arr);
}
