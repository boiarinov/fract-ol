/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboiarin <aboiarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:47:47 by aboiarin          #+#    #+#             */
/*   Updated: 2023/11/27 17:05:29 by aboiarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft/libft.h"
# include "mlx/mlx.h"

typedef struct  s_img
{
    void    *img;
    char    *addr;
    int     bpp;
    int     len;
    int     end;
}           t_img;
