/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koparker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:01:25 by koparker          #+#    #+#             */
/*   Updated: 2019/02/01 16:59:32 by koparker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstat(t_list *lst, size_t pos)
{
	size_t	i;
	t_list	*at;

	i = 0;
	at = lst;
	if (lst)
	{
		while (at->next && i != pos)
		{
			at = at->next;
			i++;
		}
	}
	return (at);
}
