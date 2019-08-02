/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 14:26:31 by achatoua          #+#    #+#             */
/*   Updated: 2019/07/29 14:26:32 by achatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

void ft_iter_moin(void * param)
{
	t_image *img = (t_image *)param;
		
		if(img->max > 0)
			img->max -= 3;
		if ( img->i == 1)
			julia2(param);
		else if (img->i == 2)
			mandelbrot2(param);
		else if (img->i == 3)
			burning_ship(param);
}
int ft_change_color(void *param)
{
	t_image *img = (t_image *)param;
	if ( img->i == 1)
	ft_color(param, julia2);
	else if (img->i == 2)
	ft_color(param, mandelbrot2);
	else if (img->i == 3)
	ft_color(param, burning_ship);
	else if (img->i == 4)
	ft_color(param, mandelbrot4);
	else if (img->i == 5)
	ft_color(param, mandelbrot3);
	return 0;
}

int ft_space_effect(void *param)
{
		t_image *img = (t_image *)param;
		if (img->co_fix == 0)
		{
			if ( img->i == 1)
		{
			img->f *= 1.012;
			julia2(param); }
		if ( img->i == 2)
		{
			img->f *= 1.012;
			mandelbrot2(param);
		}
		if ( img->i == 3)
		{
			img->f *= 1.012;
			burning_ship(param);
		}
		
		}
		return 0;

}