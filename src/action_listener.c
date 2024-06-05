/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_listener.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:03:56 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/06/05 15:51:23 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	close_hook(void *param)
{
	t_fractal *f;

	f = param;
	esc_exit(f);
}

static void	resize_hook(int32_t new_width, int32_t new_height, void *param)
{
	t_fractal *f;

	f = param;
	if (new_width >= MIN_WIDTH && new_height >= MIN_HEIGHT)
	{
		f->img_buf = mlx_new_image(f->init, new_width, new_height);
		if (f->img_buf == NULL)
			error_exit(f);
		f->win_width = new_width;
		f->win_height = new_height;
		if (mlx_image_to_window(f->init, f->img_buf, 0, 0) < 0)
			error_exit(f);
		mlx_delete_image(f->init, f->img);
		f->img = f->img_buf;
		f->img_buf = NULL;
	}
	fractol_render(f);
}

static void	scroll_hook(double xdelta, double ydelta, void* param)
{
	t_fractal *f;

	f = param;
	if (ydelta > 0)
		f->zoom *= 0.85;
	else if (ydelta < 0)
		f->zoom *= 1.15;
	if (xdelta < 0)
		f->zoom *= 0.85;
	else if (xdelta > 0)
		f->zoom *= 1.15;
	fractol_render(f);
}

static void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_fractal	*f;

	f = param;
	if ((keydata.key == MLX_KEY_ESCAPE) && keydata.action == MLX_PRESS)
		mlx_close_window(f->init);
	if ((keydata.key == MLX_KEY_UP) && (keydata.action == MLX_PRESS))
		f->shift_y += (0.4 * f->zoom);
	if ((keydata.key == MLX_KEY_DOWN) && (keydata.action == MLX_PRESS))
		f->shift_y -= (0.4 * f->zoom);
	if ((keydata.key == MLX_KEY_LEFT) && (keydata.action == MLX_PRESS))
		f->shift_x -= (0.4 * f->zoom);
	if ((keydata.key == MLX_KEY_RIGHT) && (keydata.action == MLX_PRESS))
		f->shift_x += (0.4 * f->zoom);
	if ((keydata.key == MLX_KEY_EQUAL) && (keydata.action == MLX_PRESS))
	{
		if (f->iter_std <= f->iter_max)
			f->iter_std += 10;
	}
	if ((keydata.key == MLX_KEY_MINUS) && (keydata.action == MLX_PRESS))
	{
		if (f->iter_std >= f->iter_min)
			f->iter_std -= 10;
	}
	fractol_render(f);
}

void	action_listener(void *param)
{
	t_fractal *f;

	f = param;
	mlx_close_hook(f->init, &close_hook, f);
	mlx_resize_hook(f->init, &resize_hook, f);
	mlx_scroll_hook(f->init, &scroll_hook, f);
	mlx_key_hook(f->init, &key_hook, f);
}
