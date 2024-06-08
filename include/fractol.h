/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 10:50:14 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/06/08 13:28:40 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../lib/libft/libft.h"
# include "../lib/libft/ft_printf/ft_printf.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include <math.h>

#define ERROR_MESSAGE "Insert right input. For example: \n\t\t \" ./fractol mandelbrot \" \n\t\t \" ./farctol julia <real_value> <i_value> \"\n"

#define WIDTH	800
#define HEIGHT	800
#define MIN_WIDTH	120
#define MIN_HEIGHT	120

// Colors
#define BLACK		0x000000FF
#define WHITE		0xFFFFFFFF
#define MAGENTA		0xFF00FFFF
#define PINK		0xFF69B4FF
#define HOT_PINK	0xFF00AAFF
#define CORAL		0xFF5555FF
#define DEEP_PINK	0xFF1493FF
#define TURQUOISE	0x40E0D0FF
#define CYAN		0x00FFFFFF
#define AQUA		0x00FFAAFF
#define SKY_BLUE	0x00AAFFFF
#define BLUE_VIOLET	0x8A2BE2FF
#define PURPLE		0xAA00FFFF
#define PLUM		0xDDA0DDFF
#define ORCHID		0xDA70D6FF
#define YELLOW		0xFFFF00FF
#define GOLD		0xFFD700FF
#define ORANGE_RED	0xFF4500FF
#define ORANGE		0xFFAA00FF
#define LIME		0xAAFF00FF
#define CHARTREUSE	0x7FFF00FF
#define GREEN		0x00FF7FFF

#define LIGHT_SALMON	0xFFA07AFF
#define SALMON			0xFA8072FF
#define DARK_SALMON		0xE9967AFF
#define LIGHT_CORAL		0xF08080FF
#define INDIAN_RED		0xCD5C5CFF
#define CRIMSON			0xDC143CFF
#define FIREBRICK		0xB22222FF
#define DARK_RED		0x8B0000FF
#define LIGHT_PINK		0xFFB6C1FF
#define PALE_VIOLET_RED	0xDB7093FF
#define THISTLE			0xD8BFD8FF
#define VIOLET			0xEE82EEFF
#define LIGHT_GRAY		0xD3D3D3FF
#define SILVER			0xC0C0C0FF
#define DARK_GRAY		0xA9A9A9FF
#define GRAY			0x808080FF
#define DIM_GRAY		0x696969FF
#define SLATE_GRAY		0x708090FF
#define DARK_SLATE_GRAY	0x2F4F4FFF
#define LIGHT_SEA_GREEN	0x20B2AAFF
#define SEA_GREEN		0x2E8B57FF
#define SPRING_GREEN	0x00FF7FFF
#define PALE_GREEN		0x98FB98FF
#define LIGHT_GREEN		0x90EE90FF
#define AQUAMARINE		0x7FFFD4FF
#define POWDER_BLUE		0xB0E0E6FF
#define LIGHT_BLUE		0xADD8E6FF
#define DODGER_BLUE		0x1E90FFFF
#define ROYAL_BLUE		0x4169E1FF
#define MIDNIGHT_BLUE	0x191970FF
#define LAVENDER		0xE6E6FAFF
#define FLORAL_WHITE	0xFFFAF0FF
#define ALICE_BLUE		0xF0F8FFFF
#define GHOST_WHITE		0xF8F8FFFF
#define HONEYDEW		0xF0FFF0FF
#define IVORY			0xFFFFF0FF
#define MINT_CREAM		0xF5FFFAFF
#define LEMON_CHIFFON	0xFFFACDFF
#define CORNSILK		0xFFF8DCFF
#define LINEN			0xFAF0E6FF
#define SEASHELL		0xFFF5EEFF
#define LAVENDER_BLUSH	0xFFF0F5FF
#define MISTY_ROSE		0xFFE4E1FF

// Bright colors
#define BRIGHT_RED           0xFF0000FF
#define BRIGHT_GREEN         0x00FF00FF
#define BRIGHT_BLUE          0x0000FFFF
#define BRIGHT_YELLOW        0xFFFF00FF
#define BRIGHT_CYAN          0x00FFFFFF
#define BRIGHT_MAGENTA       0xFF00FFFF
#define BRIGHT_ORANGE        0xFFA500FF
#define BRIGHT_PINK          0xFFC0CBFF
#define BRIGHT_LIME          0x00FF00FF
#define BRIGHT_PURPLE        0x8000FFFF
#define BRIGHT_TEAL          0x008080FF
#define BRIGHT_VIOLET        0xEE82EEFF
#define BRIGHT_AQUA          0x00FFFF
#define BRIGHT_TURQUOISE     0x40E0D0FF
#define BRIGHT_CORAL         0xFF7F50FF
#define BRIGHT_GOLD          0xFFD700FF
#define BRIGHT_SPRING_GREEN  0x00FF7FFF
#define BRIGHT_SKY_BLUE      0x87CEEBFF
#define BRIGHT_MINT          0xF5FFFAFF
#define BRIGHT_PEACH         0xFFDAB9FF
#define BRIGHT_LAVENDER      0xE6E6FAFF
#define BRIGHT_BEIGE         0xF5F5DCFF
#define BRIGHT_OLIVE         0x808000FF
#define BRIGHT_MAROON        0xB03060FF
#define BRIGHT_NAVY          0x000080FF
#define BRIGHT_IVORY         0xFFFFF0FF
#define BRIGHT_ALMOND        0xFFEBCDFF
#define BRIGHT_HONEYDEW      0xF0FFF0FF
#define BRIGHT_CHARTREUSE    0x7FFF00FF
#define BRIGHT_AZURE         0xF0FFFFFF
#define BRIGHT_CRIMSON       0xDC143CFF
#define BRIGHT_INDIGO        0x4B0082FF
#define BRIGHT_TOMATO        0xFF6347FF
#define BRIGHT_PLUM          0xDDA0DDFF
#define BRIGHT_ORCHID        0xDA70D6FF
#define BRIGHT_SALMON        0xFA8072FF
#define BRIGHT_KHAKI         0xF0E68CFF
#define BRIGHT_SIENNA        0xA0522DFF
#define BRIGHT_SILVER        0xC0C0C0FF
#define BRIGHT_MISTY_ROSE    0xFFE4E1FF
#define BRIGHT_SEA_GREEN     0x2E8B57FF
#define BRIGHT_ROYAL_BLUE    0x4169E1FF
#define BRIGHT_SNOW          0xFFFAFAFF
#define BRIGHT_POWDER_BLUE   0xB0E0E6FF
#define BRIGHT_FIREBRICK     0xB22222FF
#define BRIGHT_LAWN_GREEN    0x7CFC00FF
#define BRIGHT_MEDIUM_ORCHID 0xBA55D3FF
#define BRIGHT_PALE_GREEN    0x98FB98FF

// Dark colors
#define DARK_BLUE           0x00008BFF
#define DARK_GREEN          0x006400FF
#define DARK_CYAN           0x008B8BFF
#define DARK_RED            0x8B0000FF
#define DARK_MAGENTA        0x8B008BFF
#define DARK_YELLOW         0x8B8B00FF
#define DARK_GRAY           0xA9A9A9FF
#define DARK_ORANGE         0xFF8C00FF
#define DARK_SALMON         0xE9967AFF
#define DARK_OLIVE_GREEN    0x556B2FFF
#define DARK_SLATE_BLUE     0x483D8BFF
#define DARK_SLATE_GRAY     0x2F4F4FFF
#define DARK_TURQUOISE      0x00CED1FF
#define DARK_VIOLET         0x9400D3FF
#define MIDNIGHT_BLUE       0x191970FF
#define INDIGO              0x4B0082FF
#define MAROON              0x800000FF
#define SADDLE_BROWN        0x8B4513FF
#define FOREST_GREEN        0x228B22FF
#define SEA_GREEN           0x2E8B57FF
#define MEDIUM_BLUE         0x0000CDFF
#define ROYAL_BLUE          0x4169E1FF
#define BLUE_VIOLET         0x8A2BE2FF
#define DIM_GRAY            0x696969FF
#define SLATE_BLUE          0x6A5ACDFF
#define SLATE_GRAY          0x708090FF
#define STEEL_BLUE          0x4682B4FF
#define OLIVE_DRAB          0x6B8E23FF
#define CADET_BLUE          0x5F9EA0FF
#define MEDIUM_SLATE_BLUE   0x7B68EEFF
#define MEDIUM_SEA_GREEN    0x3CB371FF
#define CHOCOLATE           0xD2691EFF
#define FIREBRICK           0xB22222FF
#define SADDLE_BROWN        0x8B4513FF
#define SIENNA              0xA0522DFF
#define ROSY_BROWN          0xBC8F8FFF
#define DARK_KHAKI          0xBDB76BFF
#define PERU                0xCD853FFF
#define INDIAN_RED          0xCD5C5CFF
#define LIGHT_CORAL         0xF08080FF
#define BROWN               0xA52A2AFF
#define BURGUNDY            0x800020FF
#define CHARCOAL            0x36454FFF
#define ASH_GRAY            0xB2BEB5FF
#define TEAL                0x008080FF
#define BRICK_RED           0xCB4154FF
#define DARK_BURGUNDY       0x3C1414FF
#define DARK_BROWN          0x654321FF

typedef struct	s_color
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

typedef struct	s_point
{
	double	x;
	double	y;
}				t_point;

typedef struct	s_fractal
{
	char		*name;
	mlx_t		*init;
	mlx_image_t	*img;
	mlx_image_t *img_buf;
	int32_t		win_width;
	int32_t		win_height;
	t_color		color;
	t_point		z;
	t_point		c;
	t_point		cur_pos;
	t_point		julia;
	t_point		shift;
	double		outside_value;
	int			iter_std;
	int			iter_max;
	int			iter_min;
	int			x;
	int			y;
	double		zoom;
	int			is_psychedelic;
	int			is_mutable;
}				t_fractal;

void	input_handler(int argc, char **argv, t_fractal *f);
void	fractol_init(t_fractal *f, char *fractal_name);
void	fractol_render(t_fractal *f);
void	action_listener(void *param);
void	error_exit(t_fractal *f);
void	esc_exit(t_fractal *f);
int		color_init(t_fractal *f, int color1, int color2);
double	scale(double unscaled_num, double new_min, double new_max, double old_max);
t_point	sum_point(t_point z1, t_point z2);
t_point	square_point(t_point z);
double	ft_atod(char *str);
int		is_double(char *str);

#endif
