/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_listener.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:03:56 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/06/03 17:43:25 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_fractal	*f;

	f = param;
	if ((keydata.key == MLX_KEY_ESCAPE) && keydata.action == MLX_PRESS)
		esc_exit(f);
	if ((keydata.key == MLX_KEY_UP) && (keydata.action == MLX_PRESS
		|| keydata.action == MLX_RELEASE || keydata.action == MLX_REPEAT))
		f->shift_y += 0.1;
	if ((keydata.key == MLX_KEY_DOWN) && (keydata.action == MLX_PRESS
		|| keydata.action == MLX_RELEASE || keydata.action == MLX_REPEAT))
		f->shift_y -= 0.1;
	if ((keydata.key == MLX_KEY_LEFT) && (keydata.action == MLX_PRESS
		|| keydata.action == MLX_RELEASE || keydata.action == MLX_REPEAT))
		f->shift_x -= 0.1;
	if ((keydata.key == MLX_KEY_RIGHT) && (keydata.action == MLX_PRESS
		|| keydata.action == MLX_RELEASE || keydata.action == MLX_REPEAT))
		f->shift_x += 0.1;
	if ((keydata.key == MLX_KEY_EQUAL) && (keydata.action == MLX_PRESS))
		f->fract_iter += 10;
	if ((keydata.key == MLX_KEY_MINUS) && (keydata.action == MLX_PRESS))
		f->fract_iter -= 10;
	fractal_print(f);
}

void	action_listener(t_fractal *f)
{
	// mlx_close_hook();
	// mlx_scroll_hook();
	mlx_key_hook(f->init, key_hook, f);
}
