/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 16:39:52 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/06/10 00:52:00 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/*------------------------------------------------------------------*/
/*  Handles program exiting while clicking the window close button  */
/*------------------------------------------------------------------*/
void	close_hook(void *param)
{
	t_fractal	*f;

	f = param;
	esc_exit(f);
}

/*------------------------------------------*/
/*  Handles resizing of the program window  */
/*------------------------------------------*/
void	resize_hook(int32_t new_width, int32_t new_height, void *param)
{
	t_fractal	*f;

	f = param;
	if (new_width >= MIN_WIDTH && new_height >= MIN_HEIGHT)
	{
		f->img_buf = mlx_new_image(f->mlx, new_width, new_height);
		if (f->img_buf == NULL)
			error_exit(f);
		f->win_width = new_width;
		f->win_height = new_height;
		if (mlx_image_to_window(f->mlx, f->img_buf, 0, 0) < 0)
			error_exit(f);
		mlx_delete_image(f->mlx, f->img);
		f->img = f->img_buf;
		f->img_buf = NULL;
		fractol_render(f);
	}
}

/*---------------------------------------------------------------*/
/*  Handles mouse wheel's scrolling by zooming in/out the image  */
/*---------------------------------------------------------------*/
void	scroll_hook(double xdelta, double ydelta, void *param)
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

/*---------------------------------*/
/*  Handles mouse cursor position  */
/*---------------------------------*/
void	cursor_hook(double xpos, double ypos, void *param)
{
	t_fractal	*f;

	f = param;
	if (!ft_strncmp(f->name, "julia", 5) && f->is_mutable == -1)
	{
		f->julia.x = (scale(xpos, -2, +2, f->win_width) * f->zoom);
		f->julia.y = (scale(ypos, +2, -2, f->win_height) * f->zoom);
		fractol_render(f);
	}
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
