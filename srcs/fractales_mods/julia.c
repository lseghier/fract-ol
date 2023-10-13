/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseghier <lseghier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 02:53:47 by lseghier          #+#    #+#             */
/*   Updated: 2023/10/13 04:17:57 by lseghier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

int	julia(t_fractol *f, double zr, double zi)
{
	int		i;
	double	tmp;

	i = 0;
	while (i < MAX_ITER)
	{
		tmp = zr;
		zr = zr * zr - zi * zi + f->reel_value;
		zi = 2 * tmp * zi + f->imaginaire_value;
		if (zr * zr + zi * zi > 4)
			break ;
		i++;
	}
	return (i);
}
