/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrattez <mrattez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 09:47:43 by mrattez           #+#    #+#             */
/*   Updated: 2021/12/21 16:16:10 by mrattez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map[20][38] = {
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,1,0,1,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,1,0,1,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,1,0,1,0,1,0,0,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
};

int	key_hook(int keycode, t_cub *cub)
{
	(void) cub;
	if (keycode == ESC)
		exit(0);
	if (keycode == K_W)
		cub->player.pos.y -= 0.2;
	if (keycode == K_S)
		cub->player.pos.y += 0.2;
	if (keycode == K_D)
		cub->player.pos.x += 0.2;
	if (keycode == K_A)
		cub->player.pos.x -= 0.2;
	if (keycode == ARROW_LEFT)
		cub->player.dir = vec2_rotate(cub->player.dir, -M_PI_4);
	if (keycode == ARROW_RIGHT)
		cub->player.dir = vec2_rotate(cub->player.dir, M_PI_4);
	return (0);
}

void	init_cub(t_cub *cub)
{
	cub->mlx = mlx_init();
	cub->width = 1920;
	cub->height = 1080;
	cub->window = mlx_new_window(cub->mlx, cub->width, cub->height, "Cub3D");
	cub->frame = new_image(cub->mlx, cub->width, cub->height);
	cub->minimap = new_image(cub->mlx, cub->width / 5, cub->height / 5);
	cub->player.pos.x = 1.5;
	cub->player.pos.y = 1.5;
	cub->player.dir.x = 1;
	cub->player.dir.y = 0;
	cub->player.fov = rad(60);
}

t_vec2	h_ray(t_vec2 pos, t_vec2 dir)
{
	t_vec2	hit;
	double	dir_angle;
	int		dof;

	dir_angle = vec2_angle(dir);
	if (dir_angle == 0 || dir_angle == M_PI)
		return (-1);
	if (dir_angle > 0)
		hit = (t_vec2){(1 - pos.y % 1) / tan(dir_angle) + pos.x, (int)pos.y};
	else if (dir_angle < 0)
		hit = (t_vec2){(pos.y % 1) / tan(dir_angle) + pos.x, (int)pos.y + 1};
	else
		return (-1);
	dof = 0;
	while (dof < 8)
	{
		if (map[(int)hit.y][(int)hit.x])
			return (hit);
		else
		{
			
		}
	}
}

void	draw_floor_sky(t_cub *cub)
{
	int	x;
	int	y;

	y = 0;
	while (y < cub->height)
	{
		x = 0;
		while (x < cub->width)
		{
			if (y < cub->height / 2)
				put_pixel(cub->frame, x, y, 0x87CEEB);
			else
				put_pixel(cub->frame, x, y, 0x2E3136);
			x++;
		}
		y++;
	}
}

void	draw_minimap(t_cub *cub)
{
	t_player	player;
	int			y;
	int			x;
	int			size;

	player = cub->player;
	mlx_destroy_image(cub->mlx, cub->minimap.ptr);
	cub->minimap = new_image(cub->mlx, cub->width / 5, cub->height / 5);
	size = cub->height / 5 / 20;
	y = 0;
	while (y < 20)
	{
		x = 0;
		while (x < 38)
		{
			draw_square(cub->minimap, (t_point){x * size + 1, y * size + 1}, \
				size - 1, map[y][x] * 255);
			x++;
		}
		y++;
	}
	draw_square(cub->minimap,
		(t_point){\
			cub->player.pos.x * size - 2, \
			cub->player.pos.y * size - 2 \
		}, 5, 0xFFFF00);
	draw_line(cub->minimap, \
		(t_point){player.pos.x * size, player.pos.y * size}, \
		(t_point){(player.pos.x + player.dir.x) * size, \
				(player.pos.y + player.dir.y) * size}, \
		0xFF0000);
}

int	draw(t_cub *cub)
{
	draw_floor_sky(cub);
	draw_minimap(cub);
	mlx_put_image_to_window(cub->mlx, cub->window, cub->frame.ptr, 0, 0);
	mlx_put_image_to_window(cub->mlx, cub->window, cub->minimap.ptr, 0, 0);
	return (0);
}

int	main(void)
{
	t_cub	cub;

	init_cub(&cub);
	draw(&cub);
	mlx_do_key_autorepeaton(cub.mlx);
	mlx_key_hook(cub.window, key_hook, &cub);
	mlx_loop_hook(cub.mlx, draw, &cub);
	mlx_loop(cub.mlx);
	return (0);
}