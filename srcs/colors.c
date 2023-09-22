/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseghier <lseghier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 04:56:23 by lseghier          #+#    #+#             */
/*   Updated: 2023/09/22 07:49:34 by lseghier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	set_pixel_color(t_fractol *f, int x, int y, int color)
{
	f->buf[x * 4 + y * WIDTH * 4] = color;
	f->buf[x * 4 + y * WIDTH * 4 + 1] = color >> 8;
	f->buf[x * 4 + y * WIDTH * 4 + 2] = color >> 16;
	f->buf[x * 4 + y * WIDTH * 4 + 3] = color >> 24;
}

int	calculate_fractal(t_fractol *frac, double pr, double pi)
{
	int	nb_iter;

	nb_iter = 0;
	if (frac->set == MANDELBROT)
		nb_iter = mandelbrot(frac);
	else if (frac->set == JULIA)
		nb_iter = julia(frac, pr, pi);
	else if (frac->set == BURNING_SHIP)
		nb_iter = burning_ship(frac, pr, pi);
	return (nb_iter);
}

void	render(t_fractol *f)
{
	int		x;
	int		y;
	double	pr;
	double	pi;
	int		nb_iter;

	nb_iter = 0;
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			pr = 1.5 * (x - WIDTH / 2) / (0.5 * f->zoom * WIDTH) + f->move_x;
			pi = (y - HEIGHT / 2) / (0.5 * f->zoom * HEIGHT) + f->move_y;
			nb_iter = calculate_fractal(f, pr, pi);
			if (nb_iter == f->max_iter)
				set_pixel_color(f, x, y, 0);
			else
				set_pixel_color(f, x, y, f->color * nb_iter);
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

void	change_color(t_fractol *f)
{
	if (f->color == 0x000000)
		f->color = 0x0000FF;
	else if (f->color == 0x0000FF)
		f->color = 0x00FF00;
	else if (f->color == 0x00FF00)
		f->color = 0xFF0000;
	else if (f->color == 0xFF0000)
		f->color = 0xFFFF00;
	else if (f->color == 0xFFFF00)
		f->color = 0xFFFFFF;
	else if (f->color == 0xFFFFFF)
		f->color = 0x000000;
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
