/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 21:14:15 by achatoua          #+#    #+#             */
/*   Updated: 2019/07/29 14:47:12 by achatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx.h"
#include <time.h>
#include <stdlib.h>
# include <stdio.h>
#include <math.h>
#include <complex.h>
# include <pthread.h>
#include <unistd.h>
# define width 1000
# define height 1000



typedef struct s_complex
{
    double x;
    double y;
}               t_complex;

typedef struct s_vec
{
    int x;
    int y;
}               t_vec;

typedef struct map
{
	int		x;
	double x_new;
	int		y;
	int		row;
	double	max;
	double	min;
	int		col;
	double	c_re;
	int		count;
	double	c_im;
	double	factor;
	int		iter;
}					s_map;
typedef struct s_image
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	double 	f;
	int		*mlx_data;
	int		bpp;
	int		color;
	double color_change;
	int		fix;
	int		co_fix;
	int		line_len;
	int		end;
	int 	max;
	int		func;
	int		(*fun)(int i, double freqe, int color, double col_chang);
	t_complex  pmax;
	t_complex pmin;
	s_map   map;
	t_complex vect;
	t_complex re;
	t_complex im;
	int 	space;
	int 	i;

}			t_image;


int ft_close(void *param);
int key_press(int keycode, void *param);
void ft_calcul(t_image *img);
void mandelbrot4(void *param);
int init();
void ft_ozoom(void *param, int button, t_complex l, void (*f)(void *));
void ft_parsing();
int ft_space_effect(void *param);
int ft_change_color(void *param);
void ft_color_pallette_moin(void *param);
void ft_color_pallette_plus(void *param);
int ft_hexcolor2(int i, double freqe, int color, double col_chang);
void ft_iter_moin(void * param);
void ft_iter_plus(void *param);
int ft_hexcolor3(int i, double freqe, int color, double col_chang);
void ft_putcolor_plus(void *param);
void ft_putcolor_moin(void *param);
void julia2(void *param);
void mandelbrot3(void *param);
double	ft_interpolate(double end, double x, double factor);
void ft_lance(t_image *img);
void ft_dezoom(t_complex *pmin,t_complex *pmax, t_complex s, double fact);
void ft_random();
int ft_mouse_press(int button, int x, int y, void *param);
void  ft_map(t_complex *z, t_complex pmin, t_complex pmax, t_complex mp);
int ft_hexcolor(int i , double freqe, int color, double col_chang);
void mandelbrot2(void *param);
void ft_light(int i, void *param);
void ft_julia2_change(void *param);
void ft_julia_change(void *param);
void ft_mandelbrot3_change(void *param);
void ft_map_changer(int i, void *param);
void ft_mandelbrot2_change(void *param);
void ft_burning_ship_change(void *param);
int ft_change(void* param);
void ft_color(void *param, void (*f)(void *));
int hexcolor(int i , double freqe, int color, double col_chang);
int ft_zoom(t_complex *pmin,t_complex *pmax,t_complex s, double fact);
void ft_clear(void *param);
void burning_ship(void *param);
#endif
