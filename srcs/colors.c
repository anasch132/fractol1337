/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:17:02 by achatoua          #+#    #+#             */
/*   Updated: 2019/07/31 22:34:19 by achatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		hexcolor(int i, double freqe, int color, double col_chang)
{
	int	red;
	int	green;
	int	blue;

	red = cos(freqe * i + 3 + color - color) * 127 + 128 + col_chang;
	green = cos(freqe * i + 5 + color - color) * 127 + 128 + col_chang;
	blue = cos(freqe * i + 7 + color - color) * 127 + 128 + col_chang;
	return (red << 16 | green << 8 | blue);
}

int		ft_hexcolor(int i, double freqe, int color, double col_chang)
{
	int	red;
	int	green;
	int	blue;

	red = cos(freqe * i + 1 + color - color) * 127 + 128 + col_chang;
	green = cos(freqe * i + 2 + color -color)  * 127 + 128 + col_chang;
	blue = cos(freqe * i + 3 + color - color) * 127 + 128 + col_chang;
	return (red << 16 | green << 8 | blue);
}
int ft_hexcolor2(int i, double freqe, int color, double col_chang)
{
	int	red;
	int	green;
	int	blue;

	red = (freqe * i + 1 + color - color) * 127 + 128 + col_chang;
	green = (freqe * i + 2 + color - color) * 127 + 128 + col_chang;
	blue = (freqe * i + 3 + color - color) * 127 + 128 + col_chang;
	return (red << 16 | green << 8 | blue);

}

 int  ft_hexcolor3( int i, double freqe, int color , double col_chang)
{
	int a;
	int g;
	int b;
	int r;
	

	a = ((color * (i +1))/20) /80;
	r = (color + 12) * (i + freqe)  / col_chang;
	g = (color + 95)* (i + freqe)  / col_chang;
	b = (color + 118)* (i + freqe)  / col_chang;
    return ((((a > 0xff) ? 0xff : a) << 24) |
        (((r > 0xff) ? 0xff : r) << 16) |
        (((g > 0xff) ? 0xff : g) << 8) |
        ((b > 0xff) ? 0xff : b));
}

void	ft_julia2_change(void *param)
{
	t_image *img;

	img = (t_image *)param;
	img->i = 1;
	ft_clear(param);
	julia2(param);
}

void	ft_mandelbrot2_change(void *param)
{
	t_image *img;

	img = (t_image *)param;
	img->i = 2;
	ft_clear(param);
	mandelbrot2(param);
}
