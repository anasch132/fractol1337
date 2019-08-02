/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 14:21:41 by achatoua          #+#    #+#             */
/*   Updated: 2019/07/22 14:21:44 by achatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void burning_ship(void *param)
{
    t_image *img;
    img = (t_image *)param;

 img->vect.y = -1;
    while (++img->vect.y < height)
    {
     img->vect.x = -1;
     while (++img->vect.x < width)
     {
         ft_calcul(img);
         img->map.iter = 0;
         while (img->re.x * img->re.x + img->re.y * img->re.y< 4 && img->map.iter++ < img->max)
         {
            img->map.x_new = img->re.x * img->re.x - img->re.y * img->re.y + img->im.x;
            img->re.y = fabs(2*img->re.x*img->re.y) + img->im.y;
        	img->re.x = fabs(img->map.x_new);
            
         }
         if (img->map.iter <= img->max)
            img->mlx_data[(int)img->vect.y * width + (int)img->vect.x] = img->fun(img->map.iter , img->f, img->color, img->color_change);
         else
            img->mlx_data[(int)img->vect.y * width + (int)img->vect.x] = img->fun(img->map.iter , img->f, img->color, img->color_change);
     }
    }
    mlx_put_image_to_window(img->mlx_ptr	, img->win_ptr, img->img_ptr , 0,0);
    mlx_string_put(img->mlx_ptr,img->win_ptr, 50, 50, 0xfff, "TEST TEST");
}


void mandelbrot3(void *param)
{
    t_image *img = (t_image *)param;

 img->vect.y = -1;
 img->vect.x = -1;


    while (++img->vect.y < height)
    {
     img->vect.x = -1;
     while (++img->vect.x < width)
     {
         ft_calcul(img);
         img->map.iter = 0;
         while (img->re.x * img->re.x + img->re.y * img->re.y< 4 && img->map.iter++ < img->max)
         {
            img->map.x_new = pow(img->re.x ,5) -10 * pow(img->re.x, 3) * pow(img->re.y, 2) + 5 * img->re.x * pow(img->re.y , 4)+ img->im.x;
            img->re.y = 5* pow(img->re.x , 4) * img->re.y -10 *pow(img->re.x, 2) * pow(img->re.y, 3) + pow(img->re.y, 5) + img->im.y;
        	img->re.x = img->map.x_new;

         }
          if (img->map.iter <= img->max)
            img->mlx_data[(int)img->vect.y * width + (int)img->vect.x] = img->fun(img->map.iter , img->f, img->color, img->color_change);
        else
           img->mlx_data[(int)img->vect.y * width + (int)img->vect.x] = img->fun(img->map.iter , img->f, img->color, img->color_change);
     }
    }
    mlx_put_image_to_window(img->mlx_ptr	, img->win_ptr, img->img_ptr , 0,0);
    mlx_string_put(img->mlx_ptr,img->win_ptr, 50, 50, 0xfff, "TEST TEST");
}

void mandelbrot2(void *param)
{
    t_image *img = (t_image *)param;

 img->vect.y = -1;
    while (++img->vect.y < height)
    {
     img->vect.x = -1;
     while (++img->vect.x < width)
     {
         ft_calcul(img);
         while (img->re.x * img->re.x + img->re.y * img->re.y< 4 && img->map.iter++ < img->max)
         {
           img->map.x_new = img->re.x*img->re.x-img->re.y*img->re.y + img->im.x;
         img->re.y = 2*img->re.x*img->re.y + img->im.y;
        	img->re.x = img->map.x_new;
      
         }
         if (img->map.iter <= img->max)
            img->mlx_data [(int)img->vect.y * width + (int)img->vect.x] = img->fun(img->map.iter , img->f , img->color, img->color_change);
         else
            img->mlx_data [(int)img->vect.y * width + (int)img->vect.x] = img->fun(img->map.iter , img->f , img->color, img->color_change);
         
     }
    }
    mlx_put_image_to_window(img->mlx_ptr	, img->win_ptr, img->img_ptr , 0,0);
    mlx_string_put(img->mlx_ptr,img->win_ptr, 50, 50, 0xfff, "TEST TEST");
}

void ft_calcul(t_image *img)
{
         img->re.x = 0.0;
         img->re.y = 0.0;
         img->im.x = 0.0;
         img->im.y = 0.0;
         ft_map(&img->re, img->pmin, img->pmax, img->vect);
         img->im = img->re;
         img->map.iter = 0;

}