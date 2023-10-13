/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseghier <lseghier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 00:06:47 by lseghier          #+#    #+#             */
/*   Updated: 2023/10/13 04:22:29 by lseghier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

int	mandelbrot(t_complex *c, double cr, double ci)
{
	int			i;
	double		temp;

	c->zr = 0;
	c->zi = 0;
	i = 0;
	while (i < MAX_ITER)
	{
		if (c->zr * c->zr + c->zi * c->zi > 4)
			break ;
		temp = 2 * c->zr * c->zi + ci;
		c->zr = c->zr * c->zr - c->zi * c->zi + cr;
		c->zi = temp;
		i++;
	}
	return (i);
}
