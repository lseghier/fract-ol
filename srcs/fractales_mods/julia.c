/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseghier <lseghier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 02:53:47 by lseghier          #+#    #+#             */
/*   Updated: 2023/09/22 07:41:19 by lseghier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

int	julia(t_fractol *f, double zr, double zi)
{
	int		i;
	double	tmp;

	i = 0;
	while (i < f->max_iter)
	{
		tmp = zr;
		zr = zr * zr - zi * zi + f->c_r;
		zi = 2 * tmp * zi + f->c_i;
		if (zr * zr + zi * zi > 4)
			break ;
		i++;
	}
	return (i);
}
