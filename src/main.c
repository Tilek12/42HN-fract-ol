/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 11:20:44 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/06/05 16:41:34 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	input_handler(argc, argv, &fractal);
	fractol_render(&fractal);
	if(!mlx_loop_hook(fractal.init, action_listener, &fractal))
		esc_exit(&fractal);
	mlx_loop(fractal.init);
	esc_exit(&fractal);
}
