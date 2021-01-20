/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 17:47:09 by pberge            #+#    #+#             */
/*   Updated: 2020/12/20 17:54:32 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	check_graph(t_lem_in *lemin, t_link *links)
{
	t_room	*start;

	start = lemin->start_room;
	if (lemin->start_room->exit_count == 0)
		end_with_error(NULL, lemin, links);
}
