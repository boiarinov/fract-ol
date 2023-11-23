/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboiarin <aboiarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:12:31 by aboiarin          #+#    #+#             */
/*   Updated: 2023/05/24 16:51:34 by aboiarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	l;
	int		r;

	l = 0;
	if (n == 0)
		return (0);
	while (s1[l] && s2[l] && s1[l] == s2[l]
		&& l < (n - 1))
		l++;
	r = (unsigned char)s1[l] - (unsigned char)s2[l];
	return (r);
}
