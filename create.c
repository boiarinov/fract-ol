/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboiarin <aboiarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:38:12 by boiarinov         #+#    #+#             */
/*   Updated: 2023/12/27 19:29:08 by aboiarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_layout(t_img *f)
{
	if (f->set == JULIA)
	{
		f->real_min = -2.0;
		f->real_max = 2.0;
		f->imagine_min = -2.0;
		f->imagine_max = f->imagine_min
			+ (f->real_max - f->real_min) * HEIGHT / WIDTH;
	}
	else
	{
		f->real_min = -2.0;
		f->real_max = 1.0;
		f->imagine_max = -1.5;
		f->imagine_min = f->imagine_max
			+ (f->real_max - f->real_min) * HEIGHT / WIDTH;
	}
}

void	set_colors(t_img *f, int argc, char **argv)
{
	if (f->set == JULIA && argc == 5)
		f->color = ft_atox_color(f, argv[4]);
	else if (f->set != JULIA && argc == 3)
		f->color = ft_atox_color(f, argv[2]);
	if (argc == 2 || (f->set == JULIA && argc == 4))
		f->color = 0xff8c00;
}

void	win_set(t_img *f)
{
	int		x;
	int		y;
	double	pr;
	double	pi;
	int		nb_iter;

	mlx_clear_window(f->mlx, f->win);
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			pr = f->real_min + (double)x * (f->real_max - f->real_min)
				/ WIDTH;
			pi = f->imagine_max + (double)y * (f->imagine_min - f->imagine_max)
				/ HEIGHT;
			nb_iter = create_fractal(f, pr, pi);
			set_pixels(f, x, y, f->palette[nb_iter]);
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

int	create_fractal(t_img *f, double pr, double pi)
{
	int	nb_iter;

	nb_iter = 0;
	if (f->set == MANDELBROT)
		nb_iter = mandelbrot(pr, pi);
	else if (f->set == JULIA)
		nb_iter = julia(f, pr, pi);
	return (nb_iter);
}

void	set_pixels(t_img *f, int x, int y, int color)
{
	f->buf[x * 4 + y * WIDTH * 4] = color;
	f->buf[x * 4 + y * WIDTH * 4 + 1] = color >> 8;
	f->buf[x * 4 + y * WIDTH * 4 + 2] = color >> 16;
	f->buf[x * 4 + y * WIDTH * 4 + 3] = color >> 24;
}
