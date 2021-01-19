/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 11:58:29 by pberge            #+#    #+#             */
/*   Updated: 2020/12/05 15:20:13 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	lem_in(void)
{
	t_lem_in	lemin;

	ft_bzero(&lemin, sizeof(t_lem_in));
	read_from_standard_output(&lemin);
	remove_input_forks(&lemin);
	debug_graph(&lemin);
	end_lem_in(&lemin);
}

int		main(int argc, char **argv)
{
	if (argc != 1 || argv == NULL)
		print_error();
	lem_in();
	return (0);
}
