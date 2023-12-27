/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboiarin <aboiarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:58:40 by boiarinov         #+#    #+#             */
/*   Updated: 2023/12/27 18:38:00 by aboiarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	manual(void)
{
	ft_printf("\nYou can choose which fractal to show and its color:\n");
	ft_printf("Example:\t./fractol <type> <color>\n\n");
	ft_printf("<type> for Mandelbrot is M and <type> for Julia is J\n");
	ft_printf("<color> is a hex color code that shall be formatted as");
	ft_printf("RRGGBB.\nHere are some examples:\n");
	colors();
	ft_printf("\nTherefore the input with color code shall look like this:\n");
	ft_printf("\tExample: ./fractol M 0066FF\n\n");
	ft_printf("For Julia, you can specify values for the fractal shape.\n");
	ft_printf("It shall be -2.0 and 2.0.\n");
	ft_printf("Example:\t./fractol J 0.285 0.01\n\n");
	ft_printf("Please note that in this case color can be set only");
	ft_printf("after the starting values.\n");
	ft_printf("Example:\t./fractol J 0.285 0.01 CC6600\n");
}

void	colors(void)
{
	ft_printf("\tPlum1: XFFBBFF Hotpink: 0XFF6EB4 Cyan: 0xffff\n");
}

void	help(t_img *f)
{
	ft_printf("🌙 fractol help:\n");
	manual();
	clean_exit(f);
}
