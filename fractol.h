/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboiarin <aboiarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:47:47 by aboiarin          #+#    #+#             */
/*   Updated: 2023/12/27 19:30:13 by aboiarin         ###   ########.fr       */
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
	double	real_min;
	double	real_max;
	double	imagine_min;
	double	imagine_max;
	double	real_const;
	double	imagine_const;
	double	scale_x;
	double	real_x;
	double	focus_x;
	char	*buf;
	int		*palette;
	int		pattern;
	int		color;
}				t_img;

void	clean_start(t_img *f);
void	win_init(t_img *f);
void	colors(void);
int		key_events(int code, t_img *mlx);
int		mouse_events(int code, int x, int y, t_img *mlx);
void	win_set(t_img *f);
void	mlx_put_pixel(t_img *f, int x, int y, int color);

void	help(t_img *f);
void	clean_exit(t_img *f);
int		quit(t_img *f);

double	ft_atof(char *str);

void	set_colors(t_img *f, int argc, char **argv);

void	set_layout(t_img *f);

void	color_shift(t_img *f);

void	reinit_img(t_img *f);

int		mandelbrot(double cr, double ci);

int		julia(t_img *f, double zr, double zi);

int		ft_atox_color(t_img *f, char *color);

int		create_fractal(t_img *f, double pr, double pi);

int		ft_ishexdigit(int c);

void	set_pixels(t_img *f, int x, int y, int color);

int		skip_space_sign_0x(char *color);

int		interpolate(int startcolor, int endcolor, double fraction);

void	color_shift_striped(t_img *f);

void	set_color_mono(t_img *f, int color);

#endif