/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 11:20:44 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/06/03 20:37:51 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	input_handler(argc, argv, &fractal);
	fractal_init(&fractal);
	fractal_print(&fractal);
	action_listener(&fractal);
	mlx_loop(fractal.init);
	mlx_terminate(fractal.init);
	return (EXIT_SUCCESS);
}
