/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 19:04:04 by achatoua          #+#    #+#             */
/*   Updated: 2019/07/21 19:04:06 by achatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void mandelbrot4(void *param)
{   
    t_image *img = (t_image *) param;

    
    img->vect.x = -1;
    img->vect.y = -1;

    while (++img->vect.y < height)
    {
        img->vect.x = -1;
        while ( ++img->vect.x < width)
        {
            t_complex z = (t_complex){0.0, 0.0};
            t_complex c = (t_complex){0.0, 0.0};
            ft_map(&z, img->pmin, img->pmax, img->vect);
           c = z;
            img->map.iter = 0;
            while(z.x * z.x + z.y * z.y < 4 && (img->map.iter += 2) < img->max)
            {
                img->map.x_new = pow(z.x,3) - 3*z.x*pow(z.y, 2) + c.x;
                z.y = 3 * pow(z.x, 2) * z.y - pow(z.y, 3) + c.y;
                z.x = img->map.x_new ;
            }
            if (img->map.iter >= img->max )
            img->mlx_data[(int)img->vect.y * width + (int)img->vect.x] =0x000;
            else
            img->mlx_data[(int)img->vect.y * width + (int)img->vect.x] = img->fun(img->map.iter , img->f);
        } 
    }
    mlx_put_image_to_window(img->mlx_ptr	, img->win_ptr, img->img_ptr , 0,0);
    mlx_string_put(img->mlx_ptr,img->win_ptr, 50, 50, 0xfff, "TEST TEST");

}

void julia2(void *param)
{
    t_image *img = (t_image *) param;

    img->vect.x = -1;
    img->vect.y = -1;
    while (++img->vect.y < height)
    {
        img->map.x = -1;
        while ( ++img->vect.x < width)
        {
            t_complex z = (t_complex){0.0, 0.0};
            t_complex c = (t_complex){0.0, 0.0};

            ft_map(&z, img->pmin, img->pmax, img->vect);
           // c = z;
             c.x = img->map.c_re;
            c.y = img->map.c_im;
            img->map.iter = 0;
            while(z.x * z.x + z.y * z.y < 4 && (img->map.iter += 2) < img->max)
            {
                img->map.x_new = pow(z.x , 2) - z.y * z.y + c.x;
                z.y = 2 * z.x *z.y + c.y;
                z.x = img->map.x_new ;
            }
            if (img->map.iter >= img->max )
            img->mlx_data[(int)img->vect.y * width + (int)img->vect.x] = img->fun(img->map.iter, img->f);
            else
                img->mlx_data[(int)img->vect.y * width + (int)img->vect.x] = img->fun(img->map.iter , img->f);
        } 
        }
    mlx_put_image_to_window(img->mlx_ptr	, img->win_ptr, img->img_ptr , 0,0);
    mlx_string_put(img->mlx_ptr,img->win_ptr, 50, 50, 0xfff, "TEST TEST");
}