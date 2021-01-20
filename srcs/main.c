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

#include "lem_in.h"

void	lem_in(char flag)
{
	t_lem_in	lemin;

	ft_bzero(&lemin, sizeof(t_lem_in));
	lemin.allocated = MAX_ROOMS_NUM;
	lemin.flag = flag;
	read_from_standard_output(&lemin);
	remove_input_forks(&lemin);
	remove_dead_ends(lemin.start_room, lemin.end_room, &lemin);
	remove_output_forks(&lemin);
	remove_dead_ends(lemin.start_room, lemin.end_room, &lemin);
	check_path_to_end_exists(&lemin);
	if (!flag)
		print_file_contents(&(lemin.contents));
	ready(&lemin);
	end_lem_in(&lemin);
}

int		main(int argc, char **argv)
{
	char	flag;

	flag = 0;
	if (argc == 2 && ft_strcmp(argv[1], "-v") == 0)
		flag = 1;
	else if (argc != 1 || argv == NULL)
		print_error();
	lem_in(flag);
	return (0);
}
