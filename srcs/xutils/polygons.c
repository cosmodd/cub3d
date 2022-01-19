/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polygons.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrattez <mrattez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 13:45:54 by mrattez           #+#    #+#             */
/*   Updated: 2022/01/18 11:07:21 by mrattez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xutils.h"
#include "maths.h"
#include <stdarg.h>
#include <limits.h>

static int	edge(t_point a, t_point b, t_point p)
{
	return ((p.x - a.x) * (b.y - a.y) - (p.y - a.y) * (b.x - a.x));
}

// void	draw_square(t_image img, t_point origin, int size, int color)
// {
// 	int	y;
// 	int	x;

// 	y = 0;
// 	while (y < size)
// 	{
// 		x = 0;
// 		while (x < size)
// 		{
// 			put_pixel(img, origin.x + x, origin.y + y, color);
// 			x++;
// 		}
// 		y++;
// 	}
// }

void	draw_rect(t_image image, t_point start, t_point end, int color)
{
	int	x;
	int	y;

	y = max(start.y, 0);
	while (y < min(end.y, image.height))
	{
		x = max(start.x, 0);
		while (x < min(end.x, image.width))
		{
			put_pixel(image, x++, y, color);
		}
		y++;
	}
}

void	draw_triangle(t_image image, t_point a, t_point b, t_point c)
{
	int	x;
	int	y;
	int	w;
	int	h;

	w = max(a.x, max(b.x, c.x));
	h = max(a.y, max(b.y, c.y));
	y = min(a.y, min(b.y, c.y));
	while (y < h)
	{
		x = min(a.x, min(b.x, c.x));
		while (x < w)
		{
			if (edge(a, b, (t_point){x, y}) >= 0
			&& edge(b, c, (t_point){x, y}) >= 0
			&& edge(c, a, (t_point){x, y}) >= 0)
				put_pixel(image, x, y, 0xFFFFFF);
			x++;
		}
		y++;
	}
}

void	draw_line(t_image image, t_point origin, t_point dest, int color)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;

	dx = abs(dest.x - origin.x);
	dy = abs(dest.y - origin.y);
	sx = origin.x < dest.x ? 1 : -1;
	sy = origin.y < dest.y ? 1 : -1;
	err = (dx > dy ? dx : -dy) / 2;
	while (1)
	{
		put_pixel(image, origin.x, origin.y, color);
		if (origin.x == dest.x && origin.y == dest.y)
			break ;
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			origin.x += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			origin.y += sy;
		}
	}
}
