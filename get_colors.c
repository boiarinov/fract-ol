/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboiarin <aboiarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:12:06 by aboiarin          #+#    #+#             */
/*   Updated: 2023/12/05 16:20:06 by aboiarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_colors(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

unsigned char	get_t(int color)
{
	return (((unsigned char *)&color)[3]);
}

unsigned char	get_r(int color)
{
	return (((unsigned char *)&color)[2]);
}

unsigned char	get_g(int color)
{
	return (((unsigned char *)&color)[1]);
}

unsigned char	get_b(int color)
{
	return (((unsigned char *)&color)[0]);
}
