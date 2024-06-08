/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_listener.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:03:56 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/06/08 13:37:52 by tkubanyc         ###   ########.fr       */
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
		fractol_render(f);
	}
}

static void	scroll_hook(double xdelta, double ydelta, void* param)
{
	t_fractal	*f;

	f = param;
	(void)xdelta;
	if (ydelta > 0)
		f->zoom *= 0.85;
	else if (ydelta < 0)
		f->zoom *= 1.15;
	fractol_render(f);
}

static void	cursor_hook(double xpos, double ypos, void *param)
{
	t_fractal	*f;

	f = param;
	if (!ft_strncmp(f->name, "julia", 5) && f->is_mutable == -1)
	{
		f->julia.x = (scale(xpos, -2, +2, f->win_width) * f->zoom)
						+ f->shift.x;
		f->julia.y = (scale(ypos, +2, -2, f->win_height) * f->zoom)
						+ f->shift.y;
		fractol_render(f);
	}
	f->cur_pos.x = xpos;
	f->cur_pos.y = ypos;
}

static void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_fractal	*f;

	f = param;
	if ((keydata.key == MLX_KEY_ESCAPE) && keydata.action == MLX_PRESS)
		mlx_close_window(f->init);
	if ((keydata.key == MLX_KEY_UP) && (keydata.action == MLX_PRESS))
		f->shift.y += (0.4 * f->zoom);
	if ((keydata.key == MLX_KEY_DOWN) && (keydata.action == MLX_PRESS))
		f->shift.y -= (0.4 * f->zoom);
	if ((keydata.key == MLX_KEY_LEFT) && (keydata.action == MLX_PRESS))
		f->shift.x -= (0.4 * f->zoom);
	if ((keydata.key == MLX_KEY_RIGHT) && (keydata.action == MLX_PRESS))
		f->shift.x += (0.4 * f->zoom);
	if ((keydata.key == MLX_KEY_P) && (keydata.action == MLX_PRESS))
		f->is_psychedelic = 1;
	if ((keydata.key == MLX_KEY_O) && (keydata.action == MLX_PRESS))
		f->is_psychedelic = 0;
	if ((keydata.key == MLX_KEY_L) && (keydata.action == MLX_PRESS))
		f->is_mutable *= -1;
	if ((keydata.key == MLX_KEY_EQUAL) && (keydata.action == MLX_PRESS))
		if (f->iter_std <= f->iter_max) f->iter_std += 10;
	if ((keydata.key == MLX_KEY_MINUS) && (keydata.action == MLX_PRESS))
		if (f->iter_std >= f->iter_min) f->iter_std -= 10;
	fractol_render(f);
}

void	action_listener(void *param)
{
	t_fractal *f;

	f = param;
	mlx_close_hook(f->init, &close_hook, f);
	mlx_resize_hook(f->init, &resize_hook, f);
	mlx_scroll_hook(f->init, &scroll_hook, f);
	mlx_cursor_hook(f->init, &cursor_hook, f);
	mlx_key_hook(f->init, &key_hook, f);
	// ft_printf("cur_pos.x = %d, cur_pos.y = %d\n\n", (int)f->cur_pos.x, (int)f->cur_pos.y);
}
