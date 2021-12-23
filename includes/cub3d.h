/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrattez <mrattez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 09:48:24 by mrattez           #+#    #+#             */
/*   Updated: 2021/12/22 17:28:14 by mrattez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>
# include <float.h>
# include <time.h>
# include "keys.h"
# include "mlx.h"
# include "maths.h"
# include "xutils.h"

typedef enum e_side
{
	NORTH = 1,
	EAST = 2,
	SOUTH = 3,
	WEST = 4
}	t_side;

typedef struct s_ray
{
	t_vec2	pos;
	t_side	side;
	double	dist;
	int		value;
}	t_ray;

typedef struct s_player
{
	t_vec2	pos;
	t_vec2	dir;
	int		fov;
}	t_player;

typedef struct s_cub
{
	void		*mlx;
	void		*window;
	int			width;
	int			height;
	int			map_width;
	int			map_height;
	int			keys[512];
	t_player	player;
	t_image		frame;
	t_image		minimap;
}	t_cub;

#endif
