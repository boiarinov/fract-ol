/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboiarin <aboiarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:47:06 by aboiarin          #+#    #+#             */
/*   Updated: 2023/12/29 19:57:04 by aboiarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoom(t_img *f, double zoom)
{
	double	x_cent;
	double	y_cent;

	x_cent = f->x_min - f->x_max;
	y_cent = f->y_max - f->y_min;
	f->x_max = f->x_max + (x_cent - zoom * x_cent) / 2;
	f->x_min = f->x_max + zoom * x_cent;
	f->y_min = f->y_min + (y_cent - zoom * y_cent) / 2;
	f->y_max = f->y_min + zoom * y_cent;
}

static void	move(t_img *f, double distance, char direction)
{
	double	x_cent;
	double	y_cent;

	x_cent = f->x_max - f->x_min;
	y_cent = f->y_max - f->y_min;
	if (direction == 'U')
	{
		f->y_min += y_cent * distance;
		f->y_max += y_cent * distance;
	}
	else if (direction == 'D')
	{
		f->y_min -= y_cent * distance;
		f->y_max -= y_cent * distance;
	}
	else if (direction == 'R')
	{
		f->x_min += x_cent * distance;
		f->x_max += x_cent * distance;
	}
	else if (direction == 'L')
	{
		f->x_min -= x_cent * distance;
		f->x_max -= x_cent * distance;
	}
}

int	key_events(int key, t_img *f)
{
	if (key == KEY_ESC)
	{
		quit(f);
		return (0);
	}
	else if (key == KEY_PLUS)
		zoom(f, 0.5);
	else if (key == KEY_MINUS)
		zoom(f, 2);
	else if (key == KEY_UP || key == KEY_W)
		move(f, 0.2, 'U');
	else if (key == KEY_DOWN || key == KEY_S)
		move(f, 0.2, 'D');
	else if (key == KEY_LEFT || key == KEY_A)
		move(f, 0.2, 'L');
	else if (key == KEY_RIGHT || key == KEY_D)
		move(f, 0.2, 'R');
	else
		return (1);
	win_fill(f);
	return (0);
}

int	mouse_events(int key, int x, int y, t_img *f)
{
	if (key == MOUSE_WHEEL_UP)
	{
		zoom(f, 0.5);
		x -= WIDTH / 2;
		y -= HEIGHT / 2;
		if (y < 0)
			move(f, (double)y * -1 / HEIGHT, 'U');
		else if (y > 0)
			move (f, (double)y / HEIGHT, 'D');
		if (x > 0)
			move(f, (double)x / WIDTH, 'R');
		else if (x < 0)
			move(f, (double)x * -1 / WIDTH, 'L');
	}
	else if (key == MOUSE_WHEEL_DOWN)
		zoom(f, 2);
	else
		return (0);
	win_fill(f);
	return (0);
}

int	quit(t_img *f)
{
	clean_exit(f);
	return (0);
}
