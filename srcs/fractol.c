/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseghier <lseghier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 06:01:45 by lseghier          #+#    #+#             */
/*   Updated: 2023/10/17 04:24:32 by lseghier         ###   ########.fr       */
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
	if (type_cmp(av[1], "m", 'M') || type_cmp(av[1], "mandelbrot", 'M'))
		f->set = 1;
	else if (type_cmp(av[1], "j", 'J') || type_cmp(av[1], "julia", 'J'))
		f->set = 2;
	else if (type_cmp(av[1], "burning_ship", 'B') || type_cmp(av[1], "b", 'B'))
		f->set = 3;
	else
	{
		ft_putendl_fd("mandelbrot = M | julia = J | burning_ship = B", 1);
		exit(0);
	}
}

static void	julia_start_values(t_fractol *f, int ac, char **av)
{
	if (f->set != JULIA || ac == 2)
	{
		f->reel_value = 0.254;
		f->imaginaire_value = 0.57;
		return ;
	}
	if (ac == 3)
		msg(f);
	if (!ft_strchr(av[2], '.'))
		msg(f);
	if (!ft_strchr(av[3], '.'))
		msg(f);
	f->reel_value = ft_atof(av[2]);
	f->imaginaire_value = ft_atof(av[3]);
	if (f->reel_value > 2.0 || f->reel_value < -2.0)
		msg(f);
	if (f->imaginaire_value >= 2.0 || f->imaginaire_value <= -2.0)
		msg(f);
}

static void	handle_args(t_fractol *f, int ac, char **av)
{
	get_set(f, av);
	if (f->set != JULIA && ac > 3)
		msg(f);
	else if (f->set == JULIA && ac > 5)
		msg(f);
	julia_start_values(f, ac, av);
	get_color(f, ac, av);
}	

int	main(int ac, char **av)
{
	t_fractol	f;

	if (ac < 2)
	{
		clean_init(&f);
		msg(&f);
	}
	clean_init(&f);
	handle_args(&f, ac, av);
	init(&f);
	render(&f);
	print_controls();
	mlx_hook(f.win, EVENT_CLOSE_BTN, 0, end_fractol, &f);
	mlx_key_hook(f.win, key_event, &f);
	mlx_mouse_hook(f.win, mouse_event, &f);
	mlx_loop(f.mlx);
}
