/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseghier <lseghier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 01:05:19 by lseghier          #+#    #+#             */
/*   Updated: 2023/09/20 09:46:27 by lseghier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH		1920
# define HEIGHT		1080
# define MAX_ITER	110

# include <math.h>
# include <stdio.h>
# include "mlx.h"
# include "keys.h"
# include "libft.h"

typedef struct	s_complex
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
	int	set;
	double	zoom;
	double	imax;
	double	imin;
	double	rmax;
	double	rmin;	

}	t_fractol;

#endif
