/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koparker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 23:05:45 by koparker          #+#    #+#             */
/*   Updated: 2020/03/14 18:44:39 by koparker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_overflow_check(int n, int sign)
{
	int	tmp;

	tmp = n;
	if (tmp * 10 / 10 != tmp && sign == 0)
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	int		i;
	long	res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i++] - '0';
		if (ft_overflow_check(res, sign) == 1)
			return (res);
		if (res < 0)
			return (sign == 1 ? -1 : 0);
	}
	if (sign == -1)
		return ((int)(-res));
	return ((int)res);
}
