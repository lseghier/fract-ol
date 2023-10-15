/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseghier <lseghier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 00:06:47 by lseghier          #+#    #+#             */
/*   Updated: 2023/10/15 03:53:26 by lseghier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

int	mandelbrot(double cr, double ci)
{
	int			i;
	double		zr;
	double		zi;
	double		temp;

	zr = 0;
	zi = 0;
	i = 0;
	while (i < MAX_ITER)
	{
		if (zr * zr + zi * zi > 4)
			break ;
		temp = 2 * zr * zi + ci;
		zr = zr * zr - zi * zi + cr;
		zi = temp;
		i++;
	}
	return (i);
}
