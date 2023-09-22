/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseghier <lseghier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 01:05:19 by lseghier          #+#    #+#             */
/*   Updated: 2023/09/22 07:55:01 by lseghier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 1920
# define HEIGHT 1080
# define MAX_ITER 110

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "keys.h"
# include <math.h>
# include <stdio.h>

# define MANDELBROT 1
# define JULIA 2
# define BURNING_SHIP 3

typedef struct s_fractol
{
	double	z;
	int		max_iter;
	void	*mlx;
	void	*win;
	void	*img;
	char	*buf;
	int		set;
	int		*data;
	double	zoom;
	double	imax;
	double	imin;
	double	rmax;
	double	julia_r;
	double	julia_i;
	double	rmin;
	double	move_x;
	double	move_y;
	double	c_r;
	double	c_i;
	double	zr;
	double	zi;
	int		x;
	int		y;
	int		color;
	int		color_max;
	int		color_min;
	int		color_value;
	double	x1;
	double	y1;
	double	x2;
	double	y2;
	int		size_l;
	int		bpp;
	int		endian;
	double	motion_x;
	double	motion_y;
	double	motion;
	int		mouse_x;
	int		mouse_y;
}			t_fractol;

int			mandelbrot(t_fractol *c);
int			julia(t_fractol *f, double zr, double zi);
int			burning_ship(t_fractol *f, int x, int y);

void		set_pixel_color(t_fractol *f, int x, int y, int color);
int			calculate_fractal(t_fractol *f, double pr, double pi);
void		render(t_fractol *f);
void		change_color(t_fractol *f);
void		change_set(t_fractol *f);

void		zoom(t_fractol *f, double zoom);
void		move(t_fractol *f, double distance, char direction);
int			key_event_extend(int keycode, t_fractol *mlx);
int			key_event(int keycode, t_fractol *mlx);
int			mouse_event(int keycode, int x, int y, t_fractol *mlx);

int			type_cmp(char *av, char *str, char c);
void		get_set(t_fractol *f, char **av);
void		julia_start_values(t_fractol *f, int ac, char **av);
void		init_fractol(t_fractol *f, int ac, char **av);

void		clean_exit(int exit_code, t_fractol *f);
int			end_fractol(t_fractol *mlx);

#endif
