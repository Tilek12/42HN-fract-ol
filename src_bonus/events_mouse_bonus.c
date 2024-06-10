/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_mouse_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 22:11:42 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/06/10 00:50:32 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol_bonus.h"

/*----------------------------------------------------------------*/
/*  Handles mouse wheel's scrolling by zooming in/out the image.  */
/*  Zooming follows the mouse position.                           */
/*----------------------------------------------------------------*/
void	scroll_hook(double xdelta, double ydelta, void *param)
{
	t_fractal	*f;
	double		scaled_cur_x;
	double		scaled_cur_y;
	double		scaled_cent_x;
	double		scaled_cent_y;

	f = param;
	(void)xdelta;
	if (ydelta > 0)
		f->zoom *= 0.85;
	else if (ydelta < 0)
		f->zoom *= 1.15;
	scaled_cur_x = scale(f->cur_pos.x, -2, +2, f->win_width);
	scaled_cur_y = scale(f->cur_pos.y, +2, -2, f->win_height);
	scaled_cent_x = scale(f->win_width / 2, -2, +2, f->win_width);
	scaled_cent_y = scale(f->win_height / 2, +2, -2, f->win_height);
	f->shift.x += (scaled_cur_x - scaled_cent_x) * f->zoom;
	f->shift.y += (scaled_cur_y - scaled_cent_y) * f->zoom;
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
		f->julia.x = (scale(xpos, -2, +2, f->win_width) * f->zoom) \
						+ f->shift.x;
		f->julia.y = (scale(ypos, +2, -2, f->win_height) * f->zoom) \
						+ f->shift.y;
		fractol_render(f);
	}
	f->cur_pos.x = xpos;
	f->cur_pos.y = ypos;
}
