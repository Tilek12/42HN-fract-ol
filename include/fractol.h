/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 10:50:14 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/05/30 13:06:26 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../lib/libft/libft.h"
# include "../lib/libft/ft_printf/ft_printf.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include <math.h>

#define ERROR_MESSAGE "Insert right input. For example:\n\t\t \" ./fractol mandelbrot \" \n\t\t \" ./farctol julia <real_value> <i_value> \"\n"
#define WIDTH	1200
#define HEIGHT	1200

typedef struct	s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
}				t_img;

typedef struct	s_fractal
{
	char	*name;
	void	*mlx_connection;
	t_img	img;
}				t_fractal;

void	input_handler(int argc, char **argv, t_fractal *f);
void	fractal_init(t_fractal *fract);
void	error_exit();

#endif
