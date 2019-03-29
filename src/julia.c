/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 15:37:49 by lbonnete          #+#    #+#             */
/*   Updated: 2019/03/29 14:17:11 by lbonnete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int		boucle_julia_2(t_complex z, t_complex c, t_info *info)
{
	t_complex	t;
	int			n;

	n = 0;
	while (n < info->acc)
	{
		t.a = z.a * z.a - z.b * z.b;
		t.b = 2 * z.a * z.b;
		z.a = c.a + t.a;
		z.b = c.b + t.b;
		if (z.a * z.a + z.b * z.b > 4)
			break ;
		n++;
	}
	return (n);
}

void	*julia(void *thrds)
{
	t_info	info;
	t_thrd	thrd;
	float	x;
	float	y;

	thrd = *(t_thrd *)thrds;
	info = *(thrd.info);
	x = (info.iw * thrd.id) / info.nb_thrd - 1;
	while (++x < ((info.iw * (thrd.id + 1) / info.nb_thrd)))
	{
		y = -1;
		while (++y < info.ih)
		{
			thrd.c.a = (info.xup - info.xdown) / 2 - info.movex;
			thrd.c.b = (info.yup - info.ydown) / 2 - info.movey;
			thrd.z.a = ((x / info.iw) * (info.xup - info.xdown)) - thrd.c.a;
			thrd.z.b = ((y / info.ih) * (info.yup - info.ydown)) - thrd.c.b;
			thrd.c.a = info.julia.a;
			thrd.c.b = info.julia.b;
			thrd.n = boucle_julia_2(thrd.z, thrd.c, &info);
			if (thrd.n != info.acc)
				color_it(x, y, &info, thrd.n);
		}
	}
	pthread_exit(NULL);
}
