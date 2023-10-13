/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseghier <lseghier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 05:21:32 by lseghier          #+#    #+#             */
/*   Updated: 2023/10/13 04:19:45 by lseghier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

int	burning_ship(t_complex *c, int x, int y)
{
	int		i;
	double	tmp;
	double	z_r;
	double	z_i;

	i = 0;
	z_r = 0;
	z_i = 0;
	while (z_r * z_r + z_i * z_i < 4 && i < MAX_ITER)
	{
		tmp = z_r * z_r - z_i * z_i + c->zr;
		z_i = fabs(2 * z_r * z_i) + c->zi;
		z_r = tmp;
		i++;
	}
	return (i);
}
