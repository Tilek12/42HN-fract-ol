/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_handler_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 10:09:00 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/06/10 00:44:46 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol_bonus.h"

/*------------------------------------------------------------*/
/*  Deletes every created memory and exits with EXIT_FAILURE  */
/*------------------------------------------------------------*/
void	error_exit(t_fractal *f)
{
	ft_putstr_fd((char *)mlx_strerror(mlx_errno), STDERR_FILENO);
	mlx_close_window(f->mlx);
	if (f->img != NULL)
		mlx_delete_image(f->mlx, f->img);
	if (f->img_buf != NULL)
		mlx_delete_image(f->mlx, f->img_buf);
	if (f->mlx != NULL)
		mlx_terminate(f->mlx);
	if (f != NULL)
		f = NULL;
	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------*/
/*  Deletes every created memory and exits with EXIT_SUCCESS  */
/*------------------------------------------------------------*/
void	esc_exit(t_fractal *f)
{
	mlx_close_window(f->mlx);
	if (f->img != NULL)
		mlx_delete_image(f->mlx, f->img);
	if (f->img_buf != NULL)
		mlx_delete_image(f->mlx, f->img_buf);
	if (f->mlx != NULL)
		mlx_terminate(f->mlx);
	if (f != NULL)
		f = NULL;
	exit(EXIT_SUCCESS);
}
