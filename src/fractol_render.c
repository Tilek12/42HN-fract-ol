/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:34:32 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/06/05 19:58:48 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

// z = z * z + c
// z1 = c + c
static void	draw_pixels_julia(int x, int y, t_fractal *f)
{
	t_point	z;
	t_point	c;
	int		i;
	int		color;

	i = 0;
	z.x = (scale(x, -2, +2, f->win_width) * f->zoom) + f->shift_x;
	z.y = (scale(y, +2, -2, f->win_height) * f->zoom) + f->shift_y;
	c.x = f->julia_x;
	c.y = f->julia_y;
	while (i < f->iter_std)
	{
		z = sum_point(square_point(z), c);
		if (((z.x * z.x) + (z.y * z.y)) > f->outside_value)
		{
			color = scale(i, BLACK, WHITE, f->iter_std);
			mlx_put_pixel(f->img, x, y, color);
			return ;
		}
		i++;
	}
	mlx_put_pixel(f->img, x, y, PLUM);
}

// z = z * z + c
static void	draw_pixels_mandelbrot(int x, int y, t_fractal *f)
{
	t_point	z;
	t_point	c;
	int		i;
	int		color;

	i = 0;
	z.x = 0.0;
	z.y = 0.0;
	c.x = (scale(x, -2, +2, f->win_width) * f->zoom) + f->shift_x;
	c.y = (scale(y, +2, -2, f->win_height) * f->zoom) + f->shift_y;
	while (i < f->iter_std)
	{
		z = sum_point(square_point(z), c);
		if (((z.x * z.x) + (z.y * z.y)) > f->outside_value)
		{
			color = scale(i, BLACK, WHITE, f->iter_std);
			mlx_put_pixel(f->img, x, y, color);
			return ;
		}
		i++;
	}
	mlx_put_pixel(f->img, x, y, PLUM);
}

void	fractol_render(t_fractal *f)
{
	int		x;
	int		y;

	y = -1;
	while (++y < f->win_height)
	{
		x = -1;
		while (++x < f->win_width)
		{
			if (!ft_strncmp(f->name, "mandelbrot", 10))
				draw_pixels_mandelbrot(x, y, f);
			else if (!ft_strncmp(f->name, "julia", 5))
				draw_pixels_julia(x, y, f);
			else
				error_exit(f);
			// x++;
		}
		// y++;
	}
	if (mlx_image_to_window(f->init, f->img, 0, 0) < 0)
		error_exit(f);
}
