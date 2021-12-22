/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrattez <mrattez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:51:26 by mrattez           #+#    #+#             */
/*   Updated: 2021/12/22 12:56:23 by mrattez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths.h"

int	distance_d(int x1, int y1, int x2, int y2)
{
	int	diff_x;
	int	diff_y;

	diff_x = x2 - x1;
	diff_y = y2 - y1;
	return ((int)sqrt(diff_x * diff_x + diff_y * diff_y));
}

double	distance_fd(double x1, double y1, double x2, double y2)
{
	double	diff_x;
	double	diff_y;

	diff_x = x2 - x1;
	diff_y = y2 - y1;
	return (sqrt(diff_x * diff_x + diff_y * diff_y));
}
