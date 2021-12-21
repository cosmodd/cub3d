/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrattez <mrattez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 09:40:30 by mrattez           #+#    #+#             */
/*   Updated: 2021/12/21 12:35:27 by mrattez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths.h"

double	rad(double degrees)
{
	return (degrees * M_PI / 180);
}

double	arc(double rad)
{
	return (rad * 180 / M_PI);
}
