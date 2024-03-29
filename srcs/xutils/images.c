/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrattez <mrattez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 10:44:04 by mrattez           #+#    #+#             */
/*   Updated: 2022/01/26 09:39:35 by mrattez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xutils.h"

t_image	new_image(void *mlx, int width, int height)
{
	t_image	image;

	image.width = width;
	image.height = height;
	image.ptr = mlx_new_image(mlx, width, height);
	image.addr = mlx_get_data_addr(
			image.ptr,
			&image.bits_per_pixel,
			&image.line_length,
			&image.endian);
	return (image);
}

void	scale_up(void *mlx, t_image *image, int factor)
{
	t_image	scaled;
	int		x;
	int		y;

	scaled = new_image(mlx, image->width * factor, image->height * factor);
	y = -1;
	while (++y < image->height * factor)
	{
		x = -1;
		while (++x < image->width * factor)
			put_pixel(scaled, x, y, get_pixel(*image, x / factor, y / factor));
	}
	mlx_destroy_image(mlx, image->ptr);
	*image = scaled;
}

t_image	from_png_image(void *mlx, char *path)
{
	t_image	image;

	image.ptr = mlx_png_file_to_image(mlx, path, &image.width, &image.height);
	image.addr = mlx_get_data_addr(
			image.ptr,
			&image.bits_per_pixel,
			&image.line_length,
			&image.endian);
	return (image);
}

t_image	from_xpm_image(void *mlx, char *path)
{
	t_image	image;

	image.ptr = mlx_xpm_file_to_image(mlx, path, &image.width, &image.height);
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

	if (x < 0 || x >= image.width || y < 0 || y >= image.height)
		return ;
	destination = image.addr;
	destination += y * image.line_length + x * (image.bits_per_pixel / 8);
	*(unsigned int *)destination = color;
}

int	get_pixel(t_image image, int x, int y)
{
	char	*source;

	if (x < 0 || x >= image.width || y < 0 || y >= image.height)
		return (0);
	source = image.addr;
	source += y * image.line_length + x * (image.bits_per_pixel / 8);
	return (*(unsigned int *)source);
}
