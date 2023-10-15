/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseghier <lseghier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 03:39:21 by lseghier          #+#    #+#             */
/*   Updated: 2023/10/15 04:33:12 by lseghier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	print_fractal_options(void)
{
	ft_putstr_fd("+===============  Fractals Disponibles  ========", 1);
	ft_putendl_fd("=======+", 1);
	ft_putendl_fd("Choisissez le fractal que vous souhaitez", 1);
	ft_putendl_fd("\tM - Mandelbrot", 1);
	ft_putendl_fd("\tJ - Julia", 1);
	ft_putendl_fd("\tX - Mandelbox", 1);
	ft_putendl_fd("\e[36mExemples:\t./fractol <type>\n\t\t./fractol M\e[0m", 1);
	ft_putstr_fd("\nPour Julia, vous pouvez specifier les valeurs de ", 1);
	ft_putstr_fd("departs.\n", 1);
	ft_putstr_fd("Les valeurs doivent etres entre -2.0 et 2.0 et doivent\n", 1);
	ft_putendl_fd("etres des valeurs decimales contenant un point.", 1);
	ft_putendl_fd("\e[36mExemples:\t", 1);
	ft_putendl_fd("\t\t./fractol J\n\t\t./fractol J 0.285 0.013\e[0m", 1);
}

void	print_color_options(void)
{
	ft_putendl_fd("\n+===============  Couleur  ====================+", 1);
	ft_putstr_fd("Vous pouvez choisir la couleur du fractral en \n", 1);
	ft_putstr_fd("donnant son code hexadeciamal, le code hexadecimal\n", 1);
	ft_putendl_fd("doit etre au format RRGGBB:", 1);
	ft_putendl_fd("\tBlanc:\tFFFFFF\t\tNoir:\t000000", 1);
	ft_putendl_fd("\tRouge:\tFF0000\t\tVert:\t00FF00", 1);
	ft_putendl_fd("\tBleu:\t0000FF\t\tJaune:\tFFFF00", 1);
	ft_putstr_fd("\e[36mExemples:\t", 1);
	ft_putendl_fd("./fractol <type> <couleur>", 1);
	ft_putendl_fd("\t\t./fractol M 0066FF\e[0m", 1);
	ft_putendl_fd("\nPour Julia, vous pouvez specifier la couleurs apres", 1);
	ft_putendl_fd("les valeurs de depart.", 1);
	ft_putstr_fd("\e[36mExemples:\t", 1);
	ft_putendl_fd("./fractol J 0.285 0.013 CC6600", 1);
	ft_putendl_fd("\t\t./fractol J -0.4 0.6 00FF80\e[0m", 1);
}

void	print_controls(void)
{
	ft_putendl_fd("\n+===============  Controls  =================+", 1);
	ft_putendl_fd("WASD fleches directionnelles\tdeplacement.", 1);
	ft_putendl_fd("scroll souris\t\tzoom avant et arriere.", 1);
	ft_putendl_fd("Espace\t\tchange le paterne de couleur.", 1);
	ft_putendl_fd("1, 2, 3\t\t\tchange de fractal.", 1);
	ft_putendl_fd("ESC ou croix de la fentre\tquitte fract'ol.", 1);
	ft_putendl_fd("+============================================+\n", 1);
}

void	msg(t_fractol *f)
{
	print_fractal_options();
	print_color_options();
	clean_exit(EXIT_FAILURE, f);
}
