/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 10:50:14 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/06/10 12:21:35 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

/*----------------------*/
/*  Included libraries  */
/*----------------------*/
# include "../lib/libft/libft.h"
# include "../lib/libft/ft_printf/ft_printf.h"
# include "../lib/mlx42/include/MLX42/MLX42.h"
# include <math.h>

/*----------------*/
/*  Window sizes  */
/*----------------*/
# define WIDTH 800
# define HEIGHT 800
# define MIN_WIDTH 120
# define MIN_HEIGHT 120

/*----------------*/
/*  Text colors  */
/*----------------*/
# define RES "\033[0m"
# define R "\033[31m"
# define G "\033[32m"
# define Y "\033[33m"
# define B "\033[34m"
# define M "\033[35m"
# define C "\033[36m"
# define W "\033[37m"

/*----------------*/
/*  Image colors  */
/*----------------*/
# define BLACK 0x000000FF
# define WHITE 0xFFFFFFFF
# define PINK 0xFF00AAFF
# define AQUA 0x00FFAAFF
# define GOLD 0xFFD700FF
# define LIME 0xAAFF00FF
# define SKY_BLUE 0x00AAFFFF
# define BRIGHT_SKY_BLUE 0x87CEEBFF
# define BRIGHT_PALE_GREEN 0x98FB98FF
# define SEA_GREEN 0x2E8B57FF

/*-----------*/
/*  Structs  */
/*-----------*/
typedef struct s_color
{
	int		r;
	int		g;
	int		b;
	int		r1;
	int		g1;
	int		b1;
	int		r2;
	int		g2;
	int		b2;
	double	t;
}				t_color;

typedef struct s_point
{
	double	x;
	double	y;
}				t_point;

typedef struct s_fractal
{
	char		*name;
	mlx_t		*mlx;
	mlx_image_t	*img;
	mlx_image_t	*img_buf;
	int32_t		win_width;
	int32_t		win_height;
	t_color		color;
	t_point		z;
	t_point		c;
	t_point		julia;
	t_point		cur_pos;
	t_point		shift;
	double		outside_value;
	int			iter_std;
	int			iter_max;
	int			iter_min;
	double		zoom;
	int			is_mutable;
	int			is_psychedelic;
}				t_fractal;

/*-------------*/
/*  Functions  */
/*-------------*/
void	input_handler(int argc, char **argv, t_fractal *f);
void	fractol_init(t_fractal *f, char *fractal_name);
int		color_init(t_fractal *f, int color1, int color2);
void	fractol_render(t_fractal *f);
void	action_listener(void *param);
void	close_hook(void *param);
void	resize_hook(int32_t new_width, int32_t new_height, void *param);
void	scroll_hook(double xdelta, double ydelta, void *param);
void	cursor_hook(double xpos, double ypos, void *param);
void	key_hook(mlx_key_data_t keydata, void *param);
void	error_exit(t_fractal *f);
void	esc_exit(t_fractal *f);
double	scale(double unscaled_num, double new_min, \
				double new_max, double old_max);
t_point	sum_point(t_point z1, t_point z2);
t_point	square_point(t_point z, char *fractal_name);
double	ft_atod(char *str);
int		is_double(char *str);

#endif
