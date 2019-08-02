/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 20:12:05 by achatoua          #+#    #+#             */
/*   Updated: 2019/07/31 22:39:31 by achatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_ozoom(void *param, int button, t_complex l, void (*f)(void *))
{
	t_image *img;

	img = (t_image *)param;
	if (button == 4)
		ft_zoom(&(img->pmin), &img->pmax, l, 1.2);
	else if (button == 5)
		ft_dezoom(&img->pmin, &img->pmax, l, 0.8998);
	ft_clear(img);
	f(img);
}

void	ft_color(void *param, void (*f)(void *))
{
	t_image *img;

	img = (t_image *)param;
	if (img->func == 1)
	{
		img->fun = ft_hexcolor;
		img->func = 2;
		
	}
	else
	{
		img->fun = hexcolor;
		img->func = 1;
	}
	ft_clear(img);
	f(img);
}

void	ft_mandelbrot3_change(void *param)
{
	t_image *img;

	img = (t_image *)param;
	img->i = 5;
	ft_clear(param);
	mandelbrot3(param);
}

void	ft_julia_change(void *param)
{
	t_image *img;

	img = (t_image *)param;
	img->i = 4;
	ft_clear(param);
	mandelbrot4(param);
}

void	ft_burning_ship_change(void *param)
{
	t_image *img;

	img = (t_image *)param;
	img->i = 3;
	ft_clear(param);
	burning_ship(param);
}
