/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrattez <mrattez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 10:55:40 by mrattez           #+#    #+#             */
/*   Updated: 2021/12/28 14:15:54 by mrattez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	rgb(int r, int g, int b)
{
	return (
		r << 16
		| g << 8
		| b << 0
	);
}

int	rgba(int r, int g, int b, int a)
{
	return (a << 24 | r << 16 | g << 8 | b);
}

int	lighten(int color, double percentage)
{
	return (rgba(\
		(color >> 16 & 0xFF) * (1 + percentage), \
		(color >> 8 & 0xFF) * (1 + percentage), \
		(color >> 0 & 0xFF) * (1 + percentage), \
		(color >> 24 & 0xFF) \
	));
}

int	darken(int color, double percentage)
{
	return (rgba(\
		(color >> 16 & 0xFF) * (1 - percentage), \
		(color >> 8 & 0xFF) * (1 - percentage), \
		(color >> 0 & 0xFF) * (1 - percentage), \
		(color >> 24 & 0xFF) \
	));
}
