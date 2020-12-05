/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koparker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 23:05:45 by koparker          #+#    #+#             */
/*   Updated: 2019/02/09 16:10:43 by koparker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_is_wsp(char wsp)
{
	if (wsp == ' ' || wsp == '\t' || wsp == '\n' ||
			wsp == '\v' || wsp == '\f' || wsp == '\r')
		return (1);
	return (0);
}

static int		ft_overflow_check(int n, int sign)
{
	int tmp;

	tmp = n;
	if (tmp * 10 / 10 != tmp && sign == 1)
		return (1);
	return (0);
}

static void		ft_fractional(const char *s, size_t *i, long double *res)
{
	size_t		k;

	(*i)++;
	k = 1;
	while (s[*i] != '\0' && s[*i] >= '0' && s[*i] <= '9')
		*res = *res + (s[(*i)++] - '0') / ft_pow(10, k++);
}

static void		ft_skip_spaces_sign(const char *str, size_t *i, int *sign)
{
	*i = 0;
	*sign = 1;
	while (ft_is_wsp(str[*i]))
		(*i)++;
	if (str[*i] == '-')
		*sign = -1;
	if (str[*i] == '-' || str[*i] == '+')
		(*i)++;
}

double			ft_atof(const char *str)
{
	size_t		i;
	long double res;
	int			sign;

	res = 0.0;
	ft_skip_spaces_sign(str, &i, &sign);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i++] - '0';
		if (ft_overflow_check(res, sign) == 1)
			return (res);
		if (res < 0)
			return (sign == 1 ? -1 : 0);
	}
	if (str[i] == '.')
		ft_fractional(str, &i, &res);
	if (sign == -1)
		return ((long double)(-res));
	return ((long double)res);
}
