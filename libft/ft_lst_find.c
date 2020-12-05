/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_find.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koparker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:07:55 by koparker          #+#    #+#             */
/*   Updated: 2019/02/01 17:01:10 by koparker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_find(t_list **lst, char *value)
{
	t_list	*tmp;

	if (!lst || !(*lst) || !value)
		return (NULL);
	tmp = *lst;
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->content, value) == 0)
			return (tmp->content);
		tmp = tmp->next;
	}
	return (NULL);
}
