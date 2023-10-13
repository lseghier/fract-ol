/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseghier <lseghier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 01:05:19 by lseghier          #+#    #+#             */
/*   Updated: 2023/10/13 04:31:53 by lseghier         ###   ########.fr       */
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

typedef struct s_complex
{
	double	zr;
	double	zi;
}	t_complex;

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*buf;
	int		set;
	double	imin;
	double	rmin;
	double	imax;
	double	rmax;
	double	reel_value;
	double	imaginaire_value;
	int		*palette;
	int		color_pattern;
	int		color;
}	t_fractol;


int			mandelbrot(t_complex *c, double cr, double ci);
int			julia(t_fractol *f, double zr, double zi);
int			burning_ship(t_complex *f, int x, int y);

void	put_pixel_to_image(t_fractol *img, int x, int y, int color);

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
