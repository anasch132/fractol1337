/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 21:51:10 by achatoua          #+#    #+#             */
/*   Updated: 2019/08/02 21:51:11 by achatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void ft_light(int i, void *param)
{
    t_image *img;

    img = (t_image *)param;
    if (i == 126 )
    ft_putcolor_plus(param);
    else if (i == 125)
    ft_putcolor_moin(param);
    else if (i == 123)
    ft_color_pallette_moin(param);
    else if (i == 124)
    ft_color_pallette_plus(param);

}

void ft_putcolor_plus(void *param)
{
    t_image *img;
    img = (t_image *)param;

    ft_clear(param);
    if (img->f <= 20)
    img->f += 0.12;
    if (img-> i == 1)
    julia2(param);
    else if (img-> i == 2)
    mandelbrot2(param);
    else if (img-> i == 3)
    burning_ship(param);
    else if (img-> i == 4)
    mandelbrot4(param);
    else if (img-> i == 5)
    mandelbrot3(param);
}
void ft_putcolor_moin(void *param)
{
    t_image *img;
    img = (t_image *)param;

    ft_clear(param);
    if (img->f >= -20)
    img->f -= 0.42;
    if (img-> i == 1)
    julia2(param);
    else if (img-> i == 2)
    mandelbrot2(param);
    else if (img-> i == 3)
    burning_ship(param);
    else if (img-> i == 4)
    mandelbrot4(param);
    else if (img-> i == 5)
    mandelbrot3(param);
}
 void ft_color_pallette_plus(void *param)
 {
     t_image *img;
    img = (t_image *)param;

    ft_clear(param);
    if (img->color >= 250)
    img->color += 4;
    img->color_change += 1.2;
    printf("%d\n", img->color);
    if (img-> i == 1)
    julia2(param);
    else if (img-> i == 2)
    mandelbrot2(param);
    else if (img-> i == 3)
    burning_ship(param);
    else if (img-> i == 4)
    mandelbrot4(param);
    else if (img-> i == 5)
    mandelbrot3(param);
 }

 void ft_color_pallette_moin(void *param)
 {
     t_image *img;
    img = (t_image *)param;

    ft_clear(param);
    if (img->color >= 80)
    img->color -= 4;
    img->color_change -= 1.2;
    printf("%d\n", img->color);
    if (img-> i == 1)
    julia2(param);
    else if (img-> i == 2)
    mandelbrot2(param);
    else if (img-> i == 3)
    burning_ship(param);
    else if (img-> i == 4)
    mandelbrot4(param);
    else if (img-> i == 5)
    mandelbrot3(param);
 }
