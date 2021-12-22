/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrattez <mrattez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 11:59:20 by mrattez           #+#    #+#             */
/*   Updated: 2021/12/22 12:57:08 by mrattez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths.h"

int	in_range_fd(double value, double lower, double upper, int inclusive)
{
	if (inclusive)
		return (value >= lower && value <= upper);
	else
		return (value > lower && value < upper);
}

int	in_range_ff(float value, float lower, float upper, int inclusive)
{
	if (inclusive)
		return (value >= lower && value <= upper);
	else
		return (value > lower && value < upper);
}

int	in_range_d(int value, int lower, int upper, int inclusive)
{
	if (inclusive)
		return (value >= lower && value <= upper);
	else
		return (value > lower && value < upper);
}
