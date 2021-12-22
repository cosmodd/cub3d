/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrattez <mrattez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 09:47:43 by mrattez           #+#    #+#             */
/*   Updated: 2021/12/22 16:11:38 by mrattez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map[20][38] = {
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,1,1,1,1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
};

int	key_press(int keycode, t_cub *cub)
{
	if (keycode == ESC)
		exit(0);
	cub->keys[keycode] = 1;
	return (0);
}

int	key_release(int keycode, t_cub *cub)
{
	cub->keys[keycode] = 0;
	return (0);
}

void	handle_keys(t_cub *cub)
{
	t_vec2	d;

	d = cub->player.dir;
	if (cub->keys[K_W] || cub->keys[K_S])
	{
		cub->player.pos.x += d.x * 0.05 * (!cub->keys[K_S] * 2 - 1);
		cub->player.pos.y += d.y * 0.05 * (!cub->keys[K_S] * 2 - 1);
	}
	if (cub->keys[K_A] || cub->keys[K_D])
	{
		d = vec2_rotate(d, PI_2);
		cub->player.pos.x += d.x * 0.05 * (!cub->keys[K_A] * 2 - 1);
		cub->player.pos.y += d.y * 0.05 * (!cub->keys[K_A] * 2 - 1);
	}
	if (cub->keys[ARROW_LEFT] || cub->keys[ARROW_RIGHT])
	{
		cub->player.dir = vec2_rotate(cub->player.dir, PI / 90 * (!cub->keys[ARROW_LEFT] * 2 - 1));
	}
}

void	init_cub(t_cub *cub)
{
	cub->mlx = mlx_init();
	cub->width = 1920;
	cub->height = 1080;
	cub->map_width = 38;
	cub->map_height = 20;
	cub->window = mlx_new_window(cub->mlx, cub->width, cub->height, "Cub3D");
	cub->frame = new_image(cub->mlx, cub->width, cub->height);
	cub->minimap = new_image(cub->mlx, cub->width / 4, cub->height / 4);
	cub->player.pos.x = 1.5;
	cub->player.pos.y = 1.5;
	cub->player.dir.x = 1;
	cub->player.dir.y = 0;
	cub->player.fov = rad(60);
	memset(cub->keys, 0, sizeof(int) * 101);
}


t_vec2	h_ray(t_cub *cub, t_vec2 pos, t_vec2 dir, int size)
{
	// t_vec2	prev_hit;
	t_vec2	hit;
	double	dir_angle;
	int		dof;
	(void) size;

	// prev_hit.x = pos.x;
	// prev_hit.y = pos.y;
	hit.x = DBL_MAX;
	hit.y = DBL_MAX;
	dir_angle = vec2_angle(dir);
	if (sin(dir_angle) > 0.001)
		hit = (t_vec2){fmod(pos.y, 1) / tan(dir_angle) + pos.x, (int)pos.y - 0.001};
	else if (sin(dir_angle) < -0.001)
		hit = (t_vec2){(1 - fmod(pos.y, 1)) / tan(-dir_angle) + pos.x, (int)pos.y + 1};
	else
		return (hit);
	dof = 0;
	while (dof < cub->map_width)
	{
		// draw_line(cub->minimap, \
			// (t_point){prev_hit.x * size, prev_hit.y * size}, \
			// (t_point){hit.x * size, hit.y * size}, 0xFF00FF);
		// draw_square(cub->minimap, \
			// (t_point){hit.x * size - 1, hit.y * size - 1}, \
			// 3, 0xFF00FF);
		if (hit.x < 0 || hit.x >= cub->map_width || \
			hit.y < 0 || hit.y >= cub->map_height || \
			map[(int)hit.y][(int)hit.x])
			return (hit);
		// if (map[(int)hit.y][(int)hit.x] || (hit.x < 0 || hit.x >= cub->map_width) \
		// 								|| (hit.y < 0 || hit.y >= cub->map_height))
		// 	return (hit);
		else
		{
			// prev_hit.x = hit.x;
			// prev_hit.y = hit.y;
			hit.y += (sin(dir_angle) < -0.001) * 2 - 1;
			hit.x -= ((sin(dir_angle) < -0.001) * 2 - 1) / tan(dir_angle);
			dof++;
		}
	}
	return (hit);
}

t_vec2	v_ray(t_cub *cub, t_vec2 pos, t_vec2 dir, int size)
{
	// t_vec2	prev_hit;
	t_vec2	hit;
	double	dir_angle;
	int		dof;
	(void) size;

	// prev_hit.x = pos.x;
	// prev_hit.y = pos.y;
	hit.x = 0;
	hit.y = 0;
	dir_angle = vec2_angle(dir);
	if (cos(dir_angle) > 0.001)
		hit = (t_vec2){(int)pos.x + 1, (1 - fmod(pos.x, 1)) * tan(-dir_angle) + pos.y};
	else if (cos(dir_angle) < -0.001)
		hit = (t_vec2){(int)pos.x -0.001, fmod(pos.x, 1) * tan(dir_angle) + pos.y};
	else
		return (hit);
	dof = 0;
	while (dof < cub->map_width)
	{
		// draw_line(cub->minimap, \
		// 	(t_point){prev_hit.x * size, prev_hit.y * size}, \
		// 	(t_point){hit.x * size, hit.y * size}, 0xFFFF00);
		// draw_square(cub->minimap, \
		// 	(t_point){hit.x * size - 2, hit.y * size - 2}, \
		// 	5, 0xFFFF00);
		if (hit.x < 0 || hit.x >= cub->map_width || \
			hit.y < 0 || hit.y >= cub->map_height || \
			map[(int)hit.y][(int)hit.x])
			return (hit);
		// if (map[(int)hit.y][(int)hit.x] && (hit.x < 0 || hit.x >= cub->map_width) \
		// 								&& (hit.y < 0 || hit.y >= cub->map_height))
		else
		{
			// prev_hit.x = hit.x;
			// prev_hit.y = hit.y;
			hit.x -= (cos(dir_angle) < -0.001) * 2 - 1;
			hit.y += ((cos(dir_angle) < -0.001) * 2 - 1) * tan(dir_angle);
			dof++;
		}
	}
	return (hit);
}

t_vec2	raycast(t_cub *cub, t_vec2 pos, t_vec2 dir)
{
	t_vec2	rays[2];
	double	dists[2];
	int		size;

	size = cub->height / 3 / 15;
	rays[0] = h_ray(cub, pos, dir, size);
	rays[1] = v_ray(cub, pos, dir, size);
	dists[0] = distance_fd(pos.x, pos.y, rays[0].x, rays[0].y);
	dists[1] = distance_fd(pos.x, pos.y, rays[1].x, rays[1].y);
	// draw_square(cub->minimap,
	// 	(t_point){\
	// 		(int)rays[0].x * size, \
	// 		(int)rays[0].y * size \
	// 	}, size, 0xFF00FF);
	// draw_square(cub->minimap,
	// 	(t_point){\
	// 		(int)rays[1].x * size, \
	// 		(int)rays[1].y * size \
	// 	}, size, 0xFFFF00);
	if (dists[0] < dists[1])
		return (rays[0]);
	else
		return (rays[1]);
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
	t_vec2		vector;
	t_player	player;
	int			y;
	int			x;
	int			size;

	player = cub->player;
	mlx_destroy_image(cub->mlx, cub->minimap.ptr);
	cub->minimap = new_image(cub->mlx, cub->width / 4, cub->height / 4);
	size = cub->height / 6 / 15;
	y = 0;
	while (y < cub->map_height)
	{
		x = 0;
		while (x < cub->map_width)
		{
			if (map[y][x])
				draw_square(cub->minimap, (t_point){x * size + 1, y * size + 1}, size - 2, 0x000000FF);
			else
				draw_square(cub->minimap, (t_point){x * size + 1, y * size + 1}, size - 2, 0x00222222);
			x++;
		}
		y++;
	}
	draw_square(cub->minimap,
		(t_point){\
			cub->player.pos.x * size - 2, \
			cub->player.pos.y * size - 2 \
		}, 5, 0xFFFF00);
	vector = vec2_rotate(cub->player.dir, cub->player.fov / 2.0);
	// printf("%d\n", vec2_angle(vector) == vec2_angle(cub->player.dir));
	draw_line(cub->minimap, \
		(t_point){player.pos.x * size, player.pos.y * size}, \
		(t_point){(player.pos.x + vector.x) * size, \
				(player.pos.y + vector.y) * size}, \
		0x00FF00);
	vector = vec2_rotate(cub->player.dir, cub->player.fov / -2.0);
	// printf("%d\n", vec2_angle(vector) == vec2_angle(cub->player.dir));
	draw_line(cub->minimap, \
		(t_point){player.pos.x * size, player.pos.y * size}, \
		(t_point){(player.pos.x + vector.x) * size, \
				(player.pos.y + vector.y) * size}, \
		0x00FF00);
	draw_line(cub->minimap, \
		(t_point){player.pos.x * size, player.pos.y * size}, \
		(t_point){(player.pos.x + player.dir.x) * size, \
				(player.pos.y + player.dir.y) * size}, \
		0xFF0000);
	vector = raycast(cub, cub->player.pos, cub->player.dir);
	draw_square(cub->minimap,
		(t_point){\
			(int)vector.x * size, \
			(int)vector.y * size \
		}, size, 0xFF0000);
	// printf("(%f, %f)\n", vector.x, vector.y);
}

void	draw_walls(t_cub *cub)
{
	t_vec2	cast;
	t_vec2	dir;
	double	dist;
	double	da;
	int		x;
	int		y;
	int		height;

	x = 0;
	da = cub->player.fov / (double)cub->width;
	dir = vec2_rotate(cub->player.dir, cub->player.fov / -2.0);
	// printf("(%f, %f) => %.20f\n", dir.x, dir.y, da);
	while (x < cub->width)
	{
		cast = raycast(cub, cub->player.pos, dir);
		dist = distance_fd(cub->player.pos.x, cub->player.pos.y, \
							cast.x, cast.y) * 20;
		// printf("\t%d => (%f, %f) => %f\n", x, dir.x, dir.y, dist);
		height = 64 / dist * 277;
		if (height >= cub->height)
			height = cub->height - 1;
		y = 0;
		while (y < height)
			put_pixel(cub->frame, x, y++ + cub->height / 2.0 - height / 2.0, 0xFF0000);
		// printf("\t(%f, %f) ->", dir.x, dir.y);
		dir = vec2_rotate(dir, da);
		// printf(" (%f, %f)\n", dir.x, dir.y);
		x++;
	}
}

int	draw(t_cub *cub)
{
	clock_t	start = clock();
	clock_t	end;
	char	*str = NULL;
	char	*clock_str = NULL;

	asprintf(&str, "Angle: %f\n", vec2_angle(cub->player.dir));
	handle_keys(cub);
	draw_floor_sky(cub);
	draw_minimap(cub);
	draw_walls(cub);
	end = clock();
	asprintf(&clock_str, "%.0f FPS\n", 1.0 / ((double)(end-start) / CLOCKS_PER_SEC));
	mlx_put_image_to_window(cub->mlx, cub->window, cub->frame.ptr, 0, 0);
	mlx_put_image_to_window(cub->mlx, cub->window, cub->minimap.ptr, 0, 0);
	mlx_string_put(cub->mlx, cub->window, 10, cub->height / 2 - 10, 0xFFFFFF, str);
	mlx_string_put(cub->mlx, cub->window, 10, cub->height / 2 - 20, 0xFFFFFF, clock_str);
	free(str);
	return (0);
}

int	main(void)
{
	t_cub	cub;

	init_cub(&cub);
	draw(&cub);
	mlx_do_key_autorepeaton(cub.mlx);
	// mlx_key_hook(cub.window, key_hook, &cub);
	mlx_hook(cub.window, 2, 0 ,key_press, &cub);
	mlx_hook(cub.window, 3, 0 ,key_release, &cub);
	mlx_loop_hook(cub.mlx, draw, &cub);
	mlx_loop(cub.mlx);
	return (0);
}
