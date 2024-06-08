/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:17:27 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/06/06 21:08:08 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

//** Some inputs for Julia set: **
// 0.285	+0.01
// -0.8		+0.156
// 0.35		+0.35
// -0.4		+0.6
// -0.835	-0.2321
// -0.70176	-0.3842
// -0.7269	+0.1889
// 0.285	+0

void	input_handler(int argc, char **argv, t_fractal *f)
{
	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
	{
		fractol_init(f, argv[1]);
	}
	else if (argc == 4 && !ft_strncmp(argv[1], "julia", 5)
				&& is_double(argv[2]) && is_double(argv[3]))
	{
		fractol_init(f, argv[1]);
		f->julia.x = ft_atod(argv[2]);
		f->julia.y = ft_atod(argv[3]);
	}
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
