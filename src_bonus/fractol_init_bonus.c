/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 10:04:40 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/06/10 00:44:19 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol_bonus.h"

/*-----------------------------*/
/*  Creates color transitions  */
/*-----------------------------*/
int	color_init(t_fractal *f, int color1, int color2)
{
	f->color.r1 = (color1 >> 16) & 0xFF;
	f->color.g1 = (color1 >> 8) & 0xFF;
	f->color.b1 = color1 & 0xFF;
	f->color.r2 = (color2 >> 16) & 0xFF;
	f->color.g2 = (color2 >> 8) & 0xFF;
	f->color.b2 = color2 & 0xFF;
	f->color.r = (int)(f->color.r1 + (f->color.r2 - f->color.r1) * f->color.t);
	f->color.g = (int)(f->color.g1 + (f->color.g2 - f->color.g1) * f->color.t);
	f->color.b = (int)(f->color.b1 + (f->color.b2 - f->color.b1) * f->color.t);
	return ((f->color.r << 16) | (f->color.g << 8) | f->color.b);
}

/*-------------------------*/
/*  Inputs fractal's data  */
/*-------------------------*/
void	fractol_init(t_fractal *f, char *fractal_name)
{
	f->name = fractal_name;
	f->win_width = WIDTH;
	f->win_height = HEIGHT;
	f->outside_value = 4;
	f->iter_std = 50;
	f->iter_max = 1000;
	f->iter_min = 20;
	f->shift.x = 0.0;
	f->shift.y = 0.0;
	f->zoom = 1.0;
	f->is_mutable = 1;
	f->is_psychedelic = 0;
	f->mlx = mlx_init(f->win_width, f->win_height, f->name, true);
	if (f->mlx == NULL)
		error_exit(f);
	f->img = mlx_new_image(f->mlx, f->win_width, f->win_height);
	if (f->img == NULL)
		error_exit(f);
}
