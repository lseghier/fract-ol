/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseghier <lseghier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 01:06:02 by lseghier          #+#    #+#             */
/*   Updated: 2023/09/12 04:36:31 by lseghier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "includes/fractol.h"
#include "./includes/minilibx-linux/mlx.h"
#include <math.h>

#define WIDTH 1920
#define HEIGHT 1080
#define MAX_ITER 50

typedef struct s_complex
{
    double real;
    double imag;
} t_complex;

int mandelbrot(t_complex c)
{
    int i;
    t_complex z;
    z.real = 0;
    z.imag = 0;

    i = 0;
    while (i < MAX_ITER)
    {
        double temp = z.real;
        z.real = z.real * z.real - z.imag * z.imag + c.real;
        z.imag = 2 * temp * z.imag + c.imag;

        if (z.real * z.real + z.imag * z.imag >= 4)
            return i;
        i++;
    }
    return MAX_ITER;
}

int get_color(int iterations)
{
    if (iterations == MAX_ITER)
        return 0x000000;

    int r = iterations % 8 * 32;
    int g = iterations % 16 * 16;
    int b = iterations % 32 * 8;

    return (r << 16) | (g << 8) | b;
}

int main(void)
{
    void *mlx;
    void *win;

    mlx = mlx_init();
    win = mlx_new_window(mlx, WIDTH, HEIGHT, "Mandelbrot");

    int y = 0;
    while (y < HEIGHT)
    {
        int x = 0;
		while (x < WIDTH)
		{
			t_complex	c;
			c.real = (x - WIDTH / 2.0) * 4.0 / WIDTH;
			c.imag = (y - HEIGHT / 2.0) * 4.0 / HEIGHT;
			int iterations = mandelbrot(c);
			int color = get_color(iterations);
			mlx_pixel_put(mlx, win, x, y, color);
            x++;
        }
        y++;
    }

    mlx_loop(mlx);
    return 0;
}
