/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koparker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 17:16:22 by koparker          #+#    #+#             */
/*   Updated: 2019/02/01 17:07:08 by koparker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_base(char const *s, int out)
{
	size_t i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i])
	{
		ft_putchar_base(s[i], out);
		i++;
	}
}
