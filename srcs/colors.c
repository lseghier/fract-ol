/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseghier <lseghier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 04:56:23 by lseghier          #+#    #+#             */
/*   Updated: 2023/10/17 04:20:39 by lseghier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	set_pixel_color(t_fractol *f, int x, int y, int color)
{
		f->buf[x * 4 + y * WIDTH * 4] = color;
		f->buf[x * 4 + y * WIDTH * 4 + 1] = color >> 8;
		f->buf[x * 4 + y * WIDTH * 4 + 2] = color >> 16;
		f->buf[x * 4 + y * WIDTH * 4 + 3] = color >> 24;
}

int	calculate_fractal(t_fractol *f, double pr, double pi)
{
	int	nb_iter;

	nb_iter = 0;
	if (f->set == MANDELBROT)
		nb_iter = mandelbrot(pr, pi);
	else if (f->set == JULIA)
		nb_iter = julia(f, pr, pi);
	else if (f->set == BURNING_SHIP)
		nb_iter = burning_ship(pr, pi);
	return (nb_iter);
}

void	render(t_fractol *f)
{
	int		x;
	int		y;
	double	pr;
	double	pi;
	int		nb_iter;

	mlx_clear_window(f->mlx, f->win);
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			pr = f->rmin + (double)x * (f->rmax - f->rmin) / WIDTH;
			pi = f->imax + (double)y
				* (f->imin - f->imax) / HEIGHT;
			nb_iter = calculate_fractal(f, pr, pi);
			set_pixel_color(f, x, y, f->palette[nb_iter]);
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

void	change_set(t_fractol *f)
{
	if (f->set == MANDELBROT)
		f->set = JULIA;
	else if (f->set == JULIA)
		f->set = BURNING_SHIP;
	else if (f->set == BURNING_SHIP)
		f->set = MANDELBROT;
}

void	color_shift(t_fractol *f)
{
	int	alt_color;

	f->color_pattern = (f->color_pattern +1) % 3;
	reinit_img(f);
	if (f->color == 0x000000)
		alt_color = 0x990F4B;
	else
		alt_color = f->color;
	if (f->color_pattern == 0)
		set_color_mono(f, alt_color);
	else if (f->color_pattern == 1)
		set_color_multiple(f, (int [8]){0xFF0000, 0xFF7F00, 0xFFFF00,
			0x00FF00, 0x0000FF, 0x4B0082, 0x9400D3, 0xFFFFFF}, 8);
	else if (f->color_pattern == 2)
		set_color_contrasted(f, alt_color);
}
