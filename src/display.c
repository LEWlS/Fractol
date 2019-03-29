/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 16:19:50 by lbonnete          #+#    #+#             */
/*   Updated: 2019/03/29 14:14:11 by lbonnete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_multithreading(t_info *info)
{
	t_mthrds	*mthrds;
	int			i;

	mthrds = &info->mthrds;
	i = -1;
	while (++i < info->nb_thrd)
	{
		mthrds->thrd[i].id = i;
		mthrds->thrd[i].info = info;
		pthread_create(&mthrds->threads[i], NULL, \
		choose(info), &mthrds->thrd[i]);
	}
	i = -1;
	while (++i < info->nb_thrd)
	{
		pthread_join(mthrds->threads[i], NULL);
	}
}

void	*choose(t_info *info)
{
	if (info->proj == 1)
		return (mandelbrot);
	if (info->proj == 2)
		return (mandelbrot_3);
	if (info->proj == 3)
		return (julia);
	if (info->proj == 4)
		return (julia_3);
	return (0);
}

void	drawer(t_info *info)
{
	int bpp;
	int size_l;
	int endian;

	if (info->hud)
		put_hud(info);
	bpp = 32;
	size_l = info->iw * 4;
	endian = 0;
	info->im = mlx_new_image(info->pt, info->iw, info->ih);
	info->addr = mlx_get_data_addr(info->im, &bpp, &size_l, &endian);
	ft_multithreading(info);
	mlx_put_image_to_window(info->pt, info->wn, info->im, info->ix, info->iy);
	mlx_destroy_image(info->pt, info->im);
}
