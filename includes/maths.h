/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrattez <mrattez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 12:15:35 by mrattez           #+#    #+#             */
/*   Updated: 2021/12/21 12:35:27 by mrattez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHS_H
# define MATHS_H

# include <math.h>

typedef struct s_vec2
{
	double	x;
	double	y;
}	t_vec2;

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