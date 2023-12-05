/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rainbow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboiarin <aboiarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:47:06 by aboiarin          #+#    #+#             */
/*   Updated: 2023/12/05 15:48:25 by aboiarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mlx_put_pixel(t_img *data, int x, int y, int color)
{
	char	*dest;

	dest = data->addr + (y * data->len + x * (data->bpp / 8));
	*(unsigned int *)dest = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_img	img;
	int		x;
	int		y;
	int		r;
	int		g;
	int		b;
	int		color;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Rainbow");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.len, &img.end);
	x = 0;
	while (++x < 1920)
	{
		y = 0;
		while (++y < 1080)
		{
			r = 255 * x / 1920;
			g = 255 * y / 1080;
			b = 255 - 255 * x / 1920;
			color = (r << 16) | (g << 8) | b;
			mlx_put_pixel(&img, x, y, color);
		}
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
