/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 11:20:44 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/06/08 12:45:30 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

// void	leaker() {
// 	unsetenv("DYLD_INSERT_LIBRARIES");
// 	system("leaks fractol");
// }

int	main(int argc, char **argv)
{
	// atexit(leaker);
	t_fractal	fractal;

	input_handler(argc, argv, &fractal);
	fractol_render(&fractal);
	if(!mlx_loop_hook(fractal.init, action_listener, &fractal))
		esc_exit(&fractal);
	mlx_loop(fractal.init);
	esc_exit(&fractal);
}
