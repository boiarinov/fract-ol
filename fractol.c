/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboiarin <aboiarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:47:06 by aboiarin          #+#    #+#             */
/*   Updated: 2023/12/11 14:32:22 by aboiarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	clean_exit(t_img *f)
{
	if (!f)
		exit(1);
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

void	mlx_put_pixel(t_img *data, int x, int y, int color)
{
	char	*dest;

    dest = data->addr + (y * data->len + x * (data->bpp / 8));
    if (data->bpp == 32)
        *(unsigned int *)dest = color;
    else if (data->bpp == 24)
    {
        dest[0] = color & 0xFF;
        dest[1] = (color >> 8) & 0xFF;
        dest[2] = (color >> 16) & 0xFF;
    }
}

int	main(void)
{
	t_img	f;
	int		x;
	int		y;
	int		r;
	int		g;
	int		b;
	int		color;

	f.mlx = mlx_init();
	f.win = mlx_new_window(f.mlx, WIDTH, HEIGHT, "Rainbow");
	f.img = mlx_new_image(f.mlx, WIDTH, HEIGHT);
	f.addr = mlx_get_data_addr(f.img, &f.bpp, &f.len, &f.end);
	x = 0;
	while (++x < WIDTH)
	{
		y = 0;
		while (++y < HEIGHT)
		{
			r = 255 * x / WIDTH;
			g = 255 * y / HEIGHT;
			b = 255 - 255 * x / WIDTH;
			color = (r << 16) | (g << 8) | b;
			mlx_put_pixel(&f, x, y, color);
		}
	}
	mlx_hook(f.win, CLOSE_BTN, 0, clean_exit, &f);
	mlx_put_image_to_window(f.mlx, f.win, f.img, 0, 0);
	mlx_loop(f.mlx);
	return (0);
}
