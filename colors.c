/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboiarin <aboiarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:41:49 by aboiarin          #+#    #+#             */
/*   Updated: 2023/12/29 19:42:59 by aboiarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_pattern(t_img *f)
{
	int	shade;

	f->pattern = (f->pattern + 1) % 9;
	reinit_img(f);
	if (f->color == 0x000000)
		shade = 0xFFFFFF;
	else
		shade = f->color;
	if (f->pattern == 0)
		draw_colors(f, shade);
}

void	draw_colors(t_img *f, int color)
{
	int		i;
	int		j;
	double	fraction;
	int		shade1;
	int		shade2;

	shade1 = 0x000000;
	shade2 = color;
	i = 0;
	while (i < MAX_I)
	{
		j = 0;
		while (j < MAX_I / 2)
		{
			fraction = (double)j / (MAX_I / 2);
			f->palette[i + j] = interpolate(shade1, shade2, fraction);
			j++;
		}
		shade1 = shade2;
		shade2 = 0xFFFFFF;
		i += j;
	}
	f->palette[MAX_I - 1] = 0;
}

int	interpolate(int start, int end, double fraction)
{
	int	s_rgb[3];
	int	e_rgb[3];

	s_rgb[0] = ((start >> 16) & 0xFF);
	s_rgb[1] = ((start >> 8) & 0xFF);
	s_rgb[2] = ((start >> 0) & 0xFF);
	e_rgb[0] = ((end >> 16) & 0xFF);
	e_rgb[1] = ((end >> 8) & 0xFF);
	e_rgb[2] = ((end >> 0) & 0xFF);
	s_rgb[0] = (e_rgb[0] - s_rgb[0]) * fraction + s_rgb[0];
	s_rgb[1] = (e_rgb[1] - s_rgb[1]) * fraction + s_rgb[1];
	s_rgb[2] = (e_rgb[2] - s_rgb[2]) * fraction + s_rgb[2];
	return (0xFF << 24 | s_rgb[0] << 16 | s_rgb[1] << 8 | s_rgb[2]);
}

void	color_pixels(t_img *f, int x, int y, int color)
{
	f->buf[x * 4 + y * WIDTH * 4] = color;
	f->buf[x * 4 + y * WIDTH * 4 + 1] = color >> 8;
	f->buf[x * 4 + y * WIDTH * 4 + 2] = color >> 16;
	f->buf[x * 4 + y * WIDTH * 4 + 3] = color >> 24;
}
