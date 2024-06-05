/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:46:37 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/06/05 16:22:41 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

double	scale(double unscaled_num, double new_min,
				double new_max, double old_max)
{
	double	result;

	result = (new_max - new_min) * (unscaled_num - 0)
		/ (old_max - 0) + new_min;
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

double	ft_atod(char *str)
{
	long	integ_part;
	double	fract_part;
	double	pow;
	int		sign;

	integ_part = 0;
	fract_part = 0;
	sign = 1;
	pow = 1;
	while ((*str == '\t') || (*str == ' '))
		str++;
	while (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1;
	while (*str != '.' && *str)
		integ_part = integ_part * 10 + (*str++ - '0');
	if (*str == '.')
		str++;
	while (*str)
	{
		pow /= 10;
		fract_part = fract_part + (*str - '0') * pow;
		str++;
	}
	return ((sign * (integ_part + fract_part)));
}

int	is_double(char *str)
{
	int	dot_sign;
	int	digit;
	int	sign;
	int	i;

	dot_sign = 0;
	digit = 0;
	sign = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
			sign++;
		else if (str[i] == '.')
			dot_sign++;
		else if (str[i] >= '0' && str[i] <= '9')
			digit++;
		else
			return (0);
		i++;
	}
	if ((sign == 0 || sign == 1) && dot_sign == 1 && digit > 0)
		return (1);
	else
		return (0);
}
