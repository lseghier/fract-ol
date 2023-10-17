/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseghier <lseghier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 23:30:14 by lseghier          #+#    #+#             */
/*   Updated: 2023/10/17 04:21:42 by lseghier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	clean_init(t_fractol *f)
{
	f->mlx = NULL;
	f->win = NULL;
	f->img = NULL;
	f->buf = NULL;
	f->set = -1;
	f->rmin = 0;
	f->rmax = 0;
	f->imin = 0;
	f->imax = 0;
	f->reel_value = 0;
	f->imaginaire_value = 0;
	f->palette = NULL;
	f->color_pattern = -1;
	f->color = 0;
}

void	get_complex_space(t_fractol *f)
{
	if (f->set == JULIA)
	{
		f->rmin = -2.0;
		f->rmax = 2.0;
		f->imin = -2.0;
		f->imax = f->imin + (f->rmax - f->rmin)
			* HEIGHT / WIDTH;
	}
	else if (f->set == BURNING_SHIP)
	{
		f->rmin = -1.0;
		f->rmax = 2.5;
		f->imin = -1.0;
		f->imax = f->imin + (f->rmax - f->rmin)
			* HEIGHT / WIDTH;
	}
	else
	{
		f->rmin = -2.0;
		f->rmax = 1.0;
		f->imin = -1.0;
		f->imax = f->imin + (f->rmax - f->rmin)
			* HEIGHT / WIDTH;
	}
}

static void	init_img(t_fractol *f)
{
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*buf;

	f->palette = ft_calloc((MAX_ITER + 1), sizeof(int));
	if (!(f->palette))
		clean_exit(msg2("error initializing color scheme.", "", 1), f);
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!(f->img))
		clean_exit(msg2("image creation error.", "", 1), f);
	buf = mlx_get_data_addr(f->img, &pixel_bits, &line_bytes, &endian);
	f->buf = buf;
}

void	reinit_img(t_fractol *f)
{
	if (f->mlx && f->img)
		mlx_destroy_image(f->mlx, f->img);
	if (f->palette)
		free(f->palette);
	if (f->buf)
		f->buf = NULL;
	init_img(f);
}

void	init(t_fractol *f)
{
	f->mlx = mlx_init();
	if (!f->mlx)
		clean_exit(msg2("MLX: error connecting to mlx.", "", 1), f);
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "Fractol");
	if (!f->win)
		clean_exit(msg2("MLX: error creating window.", "", 1), f);
	get_complex_space(f);
	color_shift(f);
}
