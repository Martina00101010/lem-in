/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koparker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:08:45 by koparker          #+#    #+#             */
/*   Updated: 2019/02/01 17:01:20 by koparker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(f)(t_list *elem))
{
	t_list	*new_lst;
	t_list	*tmp_node;

	new_lst = NULL;
	while (lst)
	{
		tmp_node = f(lst);
		if (tmp_node != NULL)
			ft_lstpush_back(&new_lst, tmp_node);
		else
		{
			if (new_lst != NULL)
			{
				ft_lstdel(&new_lst, &ft_lstfree_node);
				return (NULL);
			}
		}
		lst = lst->next;
	}
	return (new_lst);
}
