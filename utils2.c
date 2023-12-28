/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboiarin <aboiarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 19:26:14 by aboiarin          #+#    #+#             */
/*   Updated: 2023/12/28 16:07:46 by aboiarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	skip_space_2(char *color)
{
	int	i;

	i = 0;
	while ((color[i] >= 9 && color[i] <= 13) || color[i] == ' ')
		i++;
	if (color[i] == '+')
		i++;
	if (color[i] == '0' && (color[i + 1]
			&& (color[i + 1] == 'x' || color[i] == 'X')))
		i = i + 2;
	return (i);
}

int	ft_atox(t_img *f, char *color)
{
	int	i;
	int	c;
	int	r;

	r = 0;
	i = 0;
	i = skip_space_2(color);
	c = 0;
	while (color[i] && ft_ishex(color[i]))
	{
		if (ft_isdigit(color[i]))
			r = (r * 16) + (color[i] - '0');
		else
			r = (r * 16) + (ft_toupper(color[i]) - 'A' + 10);
		i++;
		c++;
	}
	if (c == 6 && !color[i])
		return (r);
	else
		help(f);
	return (-1);
}

int	ft_ishex(int c)
{
	if (c >= '0' && c <= '9')
		return (c);
	c = ft_toupper(c);
	if (c >= 'A' && c <= 'F')
		return (c);
	else
		return (0);
}

void	clean_start(t_img *f)
{
	f->mlx = NULL;
	f->win = NULL;
	f->img = NULL;
	f->set = -1;
	f->x_min = 0;
	f->x_max = 0;
	f->y_min = 0;
	f->y_max = 0;
	f->x_const = 0;
	f->y_const = 0;
	f->scale_x = 0;
	f->offset_x = 0;
	f->focus_x = 0;
	f->buf = NULL;
	f->palette = NULL;
	f->pattern = -1;
	f->color = 0;
}

void	clean_exit(t_img *f)
{
	if (!f)
		exit(1);
	if (f->palette)
		free(f->palette);
	if (f->img)
		mlx_destroy_image(f->mlx, f->img);
	if (f->win && f->mlx)
		mlx_destroy_window(f->mlx, f->win);
	if (f->mlx)
	{
		mlx_loop_end(f->mlx);
		mlx_destroy_display(f->mlx);
		free(f->mlx);
	}
	exit(0);
}
