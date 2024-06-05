/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 10:04:40 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/06/05 19:56:45 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

// int	color_init(t_color *c, int color1, int color2, int i)
// {
// 	c->t *= i;
// 	c->r1 = (color1 >> 16) & 0xFF;
// 	c->g1 = (color1 >> 8) & 0xFF;
// 	c->b1 = color1 & 0xFF;
// 	c->r2 = (color2 >> 16) & 0xFF;
// 	c->g2 = (color2 >> 8) & 0xFF;
// 	c->b2 = color2 & 0xFF;
// 	c->r = (int)(c->r1 + (c->r2 - c->r1) * c->t);
// 	c->g = (int)(c->g1 + (c->g2 - c->g1) * c->t);
// 	c->b = (int)(c->b1 + (c->b2 - c->b1) * c->t);
// 	return (c->r << 16) | (c->g << 8) | c->b;
// }

void	fractol_init(t_fractal *f, char *fractal_name)
{
	f->name = fractal_name;
	f->win_width = WIDTH;
	f->win_height = HEIGHT;
	f->outside_value = 4;
	f->iter_std = 50;
	f->iter_max = 1000;
	f->iter_min = 20;
	f->shift_x = 0.0;
	f->shift_y = 0.0;
	f->zoom = 1.0;
	f->init = mlx_init(f->win_width, f->win_height, f->name, true);
	if (f->init == NULL)
		error_exit(f);
	f->img = mlx_new_image(f->init, f->win_width, f->win_height);
	if (f->img == NULL)
		error_exit(f);
}
