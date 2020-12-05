/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koparker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 19:53:00 by koparker          #+#    #+#             */
/*   Updated: 2019/02/01 17:02:02 by koparker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstpop_front(t_list **alst)
{
	t_list *head;

	head = *alst;
	(*alst) = (*alst)->next;
	free(head);
	return (head);
}
