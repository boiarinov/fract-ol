/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboiarin <aboiarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:47:06 by aboiarin          #+#    #+#             */
/*   Updated: 2023/12/27 19:24:01 by aboiarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_julia(t_img *f, int argc, char **argv)
{
	if (f->set != JULIA || argc == 2)
	{
		f->real_const = -0.766667;
		f->imagine_const = -0.090000;
		return ;
	}
	if (argc == 3)
		help(f);
	if (!ft_strchr(argv[2], '.') || !ft_strchr(argv[3], '.'))
		help(f);
	f->real_const = ft_atof(argv[2]);
	f->imagine_const = ft_atof(argv[3]);
	if (f->real_const > 2.0 || f->real_const < -2.0
		|| f->imagine_const >= 2.0 || f->imagine_const <= -2.0)
		help(f);
}

void	set_type(t_img *f, char **argv)
{
	if (argv[1][0] == 'M' || argv[1][0] == 'm')
		f->set = MANDELBROT;
	else if (argv[1][0] == 'J' || argv[1][0] == 'j')
		f->set = JULIA;
	else
		help(f);
}

void	arg_handler(t_img *f, int argc, char **argv)
{
	set_type(f, argv);
	if (f->set != JULIA && argc > 3)
		help(f);
	else if (f->set == JULIA && argc > 5)
		help(f);
	set_julia(f, argc, argv);
	set_colors(f, argc, argv);
}

int	main(int argc, char **argv)
{
	t_img	f;

	if (argc < 2)
		help(&f);
	clean_start(&f);
	arg_handler(&f, argc, argv);
	win_init(&f);
	win_set(&f);
	mlx_hook(f.win, CLOSE_BTN, 0, quit, &f);
	mlx_key_hook(f.win, key_events, &f);
	mlx_mouse_hook(f.win, mouse_events, &f);
	mlx_loop(f.mlx);
	return (0);
}
