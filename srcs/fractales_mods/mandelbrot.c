/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseghier <lseghier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 00:06:47 by lseghier          #+#    #+#             */
/*   Updated: 2023/09/22 07:21:40 by lseghier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

int	mandelbrot(t_fractol *c)
{
	int			i;
	double		temp;

	c->zr = 0;
	c->zi = 0;
	i = 0;
	while (i < MAX_ITER)
	{
		temp = c->c_r;
		c->zr = c->zr * c->zr - c->zi * c->zi + c->zr;
		c->zi = 2 * temp * c->zi + c->c_i;
		if (c->zr * c->zr + c->zi * c->zi >= 4)
			return (i);
		i++;
	}
	return (MAX_ITER);
}
