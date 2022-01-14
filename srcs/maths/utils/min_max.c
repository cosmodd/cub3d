/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrattez <mrattez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 10:06:46 by mrattez           #+#    #+#             */
/*   Updated: 2022/01/14 15:25:21 by mrattez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	min(int a, int b)
{
	return (a * (a <= b) + b * (b < a));
}

double	min_d(double a, double b)
{
	return (a * (a <= b) + b * (b < a));
}

int	max(int a, int b)
{
	return (a * (a >= b) + b * (b > a));
}

double	max_d(double a, double b)
{
	return (a * (a >= b) + b * (b > a));
}
