/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinsert_at.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koparker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 20:29:53 by koparker          #+#    #+#             */
/*   Updated: 2019/02/01 17:00:59 by koparker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstinsert_at(t_list **alst, t_list *node, size_t pos)
{
	t_list	*prev;
	t_list	*post;

	if (*alst == NULL)
		ft_lstadd(alst, node);
	else if (pos == 0)
		ft_lstadd(alst, node);
	else if (((*alst)->next == NULL && pos == 1) || (pos == ft_lstsize(*alst)))
		ft_lstpush_back(alst, node);
	else
	{
		prev = ft_lstat(*alst, pos - 1);
		post = ft_lstat(*alst, pos);
		prev->next = node;
		node->next = post;
	}
}
