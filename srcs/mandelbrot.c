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
    t_image *img = (t_image *)param;

 img->vect.y = -1;
 img->vect.x = -1;

    while (++img->vect.y < height)
    {
     img->vect.x = -1;
     while (++img->vect.x < width)
     {
         t_complex z = (t_complex){0.0, 0.0};
         t_complex c = (t_complex){0.0, 0.0};
         ft_map(&z, img->pmin, img->pmax, img->vect);
            c = z;
         img->map.iter = 0;
         while (z.x * z.x + z.y * z.y< 4 && img->map.iter++ < img->max)
         {
            img->map.x_new = z.x * z.x - z.y * z.y + c.x;
            z.y = fabs(2*z.x*z.y) + c.y;
        	z.x = fabs(img->map.x_new);
            
         }
         if (img->map.iter <= img->max)
            img->mlx_data[(int)img->vect.y * width + (int)img->vect.x] = img->fun(img->map.iter, img->f);
         else
            img->mlx_data[(int)img->vect.y * width + (int)img->vect.x] = img->fun(img->map.iter , img->f);
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
         t_complex z = (t_complex){0.0, 0.0};
         t_complex c = (t_complex){0.0, 0.0};
         ft_map(&z, img->pmin, img->pmax, img->vect);
         c = z;
         img->map.iter = 0;
         while (z.x * z.x + z.y * z.y< 4 && img->map.iter++ < img->max)
         {
            img->map.x_new = pow(z.x ,5) -10 * pow(z.x, 3) * pow(z.y, 2) + 5 * z.x * pow(z.y , 4)+ c.x;
            z.y = 5* pow(z.x , 4) * z.y -10 *pow(z.x, 2) * pow(z.y, 3) + pow(z.y, 5) + c.y;
        	z.x = img->map.x_new;

         }
          if (img->map.iter <= img->max)
            img->mlx_data[(int)img->vect.y * width + (int)img->vect.x] = img->fun(img->map.iter, img->f);
        else
           img->mlx_data[(int)img->vect.y * width + (int)img->vect.x] = img->fun(img->map.iter , img->f);
     }
    }
    mlx_put_image_to_window(img->mlx_ptr	, img->win_ptr, img->img_ptr , 0,0);
    mlx_string_put(img->mlx_ptr,img->win_ptr, 50, 50, 0xfff, "TEST TEST");
}

void mandelbrot2(void *param)
{
    t_image *img = (t_image *)param;

 img->vect.y = -1;
 img->vect.x = -1;

    while (++img->vect.y < height)
    {
     img->vect.x = -1;
     while (++img->vect.x < width)
     {
         t_complex z = (t_complex){0.0, 0.0};
         t_complex c = (t_complex){0.0, 0.0};
         img->vect.x = (double)img->map.x;
         img->vect.y = (double)img->map.y;
         ft_map(&z, img->pmin, img->pmax, img->vect);
         c = z;
         img->map.iter = 0;
         while (z.x * z.x + z.y * z.y< 4 && img->map.iter++ < img->max)
         {
            img->map.x_new = z.x*z.x-z.y*z.y + c.x;
            z.y = 2*z.x*z.y + c.y;
        	z.x = img->map.x_new;
            
         }
         if (img->map.iter <= img->max)
            img->mlx_data [(int)img->vect.y * width + (int)img->vect.x] = img->fun(img->map.iter, img->f);
         else
            img->mlx_data [(int)img->vect.y * width + (int)img->vect.x] = img->fun(img->map.iter , img->f);
         
     }
    }
    mlx_put_image_to_window(img->mlx_ptr	, img->win_ptr, img->img_ptr , 0,0);
    mlx_string_put(img->mlx_ptr,img->win_ptr, 50, 50, 0xfff, "TEST TEST");
}