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

int		hexcolor(int i, double freqe)
{
	int	red;
	int	green;
	int	blue;

	red = cos(freqe * i + 3) * 127 + 128;
	green = cos(freqe * i + 5) * 127 + 128;
	blue = cos(freqe * i + 7) * 127 + 128;
	return (red << 16 | green << 8 | blue);
}

int		ft_hexcolor(int i, double freqe)
{
	int	red;
	int	green;
	int	blue;

	red = cos(freqe * i + 1) * 127 + 128;
	green = cos(freqe * i + 2) * 127 + 128;
	blue = cos(freqe * i + 3) * 127 + 128;
	return (red << 16 | green << 8 | blue);
}
int ft_hexcolor2(int i, double freqe)
{
	int	red;
	int	green;
	int	blue;

	red = (freqe * i + 1) * 127 + 128;
	green = (freqe * i + 2) * 127 + 128;
	blue = (freqe * i + 3) * 127 + 128;
	return (red << 16 | green << 8 | blue);

}

 int  ft_hexcolor3( int i, double freqe)
{
	int a;
	int g;
	int b;
	int r;

	a = ((255 * (i +1))/20) / 60;
	r = 250 * (i + freqe)  / 20;
	g = 250 * (i + freqe)  / 20;
	b = 250 * (i + freqe)  / 20;
    return ((((a > 0xff) ? 0xff : a) << 24) |
        (((r > 0xff) ? 0xff : r) << 16) |
        (((g > 0xff) ? 0xff : g) << 8) |
        ((b > 0xff) ? 0xff : b));
}

//  int  ft_hexcolor3( int a,  int r,
//                  int g,  int b)
// {
//     return ((((a > 0xff) ? 0xff : a) << 24) |
//         (((r > 0xff) ? 0xff : r) << 16) |
//         (((g > 0xff) ? 0xff : g) << 8) |
//         ((b > 0xff) ? 0xff : b));
// }

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
