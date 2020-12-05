/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koparker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 22:04:35 by koparker          #+#    #+#             */
/*   Updated: 2019/02/01 17:02:22 by koparker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush_back(t_list **alst, t_list *new)
{
	t_list *tmp;

	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	tmp = *alst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}
