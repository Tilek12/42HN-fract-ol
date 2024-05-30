/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:46:37 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/05/30 14:51:49 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

double	scale(double unscaled_num, double new_min, double new_max,
				double old_min, double old_max)
{
	double	result;

	result = (new_max - new_min) * (unscaled_num - old_min) /
				(old_max - old_min) + new_min;
	return (result);
}
