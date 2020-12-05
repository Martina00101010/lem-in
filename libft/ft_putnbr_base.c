/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koparker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 17:24:29 by koparker          #+#    #+#             */
/*   Updated: 2019/02/01 17:06:18 by koparker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(int n, int out)
{
	long tmp;

	tmp = n;
	if (tmp < 0)
	{
		tmp *= -1;
		ft_putchar_base('-', out);
	}
	if (tmp >= 10)
		ft_putnbr_base(tmp / 10, out);
	ft_putchar_base(tmp % 10 + '0', out);
}
