/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 10:04:40 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/06/03 12:42:17 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	data_init(t_fractal *f)
{
	f->outside_value = 4;
	f->fract_quality = 120;
}

void	fractal_init(t_fractal *f)
{
	f->init = mlx_init(WIDTH, HEIGHT, f->name , true);
	if (f->init == NULL)
	{
		free(f->init);
		error_exit();
	}
	f->img = mlx_new_image(f->init, WIDTH, HEIGHT);
	if (f->img == NULL)
	{
		free(f->init);
		error_exit();
	}
	data_init(f);
}
