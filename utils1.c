/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboiarin <aboiarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:40:57 by aboiarin          #+#    #+#             */
/*   Updated: 2023/12/28 16:00:24 by aboiarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_img(t_img *f)
{
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*buf;

	f->palette = ft_calloc((MAX_I + 1), sizeof(int));
	if (!(f->palette))
		clean_exit(f);
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!(f->img))
		clean_exit(f);
	buf = mlx_get_data_addr(f->img, &pixel_bits, &line_bytes, &endian);
	f->buf = buf;
}

void	reinit_img(t_img *f)
{
	if (f->mlx && f->img)
		mlx_destroy_image(f->mlx, f->img);
	if (f->palette)
		free(f->palette);
	if (f->buf)
		f->buf = NULL;
	init_img(f);
}

void	win_init(t_img *f)
{
	f->mlx = mlx_init();
	if (!f->mlx)
		clean_exit(f);
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "fract-ol");
	if (!f->win)
		clean_exit(f);
	f->scale_x = 2.0;
	f->offset_x = 0.5;
	f->focus_x = 1.0;
	set_layout(f);
	set_pattern(f);
}

static int	skip_space(char *str, int *n)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*n *= -1;
		i++;
	}
	return (i);
}

double	ft_atod(char *str)
{
	int		i;
	double	r;
	int		n;
	double	div;

	r = 0;
	div = 0.1;
	n = 1;
	i = skip_space(str, &n);
	while (str[i] && ft_isdigit(str[i]) && str[i] != '.')
	{
		r = (r * 10.0) + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		r = r + ((str[i] - '0') * div);
		div *= 0.1;
		i++;
	}
	if (str[i] && !ft_isdigit(str[i]))
		return (-1);
	return (r * n);
}
