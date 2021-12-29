/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xutils.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrattez <mrattez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 10:45:08 by mrattez           #+#    #+#             */
/*   Updated: 2021/12/29 10:17:25 by mrattez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XUTILS_H
# define XUTILS_H

# include "mlx.h"
# include <stdlib.h>

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_image
{
	void	*ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

// Color utils
int		rgb(int r, int g, int b);
int		rgba(int r, int g, int b, int a);
int		lighten(int color, double percentage);
int		darken(int color, double percentage);

// Image manipulation
t_image	new_image(void *mlx, int width, int height);
void	put_pixel(t_image image, int x, int y, int color);

// Polygons
void	draw_square(t_image img, t_point origin, int size, int color);
void	draw_triangle(t_image image, t_point a, t_point b, t_point c);
void	draw_line(t_image image, t_point origin, t_point dest, int color);

#endif
