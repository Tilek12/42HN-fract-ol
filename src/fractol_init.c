/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 10:04:40 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/06/03 17:39:08 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	set_data(t_fractal *f)
{
	f->outside_value = 4;
	f->fract_iter = 230;
	f->shift_x = 0;
	f->shift_y = 0;
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
	set_data(f);
}
