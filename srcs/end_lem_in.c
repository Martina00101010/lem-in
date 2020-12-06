/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_lem_in.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 14:24:09 by pberge            #+#    #+#             */
/*   Updated: 2020/12/05 18:12:59 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	end_with_error(void)
{
	ft_putendl("ERROR");
	exit(0);
}

void	end_parser(/*t_buffer *buffer, */char *line)
{
	// t_chunk	*lst;
	// t_chunk	*tmp;

	if (line != NULL)
		free(line);
	// lst = buffer->start;
	// while (lst)
	// {
	// 	tmp = lst;
	// 	lst = lst->next;
	// 	ft_bzero(tmp, sizeof(t_chunk));
	// 	free(tmp);
	// }
	// ft_bzero(buffer, sizeof(t_buffer));
	ft_putendl("ERROR");
	exit(1);
}

void	end_lem_in(t_lem_in *lemin)
{
	free(lemin->rooms);
}
