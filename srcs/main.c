/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 16:04:20 by achatoua          #+#    #+#             */
/*   Updated: 2019/07/20 21:30:33 by achatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int mouse_move(int x, int y, void *param)
{
	t_image *img;

	img = (t_image*)param;
	if (!img->fix && img->i == 1)
	{
	img->map.c_re = 1.0*x / 2500.0;
	img->map.c_im = 1.0*y / 2500.0;
	if (img->i == 1)
	julia2(param);
	else if (img->i ==	 4)
	mandelbrot4(param);
	}
	return 0;
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{	
		if (argv[1][0] == '1')
			ft_parsing(julia2, 1);
		else if (argv[1][0] == '2')
			ft_parsing(mandelbrot2, 2);
		else if (argv[1][0] == '3')
			ft_parsing(burning_ship, 3);
		else if (argv[1][0] == '4')
			ft_parsing(mandelbrot4, 4);
		else if (argv[1][0] == '5')
			ft_parsing(mandelbrot3, 5);
	}
	else 
		printf("please put number");
	return 0;
}

void ft_parsing(void (*fun)(t_image *img), int b)
{
	t_image img;
	ft_lance(&img);
	init(&img);
	fun(&img);
	img.i = b;
	mlx_hook( img.win_ptr, 17,0, &ft_close, NULL);
	mlx_hook( img.win_ptr, 2,0, &key_press, &img);
	mlx_hook(img.win_ptr,4, 0, &ft_mouse_press, &img);
	mlx_hook(img.win_ptr, 6, 0, &mouse_move,  &img);
	mlx_loop_hook(img.mlx_ptr, ft_space_effect , &img);
	mlx_loop(img.mlx_ptr);
}

int		ft_zoom(t_complex *pmin,t_complex *pmax, t_complex s, double fact)
{
	s.x = ((pmax->x - pmin->x) / (double)width ) *  s.x + pmin->x;
	s.y = ((pmax->y - pmin->y) / (double)height )*  s.y  + pmin->y;
	
	pmin->x = ft_interpolate(pmin->x, s.x, fact);
	pmax->x = ft_interpolate(pmax->x, s.x, fact);
	pmin->y = ft_interpolate(pmin->y, s.y, fact);
	pmax->y = ft_interpolate(pmax->y, s.y, fact);
	return 0;
}
void	ft_dezoom(t_complex *pmin,t_complex *pmax, t_complex s, double fact)
{
	s.x = ((pmax->x - pmin->x) / (double)width ) * s.x + pmin->x;
	s.y = ((pmax->y - pmin->y) / (double)height )* s.y  + pmin->y;
	pmin->x = ft_interpolate(pmin->x, s.x, fact);
	pmax->x = ft_interpolate(pmax->x, s.x,fact);
	pmin->y = ft_interpolate(pmin->y, s.y,fact);
	pmax->y =  ft_interpolate(pmax->y, s.y,fact);
}