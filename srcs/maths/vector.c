/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrattez <mrattez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 12:19:49 by mrattez           #+#    #+#             */
/*   Updated: 2022/01/25 15:58:39 by mrattez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths.h"

t_vec2	vec2(double x, double y)
{
	return ((t_vec2){x, y});
}

double	vec2_norm(t_vec2 vec)
{
	return (sqrt(vec.x * vec.x + vec.y * vec.y));
}

double	vec2_scalar(t_vec2 a, t_vec2 b)
{
	return (a.x * b.x + a.y * b.y);
}

t_vec2	vec2_rotate(t_vec2 vec, double rad)
{
	double	new_x;
	double	new_y;

	new_x = vec.x * cos(rad) - vec.y * sin(rad);
	new_y = vec.x * sin(rad) + vec.y * cos(rad);
	return ((t_vec2){new_x, new_y});
}

double	vec2_angle(t_vec2 vector)
{
	t_vec2	base;
	double	a1;
	double	a2;

	base = (t_vec2){1, 0};
	a1 = vector.x * base.y - vector.y * base.x;
	a2 = vector.x * base.x + vector.y * base.y;
	return (atan2(a1, a2));
}
