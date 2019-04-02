/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 15:51:06 by lbonnete          #+#    #+#             */
/*   Updated: 2019/04/02 17:01:37 by lbonnete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int		boucle_mandelbrot_2(t_complex z, t_complex c, t_info *info)
{
	t_complex	t;
	int			n;

	n = 0;
	while (n < info->acc)
	{
		t.a = z.a * z.a - z.b * z.b;
		t.b = info->mand * 2 * z.a * z.b;
		z.a = c.a + t.a;
		z.b = c.b + t.b;
		if (z.a * z.a + z.b * z.b > 4)
			break ;
		n++;
	}
	return (n);
}

void	*mandelbrot(void *thrds)
{
	t_info	info;
	t_thrd	thrd;
	double	x;
	double	y;

	thrd = *(t_thrd *)thrds;
	info = *(thrd.info);
	x = (info.iw * thrd.id) / info.nb_thrd - 1;
	while (++x < ((info.iw * (thrd.id + 1) / info.nb_thrd)))
	{
		y = -1;
		while (++y < info.ih)
		{
			thrd.z.a = (info.xup - info.xdown) / 2 - info.movex;
			thrd.z.b = (info.yup - info.ydown) / 2 - info.movey;
			thrd.c.a = ((x / info.iw) * (info.xup - info.xdown)) - thrd.z.a;
			thrd.c.b = ((y / info.ih) * (info.yup - info.ydown)) - thrd.z.b;
			thrd.z.a = 0;
			thrd.z.b = 0;
			thrd.n = boucle_mandelbrot_2(thrd.z, thrd.c, &info);
			if (thrd.n != info.acc)
				color_it(x, y, &info, thrd.n);
		}
	}
	pthread_exit(NULL);
}
