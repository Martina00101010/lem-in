/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koparker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 18:00:20 by koparker          #+#    #+#             */
/*   Updated: 2019/02/01 16:59:10 by koparker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_size(int n)
{
	size_t	i;
	long	tmp;

	i = 1;
	tmp = n;
	if (tmp < 0)
	{
		tmp *= -1;
		i++;
	}
	while (tmp / 10 != 0)
	{
		tmp /= 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	size_t	i;
	long	tmp;
	char	*res;
	size_t	size;

	i = 0;
	tmp = n;
	size = ft_size(n);
	if (!(res = (char *)malloc(sizeof(*res) * (size + 1))))
		return (NULL);
	res[size] = '\0';
	if (tmp == 0)
		res[0] = '0';
	if (tmp < 0)
		tmp *= -1;
	while (tmp > 0)
	{
		res[size - i - 1] = tmp % 10 + '0';
		tmp /= 10;
		i++;
	}
	if (n < 0)
		res[0] = '-';
	return (res);
}
