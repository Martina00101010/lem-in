/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koparker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:06:01 by koparker          #+#    #+#             */
/*   Updated: 2019/02/01 17:00:00 by koparker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;

	if (alst && del)
	{
		while ((*alst) != NULL)
		{
			tmp = *alst;
			del((*alst)->content, (*alst)->content_size);
			(*alst) = (*alst)->next;
			free(tmp);
		}
		free(*alst);
		*alst = NULL;
	}
}
