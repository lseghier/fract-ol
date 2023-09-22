/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseghier <lseghier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:45:21 by lseghier          #+#    #+#             */
/*   Updated: 2023/09/22 07:34:53 by lseghier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/keys.h"

void	zoom(t_fractol *f, double zoom)
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

void	move(t_fractol *f, double distance, char direction)
{
	double	center_r;
	double	center_i;

	center_r = f->rmax - f->rmin;
	center_i = f->imax - f->imin;
	if (direction == 'R')
	{
		f->rmax += center_r * distance;
		f->rmin += center_r * distance;
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

int	key_event_extend(int keycode, t_fractol *mlx)
{
	if (keycode == KEY_ONE)
		mlx->set = MANDELBROT;
	else if (keycode == KEY_TWO)
		mlx->set = JULIA;
	else if (keycode == KEY_THREE)
		mlx->set = BURNING_SHIP;
	else
		return (1);
	// get_complex_layout(mlx);
	render(mlx);
	return (0);
}

int	key_event(int keycode, t_fractol *mlx)
{
	if (keycode == EVENT_CLOSE_BTN)
	{
		end_fractol(mlx); // faire une fonction qui free tout
		return (0);
	}
	else if (keycode == KEY_PLUS)
		zoom(mlx, 0.9);
	else if (keycode == KEY_MINUS)
		zoom(mlx, 1.1);
	else if (keycode == KEY_RIGHT)
		move(mlx, 0.1, 'R');
	else if (keycode == KEY_LEFT)
		move(mlx, 0.1, 'L');
	else if (keycode == KEY_UP)
		move(mlx, 0.1, 'U');
	else if (keycode == KEY_DOWN)
		move(mlx, 0.1, 'D');
	// else if (keycode == KEY_SPACE)
	// 	color_shift(mlx);
	else
		return (key_event_extend(keycode, mlx));
	return (0);
}

int	mouse_event(int keycode, int x, int y, t_fractol *mlx)
{
	if (keycode == MOUSE_WHEEL_UP)
	{
		zoom(mlx, 0.5);
		x -= WIDTH / 2;
		y -= HEIGHT / 2;
		if (x > 0)
			move(mlx, 0.1, 'R');
		else if (x < 0)
			move(mlx, 0.1, 'L');
	}
	else if (keycode == MOUSE_WHEEL_DOWN)
		zoom(mlx, 2);
	else if (keycode == MOUSE_BTN)
	{
		if (mlx->set == JULIA)
		{
			mlx->julia_r = (double)x / WIDTH * 2 - 1;
			mlx->julia_i = (double)y / HEIGHT * 2 - 1;
		}
	}
	else
		return (1);
	render(mlx);
	return (0);
}
