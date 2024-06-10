/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_keyboard_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 19:28:58 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/06/10 00:47:37 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol_bonus.h"

/*-----------------------------------------------------*/
/*  Handles pushing "+" and "-" buttons on a keyboard  */
/*-----------------------------------------------------*/
static void	key_iteration_adjustment(mlx_key_data_t keydata, t_fractal *f)
{
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
}

/*-----------------------------------------------*/
/*  Handles pushing arrow buttons on a keyboard  */
/*-----------------------------------------------*/
static void	key_movement(mlx_key_data_t keydata, t_fractal *f)
{
	if ((keydata.key == MLX_KEY_UP) && (keydata.action == MLX_PRESS))
		f->shift.y += (0.4 * f->zoom);
	if ((keydata.key == MLX_KEY_DOWN) && (keydata.action == MLX_PRESS))
		f->shift.y -= (0.4 * f->zoom);
	if ((keydata.key == MLX_KEY_LEFT) && (keydata.action == MLX_PRESS))
		f->shift.x -= (0.4 * f->zoom);
	if ((keydata.key == MLX_KEY_RIGHT) && (keydata.action == MLX_PRESS))
		f->shift.x += (0.4 * f->zoom);
}

/*-----------------------------------------*/
/*  Handles pushing buttons on a keyboard  */
/*-----------------------------------------*/
void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_fractal	*f;

	f = param;
	if ((keydata.key == MLX_KEY_ESCAPE) && keydata.action == MLX_PRESS)
		mlx_close_window(f->mlx);
	if ((keydata.key == MLX_KEY_P) && (keydata.action == MLX_PRESS))
		f->is_psychedelic = 1;
	if ((keydata.key == MLX_KEY_O) && (keydata.action == MLX_PRESS))
		f->is_psychedelic = 0;
	if ((keydata.key == MLX_KEY_L) && (keydata.action == MLX_PRESS))
		f->is_mutable *= -1;
	key_iteration_adjustment(keydata, f);
	key_movement(keydata, f);
	fractol_render(f);
}
