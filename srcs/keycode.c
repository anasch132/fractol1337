/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 21:14:15 by achatoua          #+#    #+#             */
/*   Updated: 2019/07/20 21:20:25 by achatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"
#include <time.h>
int ft_close(void *param)
{
	(void)param;
	exit(0);
}
int key_press(int keycode, void *param)
{	
	t_image *img = (t_image *)param;

	if(keycode == 53)
		exit(0);
	if(keycode == 11)
			img->fix = !img->fix;
	if(keycode == 82)
			img->co_fix = !img->co_fix;
	if (keycode == 69)
		ft_iter_plus(param);
	if (keycode == 126 || keycode == 125)
	ft_light(keycode, param);
	if (keycode == 78)
		ft_iter_moin(param);
	if(keycode == 8)
		ft_change_color(param);	
	if (keycode == 83)
		ft_julia2_change(param);
	if (keycode == 84)
		ft_mandelbrot2_change(param);
	if (keycode == 85)
		ft_burning_ship_change(param);
	if (keycode == 86)
		ft_julia_change(param);
	if (keycode == 87)
	ft_mandelbrot3_change(param);
		return 0;
}
int ft_mouse_press(int button, int x, int y, void *param)
{
	t_image *img = (t_image *)param;
	t_complex m;

	m.x = x;
	m.y = y;
	if (img->i == 1)
	ft_ozoom(param, button, m, julia2);
	else if (img->i == 2)
	ft_ozoom(param, button, m, mandelbrot2);
	else if (img->i == 3)
	ft_ozoom(param, button, m, burning_ship);
	else if (img->i == 4)
	ft_ozoom(param, button, m, mandelbrot4);
	else if (img->i == 5)
	ft_ozoom(param, button, m, mandelbrot3);

return 0;
}

void ft_iter_plus(void *param)
{
	t_image *img = (t_image *)param;
	if(img->max < 350)
			img->max += 3;
		if ( img->i == 1)
			julia2(param);
		else if (img->i == 2)
			mandelbrot2(param);
		else if (img->i == 3)
			burning_ship(param);
		else if (img->i == 4)
			mandelbrot4(param);
		else if (img->i == 5)
			mandelbrot3(param);	
}

