/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_window_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 22:13:40 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/06/10 00:51:12 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol_bonus.h"

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
