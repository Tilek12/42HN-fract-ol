/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:46:37 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/06/03 16:42:09 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

double	scale(double unscaled_num, double new_min,
				double new_max, double old_max)
{
	double	result;

	result = (new_max - new_min) * (unscaled_num - 0) /
				(old_max - 0) + new_min;
	return (result);
}

t_point	sum_point(t_point z1, t_point z2)
{
	t_point	sum;

	sum.x = z1.x + z2.x;
	sum.y = z1.y + z2.y;
	return (sum);
}

// (real) x = (x * x) - (y * y)
// (i) y = 2 * x * y
t_point	square_point(t_point z)
{
	t_point	square;

	square.x = (z.x * z.x) - (z.y * z.y);
	square.y = 2 * z.x * z.y;
	return (square);
}
