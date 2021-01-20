/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_input_forks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 14:22:26 by pberge            #+#    #+#             */
/*   Updated: 2021/01/16 14:22:41 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		print_ant_move(char *room_name, int ant_number)
{
	ft_putstr("\x1B[96mL");
	ft_putnbr(ant_number);
	ft_putstr("\x1B[0m-\x1B[34m");
	ft_putstr(room_name);
	ft_putstr("\x1B[0m ");
}

void		print_file_contents(t_linked *contents)
{
	t_linked	*tmp;

	while (contents->next != NULL)
		contents = contents->next;
	while (contents != NULL)
	{
		tmp = contents;
		ft_putstr(contents->data);
		ft_putchar('\n');
		contents = contents->prev;
		free(tmp->data);
		free(tmp);
	}
	ft_putchar('\n');
}

t_linked	*linked_new(char *str)
{
	t_linked	*l;

	l = (t_linked *)ft_memalloc(sizeof(t_linked));
	l->data = str;
	return (l);
}

void		linked_add(t_linked **head, char *str)
{
	t_linked	*l;

	if (*head == NULL)
		*head = linked_new(str);
	else
	{
		l = linked_new(str);
		(*head)->prev = l;
		l->next = *head;
		*head = l;
	}
}

void		check_path_to_end_exists(t_lem_in *lemin)
{
	if (lemin->start_room->exit == NULL)
		end_with_error(NULL, lemin, NULL);
}
