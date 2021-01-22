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
	t_sdl		sdl;

	ft_bzero(&lemin, sizeof(t_lem_in));
	ft_bzero(&sdl, sizeof(t_sdl));
	if (flag == DRAW)
		lemin.sdl = &sdl;
	lemin.allocated = MAX_ROOMS_NUM;
	lemin.flag = flag;
	read_from_standard_output(&lemin);
	remove_input_forks(&lemin);
	remove_dead_ends(lemin.start_room, lemin.end_room, &lemin);
	remove_output_forks(&lemin);
	remove_dead_ends(lemin.start_room, lemin.end_room, &lemin);
	check_path_to_end_exists(&lemin);
	if (lemin.flag == DRAW)
		draw_best_paths(&lemin);
	if (flag == 0)
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
	else if (argc == 2 && ft_strcmp(argv[1], "-d") == 0)
		flag = 2;
	else if (argc != 1 || argv == NULL)
		print_error();
	lem_in(flag);
	return (0);
}
