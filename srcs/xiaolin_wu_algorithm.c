/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xiaolin_wu_algorithm.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 17:34:46 by pberge            #+#    #+#             */
/*   Updated: 2019/05/10 17:46:33 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include <stdlib.h>

static void		ft_swap_ints(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static double	calc_gradient(t_point *beg, t_point *end, int steep)
{
	double	dx;
	double	dy;
	double	gradient;

	if (steep)
	{
		ft_swap_ints(&beg->x, &beg->y);
		ft_swap_ints(&end->x, &end->y);
	}
	if (beg->x > end->x)
	{
		ft_swap_ints(&beg->x, &end->x);
		ft_swap_ints(&beg->y, &end->y);
	}
	dx = end->x - beg->x;
	dy = end->y - beg->y;
	gradient = (dx == 0) ? 1.0 : dy / dx;
	return (gradient);
}

static void		draw_line(t_point beg, t_point end, int *data, int steep)
{
	int		x;
	double	y;
	double	gradient;

	gradient = calc_gradient(&beg, &end, steep);
	x = beg.x - 1;
	y = beg.y;
	if (steep)
	{
		while (++x <= end.x && y - 1 >= 0)
		{
			data[(int)y + x * IMGWIDTH] = (int)(RFPART(y)) | GREY;
			data[((int)y - 1) + x * IMGWIDTH] = (int)(FPART(y)) | GREY;
			y += gradient;
		}
	}
	else
	{
		while (++x <= end.x && y - 1 >= 0)
		{
			data[x + (int)y * IMGWIDTH] = (int)(RFPART(y)) | GREY;
			data[x + ((int)y - 1) * IMGWIDTH] = (int)(FPART(y)) | GREY;
			y += gradient;
		}
	}
}

void			line(t_point beg, t_point end, int *data)
{
	int		steep;

	steep = (abs(end.y - beg.y) > abs(end.x - beg.x)) ? 1 : 0;
	draw_line(beg, end, data, steep);
}
