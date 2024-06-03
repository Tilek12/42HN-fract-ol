/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 10:04:40 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/06/03 20:54:03 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	fractal_init(t_fractal *f)
{
	f->init = mlx_init(WIDTH, HEIGHT, f->name, true);
	if (f->init == NULL)
		error_exit(f);
	f->img = mlx_new_image(f->init, WIDTH, HEIGHT);
	if (f->img == NULL)
		error_exit(f);
	f->outside_value = 4;
	f->fract_iter = 230;
	f->shift_x = 0;
	f->shift_y = 0;
	f->zoom = 1.0;
}
