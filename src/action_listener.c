/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_listener.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:03:56 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/06/03 21:02:24 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	close_hook(void *param)
{
	t_fractal *f;

	f = param;
	esc_exit(f);
}

void	scroll_hook(double xdelta, double ydelta, void* param)
{
	t_fractal *f;

	f = param;
	ft_printf("xdelta = %d\n", xdelta);
	if (ydelta > 0)
		f->zoom *= 0.5;
	else if (ydelta < 0)
		f->zoom *= 1.05;
	fractal_print(f);
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_fractal	*f;

	f = param;
	if ((keydata.key == MLX_KEY_ESCAPE) && keydata.action == MLX_PRESS)
		esc_exit(f);
	if ((keydata.key == MLX_KEY_UP) && (keydata.action == MLX_PRESS
		|| keydata.action == MLX_RELEASE || keydata.action == MLX_REPEAT))
		f->shift_y += (0.1 * f->zoom);
	if ((keydata.key == MLX_KEY_DOWN) && (keydata.action == MLX_PRESS
		|| keydata.action == MLX_RELEASE || keydata.action == MLX_REPEAT))
		f->shift_y -= (0.1 * f->zoom);
	if ((keydata.key == MLX_KEY_LEFT) && (keydata.action == MLX_PRESS
		|| keydata.action == MLX_RELEASE || keydata.action == MLX_REPEAT))
		f->shift_x -= (0.1 * f->zoom);
	if ((keydata.key == MLX_KEY_RIGHT) && (keydata.action == MLX_PRESS
		|| keydata.action == MLX_RELEASE || keydata.action == MLX_REPEAT))
		f->shift_x += (0.1 * f->zoom);
	if ((keydata.key == MLX_KEY_EQUAL) && (keydata.action == MLX_PRESS))
		f->fract_iter += 10;
	if ((keydata.key == MLX_KEY_MINUS) && (keydata.action == MLX_PRESS))
		f->fract_iter -= 10;
	fractal_print(f);
}

void	action_listener(t_fractal *f)
{
	mlx_close_hook(f->init, &close_hook, f);
	mlx_scroll_hook(f->init, &scroll_hook, f);
	mlx_key_hook(f->init, &key_hook, f);
}
