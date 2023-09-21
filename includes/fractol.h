/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseghier <lseghier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 01:05:19 by lseghier          #+#    #+#             */
/*   Updated: 2023/09/21 07:34:26 by lseghier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH		1920
# define HEIGHT		1080
# define MAX_ITER	110

# include <math.h>
# include <stdio.h>
# include "../minilibx-linux/mlx.h"
# include "keys.h"
# include "libft.h"

# define MANDELBROT 1
# define JULIA 2
# define BURNING_SHIP 3

typedef struct s_complex
{
	double	real;
	double	imag;
}t_complex;

typedef struct s_fractol
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*buf;
	int		set;
	double	zoom;
	double	imax;
	double	imin;
	double	rmax;
	double	rmin;	
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	int		x;
	int		y;
	int		color;
	int		(*fractol)(struct s_fractol *);
	int		(*coloring)(struct s_fractol *);
	int		(*mouse)(int, int, struct s_fractol *);
	int		(*key)(int, struct s_fractol *);
	int		(*move)(int, struct s_fractol *);
	int		(*draw)(struct s_fractol *);
	int		(*init)(struct s_fractol *);
	int		(*free)(struct s_fractol *);
}	t_fractol;

int		mandelbrot (t_complex *c);
int		julia (t_fractol *f, double zr, double zi);
int		burning_ship (t_fractol *f, int x, int y);

static void	set_pixel_color (t_fractol *f, int x, int y, int color);
static int	calculate_fractal (t_fractol *f, double pr, double pi);
void		render (t_fractol *f);
void		change_color (t_fractol *f);
void		change_set (t_fractol *f);

static void	zoom (t_fractol *f, double zoom);
static void	move (t_fractol *f, double distance, char direction);
static int	key_event_extend (int keycode, t_fractol *mlx);
static int  key_event (int keycode, t_fractol *mlx);
static int	mouse_event (int keycode, int x, int y, t_fractol *mlx);

void		clean_exit (int exit_code, t_fractol *f);
int			end_fractol (t_fractol *mlx);

#endif
