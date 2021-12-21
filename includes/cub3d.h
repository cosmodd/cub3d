/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrattez <mrattez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 09:48:24 by mrattez           #+#    #+#             */
/*   Updated: 2021/12/21 15:09:07 by mrattez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include "keys.h"
# include "mlx.h"
# include "maths.h"
# include "xutils.h"

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
	t_player	player;
	t_image		frame;
	t_image		minimap;
}	t_cub;

#endif
