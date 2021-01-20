/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_room_name.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 15:05:43 by pberge            #+#    #+#             */
/*   Updated: 2020/12/27 15:05:54 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** проверка, что символ имени - буква, цифра или нижнее подчёркивание
*/

int		ft_issymbol(char c)
{
	if (ft_isalpha(c) || ft_isdigit(c) || c == '_')
		return (1);
	return (0);
}

/*
** читаем название комнаты.
** название может состоять из букв, цифр и нижнего подчеркивания.
** название комнаты не может начинаться на 'L'
*/

char	*get_room_name(char **line, short len)
{
	short	i;
	char	*name;

	i = -1;
	if (len <= 0 || **line == 'L')
		return (NULL);
	name = ft_strnew(len);
	if (name == NULL)
		return (NULL);
	while (++i < len)
	{
		if (!ft_issymbol(**line))
		{
			free(name);
			return (NULL);
		}
		name[i] = **line;
		(*line)++;
	}
	name[i] = '\0';
	return (name);
}
