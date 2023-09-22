/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseghier <lseghier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 06:01:45 by lseghier          #+#    #+#             */
/*   Updated: 2023/09/22 08:04:04 by lseghier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	type_cmp(char *av, char *str, char c)
{
	int	i;

	i = 0;
	if (!av || !av[i])
		return (-1);
	while (av[i])
	{
		av[i] = ft_tolower(av[i]);
		i++;
	}
	if (ft_strncmp(av, str, ft_strlen(str) + 1))
		return (0);
	return (1);
}

void	get_set(t_fractol *f, char **av)
{
	if (type_cmp(av[1], "mandelbrot", 'm'))
		f->set = 1;
	else if (type_cmp(av[1], "julia", 'j'))
		f->set = 2;
	else if (type_cmp(av[1], "burningship", 'b'))
		f->set = 3;
	else
	{
		ft_putendl_fd("usage: ./fractol [mandelbrot | julia | burningship]", 1);
		exit(0);
	}
}

void	julia_start_values(t_fractol *f, int ac, char **av)
{
	if (ac == 3)
	{
		f->c_r = ft_atof(av[2]);
		f->c_i = ft_atof(av[3]);
	}
	else
	{
		f->c_r = -0.7;
		f->c_i = 0.27015;
	}
}

void	init_fractol(t_fractol *f, int ac, char **av)
{
	f->move_x = 0.2;
	f->move_y = 0.2;
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "fractol");
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->data = (int *)mlx_get_data_addr(f->img, &f->bpp, &f->size_l, &f->endian);
	f->set = 0;
	f->max_iter = 50;
	f->zoom = 1;
	f->x1 = -2.1;
	f->x2 = 0.6;
	f->y1 = -1.2;
	f->y2 = 1.2;
	f->c_r = 0;
	f->c_i = 0;
	f->mouse_x = 0;
	f->mouse_y = 0;
	f->color = 0;
	f->color_max = 0x000000;
	f->color_min = 0xFFFFFF;
	f->color_value = 1;
	f->motion = 0;
	f->motion_x = 0;
	f->buf = NULL;
	f->motion_y = 0;
}

int	main(int ac, char **av)
{
	t_fractol	f;

	init_fractol(&f, ac, av);
	if (ac == 2)
		get_set(&f, av);
	if (f.set == 2)
		julia_start_values(&f, ac, av);
	render(&f);
	mlx_hook(f.win, 2, 0, key_event, &f);
	mlx_hook(f.win, 4, 0, mouse_event, &f);
	mlx_hook(f.win, 6, 0, mouse_event, &f);
	mlx_hook(f.win, 17, 0, end_fractol, &f);
	mlx_loop(f.mlx);
	return (0);
}
