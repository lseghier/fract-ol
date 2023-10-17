/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseghier <lseghier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 01:05:19 by lseghier          #+#    #+#             */
/*   Updated: 2023/10/17 02:20:11 by lseghier         ###   ########.fr       */
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


int		mandelbrot(double cr, double ci);
int		julia(t_fractol *f, double zr, double zi);
//int		burning_ship(t_fractol *f, int x, int y);
int		burning_ship(double cr, double ci);
int		calculate_fractal(t_fractol *f, double pr, double pi);
void	render(t_fractol *f);
int		get_percent_color(int color, double percent);
void	change_set(t_fractol *f);
void	color_shift(t_fractol *f);

void	get_color(t_fractol *f, int ac, char **av);
double	ft_atof(char *str);

void	set_color_mono(t_fractol *f, int color);
void	set_color_multiple(t_fractol *f, int colors[4], int n);
void	set_color_contrasted(t_fractol *f, int color);


void	print_fractal_options(void);
void	print_color_options(void);
void	print_controls(void);
void	msg(t_fractol *f);

int		key_event_extend(int keycode, t_fractol *mlx);
int		key_event(int keycode, t_fractol *mlx);
int		mouse_event(int keycode, int x, int y, t_fractol *mlx);

void	clean_exit(int exit_code, t_fractol *f);
int		end_fractol(t_fractol *mlx);
int		msg2(char *str, char *str2, int errno);
int		ft_ishexdigit(char c);
int		ft_isspace(char c);
int		ft_isdigit(char c);

void	clean_init(t_fractol *f);
void	get_complex_space(t_fractol *f);
void	reinit_img(t_fractol *f);
void	init(t_fractol *f);



#endif
