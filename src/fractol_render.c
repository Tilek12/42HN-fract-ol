/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:34:32 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/06/03 12:45:31 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

// z = z * z + c
void	draw_pixels(int x, int y, t_fractal *f)
{
	t_point	z;
	t_point	c;
	int		i;
	int		color;

	z.x = 0.0;
	z.y = 0.0;
	i = 0;
	c.x = scale(x, -2, +2, WIDTH);
	c.y = scale(y, +2, -2, HEIGHT);
	while (i < f->fract_quality)
	{
		z = sum_point(square_point(z), c);
		if (((z.x * z.x) + (z.y * z.y)) > f->outside_value)
		{
			color = scale(i, BLACK, WHITE, f->fract_quality);
			mlx_put_pixel(f->img, x, y, color);
			return ;
		}
		i++;
	}
	mlx_put_pixel(f->img, x, y, PLUM);
}

void	fractal_print(t_fractal *f)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			draw_pixels(x, y, f);
		}
	}
	mlx_image_to_window(f->init, f->img, 0, 0);
	if (mlx_image_to_window(f->init, f->img, 0, 0) < 0)
		error_exit();
}
