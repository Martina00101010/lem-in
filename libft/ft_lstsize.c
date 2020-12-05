/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koparker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 21:50:08 by koparker          #+#    #+#             */
/*   Updated: 2019/02/01 17:02:36 by koparker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** null not included
*/

size_t	ft_lstsize(t_list *lst)
{
	size_t	i;
	t_list	*tmp;

	i = 0;
	tmp = lst;
	if (lst == NULL)
		return (0);
	while (tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
