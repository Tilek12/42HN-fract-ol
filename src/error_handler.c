/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 10:09:00 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/06/05 17:08:03 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	error_exit(t_fractal *f)
{
	ft_putstr_fd((char *)mlx_strerror(mlx_errno), STDERR_FILENO);
	mlx_close_window(f->init);
	if (f->img != NULL)
	{
		mlx_delete_image(f->init, f->img);
	}
	if (f->init != NULL)
	{
		mlx_terminate(f->init);
	}
	if (f != NULL)
		f = NULL;
	exit(EXIT_FAILURE);
}

void	esc_exit(t_fractal *f)
{
	mlx_close_window(f->init);
	if (f->img != NULL)
	{
		mlx_delete_image(f->init, f->img);
	}
	if (f->init != NULL)
	{
		mlx_terminate(f->init);
	}
	if (f != NULL)
		f = NULL;
	exit(EXIT_SUCCESS);
}
