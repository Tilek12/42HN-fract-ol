/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 10:04:40 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/05/30 14:52:00 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	fractal_print(t_fractal *f)
{
	int	x;
	int	y;

}

void	fractal_init(t_fractal *f)
{
	// mlx_t	*mlx;

	// mlx = mlx_init(WIDTH, HEIGHT, "fractol", true);
	// if (!mlx)
	// 	error_exit();
	f->mlx_connection = mlx_init(WIDTH, HEIGHT, f->name , true);
	if (f->mlx_connection == NULL)
	{
		free(f->mlx_connection);
		error_exit();
	}
	f->img.img_ptr = mlx_new_image(f->mlx_connection, WIDTH, HEIGHT);
	if (f->img.img_ptr == NULL)
	{
		free(f->mlx_connection);
		error_exit();
	}
	// f->img.pixels_ptr = mlx_put_pixel(f->img.img_ptr, )
}
