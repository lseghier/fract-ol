/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseghier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 00:06:47 by lseghier          #+#    #+#             */
/*   Updated: 2023/09/21 03:07:18 by lseghier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/../includes/fractol.h"

int	mandelbrot(t_complex c)
{
	int				i;
	t_complex		z;
	double			temp;

	z.real = 0;
	z.imag = 0;
	i = 0;
	while (i < MAX_ITER)
	{
		temp = z.real;
		z.real = z.real * z.real - z.imag + c.real;
		z.imag = 2 * temp * z.imag + c.imag;
		if (z.real * z.real + z.imag * z.imag >= 4)
			return (i);
		i++;
	}
	return (MAX_ITER);
}
