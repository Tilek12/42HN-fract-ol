/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 11:20:44 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/05/30 14:35:59 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include <stdio.h>

// Print the window width and height.
static void ft_hook(void* param)
{
	const mlx_t* mlx = param;

	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	input_handler(argc, argv, &fractal);
	fractal_init(&fractal);
	fractal_print(&fractal);
	mlx_loop_hook(fractal.mlx_connection, ft_hook, fractal.mlx_connection);
	mlx_loop(fractal.mlx_connection);
	mlx_terminate(fractal.mlx_connection);
	return (EXIT_SUCCESS);
}
