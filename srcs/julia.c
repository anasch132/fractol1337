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
        ft_calcul(img);
            img->map.iter = 0;
            while(img->re.x * img->re.x + img->re.y * img->re.y < 4 && (img->map.iter += 2) < img->max)
            {
                img->map.x_new = pow(img->re.x,3) - 3*img->re.x*pow(img->re.y, 2) + img->im.x;
                img->re.y = 3 * pow(img->re.x, 2) * img->re.y - pow(img->re.y, 3) + img->im.y;
                img->re.x = img->map.x_new ;
            }
            if (img->map.iter >= img->max )
            img->mlx_data[(int)img->vect.y * width + (int)img->vect.x] = img->fun(img->map.iter , img->f, img->color, img->color_change);
            else
            img->mlx_data[(int)img->vect.y * width + (int)img->vect.x] = img->fun(img->map.iter , img->f, img->color, img->color_change);
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
        img->vect.x = -1;
        while ( ++img->vect.x < width)
        {
            ft_calcul(img);
            img->im.x = img->map.c_re;
            img->im.y = img->map.c_im;
            img->map.iter = 0;
            while(img->re.x * img->re.x + img->re.y * img->re.y < 4 && (img->map.iter += 2) < img->max)
            {
                img->map.x_new = pow(img->re.x , 2) - img->re.y * img->re.y + img->im.x;
                img->re.y = 2 * img->re.x *img->re.y + img->im.y;
                img->re.x = img->map.x_new ;
            }
            if (img->map.iter >= img->max )
            img->mlx_data[(int)img->vect.y * width + (int)img->vect.x] = img->fun(img->map.iter , img->f, img->color, img->color_change);
            else
                img->mlx_data[(int)img->vect.y * width + (int)img->vect.x] = img->fun(img->map.iter , img->f, img->color, img->color_change);
        } 
        }
    mlx_put_image_to_window(img->mlx_ptr	, img->win_ptr, img->img_ptr , 0,0);
    mlx_string_put(img->mlx_ptr,img->win_ptr, 50, 50, 0xfff, "TEST TEST");
}