/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrattez <mrattez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 12:15:35 by mrattez           #+#    #+#             */
/*   Updated: 2021/12/22 12:56:40 by mrattez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHS_H
# define MATHS_H

# include <math.h>

# define PI		3.141592
# define PI_2	1.570796
# define PI_4	0.785398

typedef struct s_vec2
{
	double	x;
	double	y;
}	t_vec2;

// Utils
int		distance_d(int x1, int y1, int x2, int y2);
double	distance_fd(double x1, double y1, double x2, double y2);
int		in_range_fd(double value, double lower, double upper, int inclusive);
int		in_range_ff(float value, float lower, float upper, int inclusive);
int		in_range_d(int value, int lower, int upper, int inclusive);

// Angles
double	rad(double degrees);
double	arc(double rad);

// Vec 2D
t_vec2	vec2(double x, double y);
double	vec2_norm(t_vec2 vec);
double	vec2_scalar(t_vec2 a, t_vec2 b);
t_vec2	vec2_rotate(t_vec2 vec, double rad);
double	vec2_angle(t_vec2 vector);

#endif
