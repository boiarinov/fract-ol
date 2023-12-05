/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboiarin <aboiarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:41:26 by aboiarin          #+#    #+#             */
/*   Updated: 2023/12/05 15:46:57 by aboiarin         ###   ########.fr       */
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

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Square and triangle");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.len, &img.end);
	x = 200;
	y = 200;
	while (x < 500)
	{
		mlx_put_pixel(&img, x, y, 0x00FF0000);
		x++;
	}
	while (y < 500)
	{
		mlx_put_pixel(&img, x, y, 0x00FF0000);
		y++;
	}
	while (x > 200)
	{
		mlx_put_pixel(&img, x, y, 0x00FF0000);
		x--;
	}
	while (y > 200)
	{
		mlx_put_pixel(&img, x, y, 0x00FF0000);
		y--;
	}
	x = 600;
	y = 600;
	while (x < 800)
	{
		mlx_put_pixel(&img, x, y, 0x00FF0000);
		y++;
		x++;
	}
	x = y;
	while (x > 400)
	{
		mlx_put_pixel(&img, x, y, 0x00FF0000);
		x--;
	}
	while (x < 600)
	{
		mlx_put_pixel(&img, x, y, 0x00FF0000);
		x++;
		y--;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
