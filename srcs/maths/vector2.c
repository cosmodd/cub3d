/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrattez <mrattez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 12:09:26 by mrattez           #+#    #+#             */
/*   Updated: 2021/12/23 12:10:44 by mrattez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths.h"

double	vec2_angle_from(t_vec2 v1, t_vec2 v2)
{
	double	a1;
	double	a2;

	a1 = v1.x * v2.y - v1.y * v2.x;
	a2 = v1.x * v2.x + v1.y * v2.y;
	return (atan2(a1, a2));
}