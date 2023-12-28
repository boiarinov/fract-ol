/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboiarin <aboiarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:41:15 by aboiarin          #+#    #+#             */
/*   Updated: 2023/12/28 16:15:04 by aboiarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	manual(void)
{
	ft_printf("\nYou can choose which fractal to show and its color:\n");
	ft_printf("Example:\t./fractol <type> <color>\n");
	ft_printf("<type> for Mandelbrot is M and <type> for Julia is J.\n\n");
	ft_printf("It's possible to use only the type value to display ");
	ft_printf("the fractal in default color (dark orange: ff8c00).\n");
	ft_printf("<color> is a hex color code that shall be formatted as ");
	ft_printf("RRGGBB.\n\nHere are some colors examples:\n");
	colors();
	ft_printf("\nTherefore the input with color code shall look like this:\n");
	ft_printf("Example:\t./fractol M 7fff00\n\n");
	ft_printf("For Julia, you can specify values for the fractal shape.\n");
	ft_printf("It shall be from -2.0 to 2.0.\n");
	ft_printf("Examples:\t./fractol J 0.388 0.367\n");
	ft_printf("\t\t./fractol J 0.285 0.01\n\n");
	ft_printf("Please note, in this case color can be set only ");
	ft_printf("after the starting values.\n");
	ft_printf("Example:\t./fractol J 0.388 0.367 f5fffa\n");
}

void	colors(void)
{
	ft_printf("\tChartreuse: 7fff00\tTurquoise: 40e0d0\tMint cream: f5fffa\n");
	ft_printf("\tSienna: ff8247\t\tMagenta: ff00ff\t\tDark red: 8b0000\n");
	ft_printf("\tDodger blue: 1e90ff\tRosybrown: ffc1c1\t");
	ft_printf("Dark golden rod: ffb90f\n");
}

void	help(t_img *f)
{
	ft_printf("🌙 fractol help:\n");
	manual();
	clean_exit(f);
}
