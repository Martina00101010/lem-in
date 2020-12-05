/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koparker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 19:01:37 by koparker          #+#    #+#             */
/*   Updated: 2019/02/01 17:01:47 by koparker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstpop_back(t_list **alst)
{
	size_t	size;
	t_list	*tail;
	t_list	*tmp;

	if (*alst == NULL)
		return (NULL);
	if ((*alst)->next == NULL)
	{
		tail = *alst;
		*alst = NULL;
		free(tail);
		return (tail);
	}
	size = ft_lstsize(*alst);
	tail = ft_lstat(*alst, size - 1);
	tmp = ft_lstat(*alst, size - 2);
	tmp->next = NULL;
	free(tail);
	return (tail);
}
