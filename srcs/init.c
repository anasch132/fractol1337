/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 19:12:56 by achatoua          #+#    #+#             */
/*   Updated: 2019/08/01 12:15:57 by achatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		init(t_image *img)
{
	img->img_ptr = mlx_new_image(img->mlx_ptr, width, height);
	img->mlx_data = (int *)mlx_get_data_addr(img->img_ptr, &img->bpp,
	&img->line_len, &img->end);
	return (0);
}

void	ft_clear(void *param)
{
	t_image *img;

	img = (t_image *)param;
	mlx_destroy_image(img->mlx_ptr, img->img_ptr);
	mlx_clear_window(img->mlx_ptr, img->win_ptr);
	init(img);
}

void	ft_map(t_complex *z, t_complex pmin, t_complex pmax, t_complex mp)
{
	z->x = ((pmax.x - pmin.x) / (double)width) * mp.x + pmin.x;
	z->y = ((pmax.y - pmin.y) / (double)height) * mp.y + pmin.y;
}

double	ft_interpolate(double end, double x, double factor)
{
	return ((end - x) * factor + x);
}

void	ft_lance(t_image *img)
{
	img->mlx_ptr = mlx_init();
	img->fix = 1;
	img->map.x_new = 0;
	img->max = 10;
	img->map.c_re = 5;
	img->map.c_im = -5;
	img->map.count = 0;
	img->pmin.x = -2.9;
	img->color = 110;
	img->color_change = 15.5;
	img->pmin.y = -1.7;
	img->pmax.x = 1.6;
	img->co_fix = 1;
	img->space = 1;
	img->pmax.y = 1.0;
	img->f = 0.08;
	img->fun = hexcolor;
	img->func = 1;
	img->pmin.x = (0 - width / 2.0) * 4.0 / width;
	img->pmin.y = (0 - height / 2.0) * 4.0 / width;
	img->pmax.x = (width - width / 2.0) * 4.0 / width;
	img->pmax.y = (height - height / 2.0) * 4.0 / width;
	img->win_ptr = mlx_new_window(img->mlx_ptr, width, height, "fractol");
}
