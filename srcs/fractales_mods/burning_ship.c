/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseghier <lseghier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 05:21:32 by lseghier          #+#    #+#             */
/*   Updated: 2023/09/21 05:23:30 by lseghier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		burning_ship(t_fractol *f, int x, int y)
{
	int		i;
	double	tmp;
	double	z_r;
	double	z_i;

	i = 0;
	z_r = 0;
	z_i = 0;
	while (z_r * z_r + z_i * z_i < 4 && i < f->max_iter)
	{
		tmp = z_r * z_r - z_i * z_i + f->c_r;
		z_i = fabs(2 * z_r * z_i) + f->c_i;
		z_r = tmp;
		i++;
	}
	return (i);
}
