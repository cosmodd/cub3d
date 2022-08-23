/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrattez <mrattez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 09:47:43 by mrattez           #+#    #+#             */
/*   Updated: 2022/05/03 13:33:45 by mrattez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map[17][15] = {
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1, 0, 0, 0, 1 },
	{ 1, 1, 1, 1, 1, 2, 2, 1,-1,-1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0,-1, 0, 0, 0, 0, 0,-1, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 1 },
	{ 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0,-1, 0, 0, 0, 0, 0,-1, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 1 },
	{ 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0,-1, 0, 0, 0, 0, 0,-1, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
};

int	key_press(int keycode, t_cub *cub)
{
	int	x;
	int	y;

	if (keycode == ESC)
		exit(0);
	if (keycode == K_E)
	{
		x = cub->player.pos.x + cub->player.dir.x;
		y = cub->player.pos.y + cub->player.dir.y;
		if (map[y][x] == 2)
			map[y][x] = 0;
	}
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
	cub->map_width = 15;
	cub->map_height = 17;
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
	cub->textures[0] = from_xpm_image(cub->mlx, "assets/CASFL27.xpm");
	cub->textures[1] = from_xpm_image(cub->mlx, "assets/C4.xpm");
	cub->textures[2] = from_xpm_image(cub->mlx, "assets/CASL19.xpm");
	cub->textures[3] = from_xpm_image(cub->mlx, "assets/C88.xpm");
	cub->sprites[0] = from_xpm_image(cub->mlx, "assets/unmaykr.xpm");
	scale_up(cub->mlx, &cub->sprites[0], 4);
	cub->texture_res = cub->textures[0].width;
	cub->player.height = cub->texture_res / 2;
	cub->frameCount = 0;
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
		return (3 - 2 * (dir.y < -0.001));
	else
		return (4 - 2 * (dir.x < -0.001));
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

t_ray	continue_ray(t_cub *cub, t_ray ray, t_vec2 dir)
{
	t_vec2	rays[2];
	double	dists[2];
	t_ray	new_ray;

	rays[0] = h_ray(cub, ray.pos, dir);
	rays[1] = v_ray(cub, ray.pos, dir);
	dists[0] = distance_fd(ray.pos.x, ray.pos.y, rays[0].x, rays[0].y);
	dists[1] = distance_fd(ray.pos.x, ray.pos.y, rays[1].x, rays[1].y);
	new_ray.pos = rays[dists[0] > dists[1]];
	new_ray.dist = dists[dists[0] > dists[1]] + ray.dist;
	new_ray.side = get_side(ray.pos, dir, rays[0], rays[1]);
	new_ray.value = map[(int)new_ray.pos.y][(int)new_ray.pos.x];
	return (new_ray);
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

void	draw_minimap(t_cub *cub)
{
	t_vec2	pos;
	t_vec2	dir;
	int		map_size;
	int		size;
	int		color;

	map_size = cub->height / 4;
	size = map_size / cub->map_height;
	pos = cub->player.pos;
	dir = cub->player.dir;
	mlx_destroy_image(cub->mlx, cub->minimap.ptr);
	cub->minimap = new_image(cub->mlx, map_size * 2, map_size);
	for (int y = 0; y < map_size; y++)
		for (int x = 0; x < map_size * 2; x++)
			put_pixel(cub->minimap, x, y, 0xCC000000);
	for (int y = 0; y < cub->map_height; y++)
		for (int x = 0; x < cub->map_width; x++)
		{
			if (map[y][x] == 0) continue ;
			color = (map[y][x] == 1) * 0xAAFFFFFF
				+ (map[y][x] == 2) * 0xAA7161EF
				+ (map[y][x] == -1) * 0xAA555555;
			draw_rect(cub->minimap,
				(t_point){
					map_size + (x - cub->player.pos.x) * size,
					map_size / 2 + (y - cub->player.pos.y) * size},
				(t_point){
					map_size + (x - cub->player.pos.x) * size + size,
					map_size / 2 + (y - cub->player.pos.y) * size + size},
				color);
		}
	draw_triangle(cub->minimap,
		(t_point){map_size + vec2_rotate(dir, rad(120)).x * size / 2, map_size / 2 + vec2_rotate(dir, rad(120)).y * size / 2},
		(t_point){map_size + dir.x * size, map_size / 2 + dir.y * size},
		(t_point){map_size + vec2_rotate(dir, rad(-120)).x * size / 2, map_size / 2 + vec2_rotate(dir, rad(-120)).y * size / 2});
}

int	get_wall_height(t_cub *cub, t_ray ray, t_vec2 dir)
{
	return cub->texture_res / (cub->texture_res * ray.dist * cos(vec2_angle_from(cub->player.dir, dir))) * cub->proj_dist;;
}

void	draw_wall_stripe(t_cub *cub, t_ray ray, t_vec2 dir, t_vec2 infos)
{
	t_vec2	current;
	t_vec2	texture;
	int		height;
	int		pixel;

	height = get_wall_height(cub, ray, dir);
	current.y = 0;
	while (current.y < height)
	{
		texture.x = fmod(ray.pos.x, 1) * cub->texture_res;
		if (ray.side % 2 == 0)
			texture.x = fmod(ray.pos.y, 1) * cub->texture_res;
		texture.y = (current.y * cub->texture_res) / height;
		pixel = get_pixel(cub->textures[(int)infos.y], texture.x, texture.y);
		if ((pixel >> 24 & 0xFF) == 0)
			put_pixel(cub->frame,
				infos.x, current.y + cub->height / 2 - height / 2,
				darken(pixel, ray.dist / cub->map_height));
		current.y++;
	}
}

void	draw_floor_stripe(t_cub *cub, t_ray ray, t_vec2 dir, t_vec2 infos)
{
	t_vec2	current;
	t_vec2	texture;
	double	beta;
	double	dist;
	int		height;
	int		rowDist;

	height = get_wall_height(cub, ray, dir);
	current.y = cub->height / 2 + height / 2;
	while (current.y < cub->height)
	{
		beta = vec2_angle_from(cub->player.dir, dir);
		rowDist = current.y - cub->height / 2;
		dist = (double)cub->player.height / rowDist * cub->proj_dist;
		dist = dist / cos(beta);
		texture.x = cub->player.pos.x * cub->texture_res + dir.x * dist;
		texture.x = fmod(texture.x, cub->texture_res);
		texture.y = cub->player.pos.y * cub->texture_res + dir.y * dist;
		texture.y = fmod(texture.y, cub->texture_res);
		put_pixel(
				cub->frame,
				infos.x, current.y,
				darken(get_pixel(cub->textures[0], texture.x, texture.y), dist / cub->texture_res / cub->map_height));
		if (infos.y)
			put_pixel(
					cub->frame,
					infos.x, cub->height / 2 - height / 2 - (current.y - cub->height / 2 - height / 2),
					darken(get_pixel(cub->textures[0], texture.x, texture.y), dist / cub->texture_res / cub->map_height));
		current.y++;
	}
}

void	draw_walls(t_cub *cub)
{
	t_ray	ray;
	t_ray	behind;
	t_vec2	dir;
	t_vec2	cur;
	t_vec2	tex;

	cur.x = 0;
	tex.y = 0;
	dir = vec2_rotate(cub->player.dir, cub->player.fov / -2.0);
	while (cur.x < cub->width)
	{
		ray = raycast(cub, cub->player.pos, dir);
		behind = raycast(cub, ray.pos, dir);
		behind.dist += ray.dist;
		if (ray.value < 0)
		{
			while (behind.value < 0)
				behind = continue_ray(cub, behind, dir);
			draw_wall_stripe(cub, behind, dir, (t_vec2){cur.x, behind.value});
			draw_floor_stripe(cub, behind, dir, (t_vec2){cur.x, 1});
			draw_wall_stripe(cub, ray, dir, (t_vec2){cur.x, abs(ray.value) + 2});
			draw_floor_stripe(cub, ray, dir, (t_vec2){cur.x, 1});
		}
		else
		{
			draw_wall_stripe(cub, ray, dir, (t_vec2){cur.x, ray.value});
			draw_floor_stripe(cub, ray, dir, (t_vec2){cur.x, 1});
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
	for (int y = 0; y < cub->height; y++)
		for (int x = 0; x < cub->width; x++)
			put_pixel(cub->frame, x, y, 0x000000);
	// draw_floor_sky(cub);
	draw_minimap(cub);
	draw_walls(cub);
	draw_rect(cub->frame,
		(t_point){cub->width / 2 - 1, cub->height / 2 - 5},
		(t_point){cub->width / 2 + 1, cub->height / 2 + 5},
		0x00FFFFFF);
	draw_rect(cub->frame,
		(t_point){cub->width / 2 - 5, cub->height / 2 - 1},
		(t_point){cub->width / 2 + 5, cub->height / 2 + 1},
		0x00FFFFFF);
	end = clock();
	asprintf(&clock_str, "%.0f FPS\n", 1.0 / ((double)(end-start) / CLOCKS_PER_SEC));
	mlx_put_image_to_window(cub->mlx, cub->window, cub->frame.ptr, 0, 0);
	mlx_put_image_to_window(cub->mlx, cub->window, cub->minimap.ptr, 0, 0);
	mlx_put_image_to_window(cub->mlx, cub->window,
		cub->sprites[0].ptr,
		cub->width / 2 - cub->sprites[0].width / 2,
		cub->height - cub->sprites[0].height);
	// mlx_string_put(cub->mlx, cub->window, 10, cub->height / 2 - 10, 0xFFFFFF, str);
	mlx_string_put(cub->mlx, cub->window, 10, cub->height / 2 - 20, 0xFFFFFF, clock_str);
	free(str);
	cub->frameCount++;
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
