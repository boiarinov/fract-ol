/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboiarin <aboiarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:47:47 by aboiarin          #+#    #+#             */
/*   Updated: 2023/12/28 16:28:10 by aboiarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include "keys.h"

# define WIDTH 800
# define HEIGHT 800
# define MAX_I 60

# define MANDELBROT 1
# define JULIA 2

typedef struct s_img
{
	void	*mlx;
	void	*win;
	void	*img;
	int		set;
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
	double	x_const;
	double	y_const;
	double	scale_x;
	double	offset_x;
	double	focus_x;
	char	*buf;
	int		*palette;
	int		pattern;
	int		color;
}				t_img;

/* creators */
void	win_init(t_img *f);
void	win_fill(t_img *f);
void	set_layout(t_img *f);

void	reinit_img(t_img *f);
int		create_fractal(t_img *f, double pr, double pi);
int		mandelbrot(double cr, double ci);
int		julia(t_img *f, double zr, double zi);

/* colors */
void	set_colors(t_img *f, int argc, char **argv);
void	set_color_mono(t_img *f, int color);
void	set_pattern(t_img *f);
int		interpolate(int startcolor, int endcolor, double fraction);
void	color_pixels(t_img *f, int x, int y, int color);

/* checkers */
int		ft_ishex(int c);

/* converters */
double	ft_atod(char *str);
int		ft_atox(t_img *f, char *color);

/* utils & helpers */
void	clean_start(t_img *f);
void	help(t_img *f);
void	clean_exit(t_img *f);
int		quit(t_img *f);
int		key_events(int code, t_img *mlx);
int		mouse_events(int code, int x, int y, t_img *mlx);

void	colors(void);
void	draw_colors(t_img *f, int color);

#endif