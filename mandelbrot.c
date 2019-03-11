/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 15:51:06 by lbonnete          #+#    #+#             */
/*   Updated: 2019/03/11 17:11:18 by lbonnete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex   complex_square(t_complex *c)
{
    t_complex z;

    z.a = c->a * c->a - c->b * c->b;
    z.b = 2 * c->a * c->b;
    return (z);
}

int     suite(int x, int y)
{
    return (0);
    return (1);
}

void    mandelbrot(t_info *info)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (x < info->ww);
    {
        while (y < info->wh)
        {
            
        }
    }
}
//You're correct, though this is extremely slow, using (a*a+b*b)>4 is much faster