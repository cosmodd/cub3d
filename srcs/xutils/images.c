/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrattez <mrattez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 10:44:04 by mrattez           #+#    #+#             */
/*   Updated: 2021/12/21 11:07:10 by mrattez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xutils.h"

t_image	new_image(void *mlx, int width, int height)
{
	t_image	image;

	image.ptr = mlx_new_image(mlx, width, height);
	image.addr = mlx_get_data_addr(
			image.ptr,
			&image.bits_per_pixel,
			&image.line_length,
			&image.endian);
	return (image);
}

void	put_pixel(t_image image, int x, int y, int color)
{
	char	*destination;

	destination = image.addr;
	destination += y * image.line_length + x * (image.bits_per_pixel / 8);
	*(unsigned int *)destination = color;
}
