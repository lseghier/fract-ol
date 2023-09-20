/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseghier <lseghier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:45:21 by lseghier          #+#    #+#             */
/*   Updated: 2023/09/20 13:58:34 by lseghier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoom(t_fractol *f, double zoom)
{
	double	center_r;
	double	center_i;

	center_r = (f->rmax + f->rmin);
	center_i = (f->imax + f->imin);
	f->rmax = f->rmax + (center_r - zoom * center_r) / 2;
	f->rmin = f->rmax + zoom * center_r;
	f->imin = f->imin - (center_r - zoom * center_r) / 2;
	f->imax = f->imin + zoom * center_i;
}
static void	move(t_fractol *f, double distance, char direction)
{
	double center_r;
	double center_i;

	center_r = f->rmax - f->rmin;
	center_i = f->imax - f->imin;
	if (direction == 'R')
	{
		f->rmax += center_r *distance;
		f->rmin += center_r *distance;
	}
	else if (direction == 'L')
	{
		f->rmax -= center_r * distance;
		f->rmin -= center_r * distance;
	}
	else if (direction == 'U')
	{
		f->imax -= center_i * distance;
		f->imin -= center_i * distance;
	}
	else if (direction == 'D')
	{
		f->imax += center_i * distance;
		f->imin += center_i * distance;
	}
}

static int	key_event_extend (int keycode, t_fractol *mlx)
{
	if (keycode == KEY_ONE)
		mlx->set = MANDELBROT;
	else if (keycode == KEY_TWO)
		mlx->set = JULIA;
	else if (keycode == KEY_THREE)
		mlx->set = BURNING_SHIP;
	else
		return(1);
	get_complex_layout(mlx);
	render(mlx);
	return (0);
}

static int	key_event (int	keycode, t_fractol *mlx)
{
	if (keycode == EVENT_CLOSE_BTN)
		exit(0); // faire une fonction qui free tout
}
