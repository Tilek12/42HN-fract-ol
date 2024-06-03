/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 10:09:00 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/06/03 16:52:29 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	error_exit()
{
	ft_putstr_fd((char *)mlx_strerror(mlx_errno), STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	esc_exit(t_fractal *f)
{
	if (f->img != NULL)
		mlx_delete_image(f->init, f->img);
	if (f->init != NULL)
		mlx_close_window(f->init);
	mlx_terminate(f->init);
	f = NULL;
	exit(EXIT_SUCCESS);
}
