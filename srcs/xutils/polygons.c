/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polygons.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrattez <mrattez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 13:45:54 by mrattez           #+#    #+#             */
/*   Updated: 2021/12/21 14:42:25 by mrattez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xutils.h"

void	draw_square(t_image img, t_point origin, int size, int color)
{
	int	y;
	int	x;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			put_pixel(img, origin.x + x, origin.y + y, color);
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
