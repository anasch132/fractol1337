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

    if (i == 126)
    {
        ft_clear(param);
        img->f++;
    }
    else 
    {
        ft_clear(param);
        img->f--;
    }
}