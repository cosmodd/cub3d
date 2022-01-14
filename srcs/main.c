/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrattez <mrattez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 09:47:43 by mrattez           #+#    #+#             */
/*   Updated: 2022/01/14 16:14:19 by mrattez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map[15][48] = {
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,1,1,2,1,2,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,2,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,2,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,1,1,2,1,2,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }
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

int	mouse_move(int x, int y, t_cub *cub)
{
	double	angle;
	double	diff;

	(void) y;
	diff = (cub->width / 2) - x;
	angle = (diff / (cub->width / 2.0)) * (cub->player.fov / 2.0);
	cub->player.dir = vec2_rotate(cub->player.dir, -angle);
	mlx_mouse_move(cub->window, cub->width / 2, cub->height / 2);
	return (0);
}

void	handle_keys(t_cub *cub)
{
	t_vec2	d;
	t_vec2	p;
	int		f;
	double	bounds;

	d = cub->player.dir;
	p = cub->player.pos;
	bounds = 0.3;
	if (cub->keys[K_W] || cub->keys[K_S])
	{
		f = !cub->keys[K_S] * 2 - 1;
		if (map[(int)(p.y)][(int)(p.x + d.x * bounds * f)] == 0)
			cub->player.pos.x += d.x * 0.05 * f;
		if (map[(int)(p.y + d.y * bounds * f)][(int)(p.x)] == 0)
			cub->player.pos.y += d.y * 0.05 * f;
	}
	if (cub->keys[K_A] || cub->keys[K_D])
	{
		d = vec2_rotate(d, PI_2);
		f = !cub->keys[K_A] * 2 - 1;
		if (map[(int)(p.y)][(int)(p.x + d.x * bounds * f)] == 0)
			cub->player.pos.x += d.x * 0.05 * f;
		if (map[(int)(p.y + d.y * bounds * f)][(int)(p.x)] == 0)
			cub->player.pos.y += d.y * 0.05 * f;
	}
	if (cub->keys[ARROW_LEFT] || cub->keys[ARROW_RIGHT])
		cub->player.dir = vec2_rotate(cub->player.dir, PI / 90 * (!cub->keys[ARROW_LEFT] * 2 - 1));
}

void	init_cub(t_cub *cub)
{
	cub->mlx = mlx_init();
	cub->width = 720;
	cub->height = 405;
	cub->map_width = 48;
	cub->map_height = 15;
	cub->window = mlx_new_window(cub->mlx, cub->width, cub->height, "Cub3D");
	cub->frame = new_image(cub->mlx, cub->width, cub->height);
	for (int y = 0; y < cub->height; y++)
		for (int x = 0; x < cub->width; x++)
			put_pixel(cub->frame, x, y, 0);
	cub->minimap = new_image(cub->mlx, cub->width, cub->height);
	cub->player.pos.x = 1.5;
	cub->player.pos.y = 1.5;
	cub->player.dir.x = 1;
	cub->player.dir.y = 0;
	cub->player.fov = rad(60);
	cub->proj_dist = (cub->width / 2.0) / tan(cub->player.fov / 2.0);
	cub->textures[0] = from_xpm_image(cub->mlx, "assets/grass.xpm");
	cub->textures[1] = from_xpm_image(cub->mlx, "assets/wall.xpm");
	cub->textures[2] = from_xpm_image(cub->mlx, "assets/door.xpm");
	cub->texture_res = cub->textures[0].width;
	cub->player.height = cub->texture_res / 2;
	memset(cub->keys, 0, sizeof(int) * 512);
}

t_vec2	h_ray(t_cub *cub, t_vec2 pos, t_vec2 dir)
{
	t_vec2	hit;
	double	dir_angle;
	int		dof;

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
		if (hit.x < 0 || hit.x >= cub->map_width || \
			hit.y < 0 || hit.y >= cub->map_height || \
			map[(int)hit.y][(int)hit.x])
			return (hit);
		else
		{
			hit.y += (sin(dir_angle) < -0.001) * 2 - 1;
			hit.x -= ((sin(dir_angle) < -0.001) * 2 - 1) / tan(dir_angle);
			dof++;
		}
	}
	return (hit);
}

t_vec2	v_ray(t_cub *cub, t_vec2 pos, t_vec2 dir)
{
	t_vec2	hit;
	double	dir_angle;
	int		dof;

	hit.x = DBL_MAX;
	hit.y = DBL_MAX;
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
		if (hit.x < 0 || hit.x >= cub->map_width ||
			hit.y < 0 || hit.y >= cub->map_height || \
			map[(int)hit.y][(int)hit.x])
			return (hit);
		else
		{
			hit.x -= (cos(dir_angle) < -0.001) * 2 - 1;
			hit.y += ((cos(dir_angle) < -0.001) * 2 - 1) * tan(dir_angle);
			dof++;
		}
	}
	return (hit);
}

t_side	get_side(t_vec2 pos, t_vec2 dir, t_vec2 h_ray, t_vec2 v_ray)
{
	double	dist_h;
	double	dist_v;
	double	angle;

	dist_h = distance_fd(pos.x, pos.y, h_ray.x, h_ray.y);
	dist_v = distance_fd(pos.x, pos.y, v_ray.x, v_ray.y);
	angle = vec2_angle(dir);
	if (dist_h < dist_v)
		return (1 + 2 * (dir.y < -0.001));
	else
		return (2 + 2 * (dir.x < -0.001));
}

t_ray	raycast(t_cub *cub, t_vec2 pos, t_vec2 dir)
{
	t_vec2	rays[2];
	double	dists[2];
	t_ray	ray;

	rays[0] = h_ray(cub, pos, dir);
	rays[1] = v_ray(cub, pos, dir);
	dists[0] = distance_fd(pos.x, pos.y, rays[0].x, rays[0].y);
	dists[1] = distance_fd(pos.x, pos.y, rays[1].x, rays[1].y);
	ray.pos = rays[dists[0] > dists[1]];
	ray.dist = dists[dists[0] > dists[1]];
	ray.side = get_side(pos, dir, rays[0], rays[1]);
	ray.value = map[(int)ray.pos.y][(int)ray.pos.x];
	return (ray);
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
				put_pixel(cub->frame, x, y, 0x5445FF);
			else
				put_pixel(cub->frame, x, y, 0x2E3136);
			x++;
		}
		y++;
	}
}

// void	draw_minimap(t_cub *cub)
// {
// 	t_vec2		pos;
// 	t_vec2		dir;
// 	int			y;
// 	int			x;
// 	int			size;

// 	pos = cub->player.pos;
// 	dir = cub->player.dir;
// 	size = 10;
// 	mlx_destroy_image(cub->mlx, cub->minimap.ptr);
// 	cub->minimap = new_image(cub->mlx, cub->map_width * size, cub->map_height * size);
// 	y = 0;
// 	while (y < cub->map_height)
// 	{
// 		x = 0;
// 		while (x < cub->map_width)
// 		{
// 			if (map[y][x])
// 				draw_square(cub->minimap, (t_point){x * size, y * size}, size, 0x220000FF);
// 			// else
// 			// 	draw_square(cub->minimap, (t_point){x * size, y * size}, size, 0x22000000);
// 			x++;
// 		}
// 		y++;
// 	}
// 	draw_triangle(cub->minimap,
// 		(t_point){(pos.x + vec2_rotate(dir, rad(120)).x / 3) * size, \
// 			(pos.y + vec2_rotate(dir, rad(120)).y / 3) * size},
// 		(t_point){(pos.x + dir.x * .75) * size, (pos.y + dir.y * 0.75) * size},
// 		(t_point){(pos.x + vec2_rotate(dir, rad(-120)).x / 3) * size, \
// 			(pos.y + vec2_rotate(dir, rad(-120)).y / 3) * size});
// }
void	draw_minimap(t_cub *cub)
{
	t_vec2	pos;
	t_vec2	dir;
	int		map_size;
	int		size;

	map_size = cub->height / 4;
	size = map_size / cub->map_height * 1.5;
	pos = cub->player.pos;
	dir = cub->player.dir;
	mlx_destroy_image(cub->mlx, cub->minimap.ptr);
	cub->minimap = new_image(cub->mlx, map_size * 2, map_size);
	for (int y = 0; y < map_size; y++)
		for (int x = 0; x < map_size * 2; x++)
			put_pixel(cub->minimap, x, y, 0xCC000000);
	draw_triangle(cub->minimap,
		(t_point){map_size + vec2_rotate(dir, rad(120)).x * size / 2, map_size / 2 + vec2_rotate(dir, rad(120)).y * size / 2},
		(t_point){map_size + dir.x * size, map_size / 2 + dir.y * size},
		(t_point){map_size + vec2_rotate(dir, rad(-120)).x * size / 2, map_size / 2 + vec2_rotate(dir, rad(-120)).y * size / 2});
}

void	draw_walls(t_cub *cub)
{
	t_ray	ray;
	t_vec2	dir;
	t_vec2	cur;
	t_vec2	tex;
	double	beta, straightDist;
	int		height, rowDist;

	cur.x = 0;
	dir = vec2_rotate(cub->player.dir, cub->player.fov / -2.0);
	while (cur.x < cub->width)
	{
		ray = raycast(cub, cub->player.pos, dir);
		height = cub->texture_res / (cub->texture_res * ray.dist * cos(vec2_angle_from(cub->player.dir, dir))) * cub->proj_dist;
		cur.y = 0;
		while (cur.y < height)
		{
			tex.x = fmod(ray.pos.x, 1) * cub->texture_res;
			if (ray.side % 2 == 0)
				tex.x = fmod(ray.pos.y, 1) * cub->texture_res;
			tex.y = cur.y * cub->texture_res / height;
			put_pixel(
				cub->frame,
				cur.x, cur.y + cub->height / 2 - height / 2,
				darken(get_pixel(cub->textures[ray.value], tex.x, tex.y), ray.dist / cub->map_height));
			// tex.y = (cur.y + (height / 2.0 - cub->height / 2.0) * (height >= cub->height)) * cub->texture_res / height;
			// put_pixel(cub->frame, cur.x, cur.y + \
			// 	(cub->height / 2.0 - height / 2.0) * (height < cub->height),
			// 	darken(wall_texture[(int)tex.y][(int)tex.x], ray.dist / cub->map_width /* + 0.3 * (ray.side % 2) */));
			// if (ray.value == 1)
			// 	put_pixel(cub->frame, cur.x, cur.y + \
			// 		(cub->height / 2.0 - height / 2.0) * (height < cub->height),
			// 		darken(get_pixel(cub->textures[0], tex.x, tex.y), ray.dist / cub->map_width));
			// else if (ray.value == 2)
			// 	put_pixel(cub->frame, cur.x, cur.y + \
			// 		(cub->height / 2.0 - height / 2.0) * (height < cub->height),
			// 		darken(get_pixel(cub->textures[2], tex.x, tex.y), ray.dist / cub->map_width));
			cur.y++;
		}
		cur.y = cub->height / 2.0 + height / 2.0;
		while (cur.y < cub->height)
		{
			beta = vec2_angle_from(cub->player.dir, dir);
			rowDist = cur.y - cub->height / 2.0;
			straightDist = (double)cub->player.height / rowDist * cub->proj_dist;
			straightDist = straightDist / cos(beta);
			tex.x = cub->player.pos.x * cub->texture_res + dir.x * straightDist;
			tex.x = fmod(tex.x, cub->texture_res);
			tex.y = cub->player.pos.y * cub->texture_res + dir.y * straightDist;
			tex.y = fmod(tex.y, cub->texture_res);
			put_pixel(
				cub->frame,
				cur.x, cur.y,
				darken(get_pixel(cub->textures[0], tex.x, tex.y), straightDist / cub->texture_res / cub->map_height));
			put_pixel(
				cub->frame,
				cur.x, cub->height / 2 - height / 2 - (cur.y - cub->height / 2 - height / 2),
				darken(get_pixel(cub->textures[1], tex.x, tex.y), straightDist / cub->texture_res / cub->map_height));
			cur.y++;
		}
		dir = vec2_rotate(dir, cub->player.fov / (double)cub->width);
		cur.x++;
	}
}

int	draw(t_cub *cub)
{
	clock_t	start = clock();
	clock_t	end;
	char	*str = NULL;
	char	*clock_str = NULL;

	// asprintf(&str, "Angle: %.0f°\n", arc(vec2_angle(cub->player.dir)));
	handle_keys(cub);
	draw_floor_sky(cub);
	draw_minimap(cub);
	draw_walls(cub);
	end = clock();
	asprintf(&clock_str, "%.0f FPS\n", 1.0 / ((double)(end-start) / CLOCKS_PER_SEC));
	mlx_put_image_to_window(cub->mlx, cub->window, cub->frame.ptr, 0, 0);
	mlx_put_image_to_window(cub->mlx, cub->window, cub->minimap.ptr, 0, 0);
	// mlx_string_put(cub->mlx, cub->window, 10, cub->height / 2 - 10, 0xFFFFFF, str);
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
	mlx_hook(cub.window, 2, 0, key_press, &cub);
	mlx_hook(cub.window, 3, 0, key_release, &cub);
	mlx_hook(cub.window, 6, 0, mouse_move, &cub);
	mlx_mouse_hide();
	mlx_loop_hook(cub.mlx, draw, &cub);
	mlx_loop(cub.mlx);
	return (0);
}
