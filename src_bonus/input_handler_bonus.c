/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:17:27 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/06/10 11:26:53 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol_bonus.h"

/*-------------------------*/
/*  Handles program input  */
/*------------------------------*/
/*  Some inputs for Julia Set:  */
/*------------------------------*/
/*  julia	+0.285	+0.01    */
/*  julia	-0.8	+0.156   */
/*  julia	+0.35	+0.35    */
/*  julia	-0.4	+0.6     */
/*  julia	-0.835	-0.2321  */
/*  julia	-0.7269	+0.1889  */
/*---------------------------*/
void	input_handler(int argc, char **argv, t_fractal *f)
{
	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
		fractol_init(f, argv[1]);
	else if (argc == 4 && !ft_strncmp(argv[1], "julia", 5)
		&& is_double(argv[2]) && is_double(argv[3]))
	{
		fractol_init(f, argv[1]);
		f->julia.x = ft_atod(argv[2]);
		f->julia.y = ft_atod(argv[3]);
	}
	else if (argc == 2 && !ft_strncmp(argv[1], "tricorn", 7))
		fractol_init(f, argv[1]);
	else if (argc == 2 && !ft_strncmp(argv[1], "burning_ship", 12))
		fractol_init(f, argv[1]);
	else
	{
		ft_printf(R"\n\t-------- !!! Incorrect input !!! --------\n\n"RES);
		ft_printf(G"\tPlease, follow the examples:\n\n"RES);
		ft_printf(Y"\t\" ./fractol_bonus mandelbrot \"\n"RES);
		ft_printf(Y"\t\" ./farctol_bonus julia <real value> <i value> \"\n"RES);
		ft_printf(C"\t\" ./fractol_bonus tricorn \"\n"RES);
		ft_printf(C"\t\" ./fractol_bonus burning_ship \"\n\n"RES);
		exit(EXIT_FAILURE);
	}
}
