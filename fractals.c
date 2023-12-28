/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboiarin <aboiarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:41:24 by aboiarin          #+#    #+#             */
/*   Updated: 2023/12/28 15:41:53 by aboiarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(double m1x, double m1y)
{
	int		i;
	double	mx;
	double	my;
	double	t;

	mx = 0;
	my = 0;
	i = 0;
	while (i < MAX_I)
	{
		if ((mx * mx + my * my) > 4.0)
			break ;
		t = 2 * mx * my + m1y;
		mx = mx * mx - my * my + m1x;
		my = t;
		i++;
	}
	return (i);
}

int	julia(t_img *f, double jx, double jy)
{
	int		i;
	double	t;

	i = 0;
	while (i < MAX_I)
	{
		if ((jy * jy + jx * jx) > 4.0)
			break ;
		t = 2 * jx * jy + f->y_const;
		jx = jx * jx - jy * jy + f->x_const;
		jy = t;
		i++;
	}
	return (i);
}
