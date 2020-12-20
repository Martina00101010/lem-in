/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 23:10:29 by pberge            #+#    #+#             */
/*   Updated: 2020/12/05 23:10:31 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

/*
** когда строка не влезает, увеличиваем буффер
*/

/*char	*manage_too_large_string(t_buffer *buffer, char *line, size_t *len)
{
	size_t	copy;
	t_chunk	*new;
    // char    *tmp;

    // tmp = line;
	while (buffer->cursor + *len >= BUFFER_SIZE)
	{
		copy = BUFFER_SIZE - buffer->cursor;
		ft_memcpy(&buffer->current->chunk[buffer->cursor], line, copy);
		new = ft_memalloc(sizeof(t_chunk));
        // if (new == NULL)
            // end_parser(buffer, tmp);
		line += copy;
		*len -= copy;
		buffer->current->next = new;
		buffer->current = new;
		buffer->cursor = 0;
	}
    return (line);
}*/

/*
** сохраняем строку из файла в буффер
*/

/*void	save_line(char *line, t_buffer *buffer)
{
	size_t	len;

	len = ft_strlen(line) + 1;
	if (buffer->start == NULL)
	{
		buffer->start = ft_memalloc(sizeof(t_chunk));
        // if (buffer->start == NULL)
			// end_parser(buffer, line);
		buffer->current = buffer->start;
	}
	line = manage_too_large_string(buffer, line, &len);
	ft_memcpy(&buffer->current->chunk[buffer->cursor], line, len);
	buffer->cursor = len;
    buffer->current->chunk[buffer->cursor] = '\n';
}*/