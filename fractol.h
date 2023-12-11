/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboiarin <aboiarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:47:47 by aboiarin          #+#    #+#             */
/*   Updated: 2023/12/11 14:23:20 by aboiarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include "keys.h"

# define WIDTH 800
# define HEIGHT 800
# define MAX_I 60

# define MANDELBROT 1
# define JULIA 2

typedef struct  s_img
{
	void	*mlx;
	void	*win;
	void	*img;
	char    *addr;
	int     bpp;
	int     len;
	int     end;
}           t_img;

#endif