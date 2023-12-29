/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboiarin <aboiarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:41:24 by aboiarin          #+#    #+#             */
/*   Updated: 2023/12/29 19:42:59 by aboiarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(double x_pix, double y_pix)
{
	int		i;
	double	x;
	double	y;
	double	t;

	x = 0;
	y = 0;
	i = 0;
	while (i < MAX_I)
	{
		if ((x * x + y * y) > 4.0)
			break ;
		t = 2 * x * y + y_pix;
		x = x * x - y * y + x_pix;
		y = t;
		i++;
	}
	return (i);
}

int	julia(t_img *f, double x, double y)
{
	int		i;
	double	t;

	i = 0;
	while (i < MAX_I)
	{
		if ((y * y + x * x) > 4.0)
			break ;
		t = 2 * x * y + f->y_const;
		x = x * x - y * y + f->x_const;
		y = t;
		i++;
	}
	return (i);
}
