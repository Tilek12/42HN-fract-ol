/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:34:32 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/06/10 10:53:05 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/*---------------------------------------------------------*/
/*  Creates pixels of Julia Set according to the formula:  */
/*---------------------------------------------------------*/
/*  z = z^2 + c  */
/*  z0 = c + c   */
/*--------------------------------*/
/*  range x (real): [-2.0, +2.0]  */
/*  range y (imag): [+2.0, -2.0]  */
/*--------------------------------*/
static void	draw_pixels_julia(int x, int y, t_fractal *f, int *color)
{
	int	i;

	i = 0;
	f->z.x = (scale(x, -2, +2, f->win_width) * f->zoom);
	f->z.y = (scale(y, +2, -2, f->win_height) * f->zoom);
	f->c.x = f->julia.x;
	f->c.y = f->julia.y;
	while (i < f->iter_std)
	{
		f->z = sum_point(square_point(f->z), f->c);
		if (((f->z.x * f->z.x) + (f->z.y * f->z.y)) > f->outside_value)
		{
			if (f->is_psychedelic == 1)
				*color = scale(i, BLACK, WHITE, f->iter_std);
			else
			{
				f->color.t = (double)i / f->iter_std;
				*color = color_init(f, BLACK, PINK);
			}
			mlx_put_pixel(f->img, x, y, *color);
			return ;
		}
		i++;
	}
	mlx_put_pixel(f->img, x, y, GOLD);
}

/*--------------------------------------------------------------*/
/*  Creates pixels of Mandelbrot Set according to the formula:  */
/*--------------------------------------------------------------*/
/*  z = z^2 + c  */
/*  z0 = 0       */
/*--------------------------------*/
/*  range x (real): [-2.0, +2.0]  */
/*  range y (imag): [+2.0, -2.0]  */
/*--------------------------------*/
static void	draw_pixels_mandelbrot(int x, int y, t_fractal *f, int *color)
{
	int	i;

	i = 0;
	f->z.x = 0.0;
	f->z.y = 0.0;
	f->c.x = (scale(x, -2, +2, f->win_width) * f->zoom);
	f->c.y = (scale(y, +2, -2, f->win_height) * f->zoom);
	while (i < f->iter_std)
	{
		f->z = sum_point(square_point(f->z), f->c);
		if (((f->z.x * f->z.x) + (f->z.y * f->z.y)) > f->outside_value)
		{
			if (f->is_psychedelic == 1)
				*color = scale(i, BLACK, WHITE, f->iter_std);
			else
			{
				f->color.t = (double)i / f->iter_std;
				*color = color_init(f, BLACK, AQUA);
			}
			mlx_put_pixel(f->img, x, y, *color);
			return ;
		}
		i++;
	}
	mlx_put_pixel(f->img, x, y, LIME);
}

/*-----------------------------*/
/*  Renders the fractal image  */
/*-----------------------------*/
void	fractol_render(t_fractal *f)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < f->win_height)
	{
		x = 0;
		while (x < f->win_width)
		{
			if (!ft_strncmp(f->name, "mandelbrot", 10))
				draw_pixels_mandelbrot(x, y, f, &color);
			else if (!ft_strncmp(f->name, "julia", 5))
				draw_pixels_julia(x, y, f, &color);
			x++;
		}
		y++;
	}
	if (mlx_image_to_window(f->mlx, f->img, 0, 0) < 0)
		error_exit(f);
}
