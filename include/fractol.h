/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 10:50:14 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/06/03 12:36:55 by tkubanyc         ###   ########.fr       */
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

#define BLACK		0x000000
#define WHITE		0xFFFFFF
#define MAGENTA		0xFF00FF
#define PINK		0xFF69B4
#define HOT_PINK	0xFF00AA
#define DEEP_PINK	0xFF1493
#define TURQUOISE	0x40E0D0
#define CORAL		0xFF5555
#define CYAN		0x00FFFF
#define AQUA		0x00FFAA
#define SKY_BLUE	0x00AAFF
#define BLUE_VIOLET	0x8A2BE2
#define PURPLE		0xAA00FF
#define PLUM		0xDDA0DD
#define ORCHID		0xDA70D6
#define YELLOW		0xFFFF00
#define GOLD		0xFFD700
#define ORANGE_RED	0xFF4500
#define ORANGE		0xFFAA00
#define LIME		0xAAFF00
#define CHARTREUSE	0x7FFF00
#define GREEN		0x00FF7F

typedef struct	s_point
{
	double	x;
	double	y;
}				t_point;

typedef struct	s_fractal
{
	char		*name;
	void		*init;
	mlx_image_t	*img;
	double		outside_value;
	int			fract_quality;
}				t_fractal;

void	input_handler(int argc, char **argv, t_fractal *f);
void	fractal_init(t_fractal *fract);
void	fractal_print(t_fractal *f);
void	draw_pixels(int x, int y, t_fractal *f);
void	data_init(t_fractal *f);
void	error_exit();
double	scale(double unscaled_num, double new_min, double new_max, double old_max);
t_point	sum_point(t_point z1, t_point z2);
t_point	square_point(t_point z);

#endif
