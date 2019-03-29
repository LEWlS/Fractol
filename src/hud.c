/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 15:42:13 by lbonnete          #+#    #+#             */
/*   Updated: 2019/03/29 13:33:01 by lbonnete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	put_top_info(t_info *info)
{
	char	buffer[50];
	int		c;

	c = ft_rgb(220, 220, 220);
	put_bar_1(info, 15, 35);
	mlx_string_put(info->pt, info->wn, 1220, 15, c, "Fractal");
	mlx_string_put(info->pt, info->wn, 1290, 15, c, " :");
	if ((info->proj == 1 || info->proj == 2) && info->mand == 1)
		mlx_string_put(info->pt, info->wn, 1320, 15, c, "Mandelbrot");
	else if ((info->proj == 1 || info->proj == 2) && info->mand == -1)
		mlx_string_put(info->pt, info->wn, 1320, 15, c, "Mandelbrat");
	else if (info->proj == 3 || info->proj == 4)
		mlx_string_put(info->pt, info->wn, 1320, 15, c, "Julia");
	put_bar_2(info, 226, 246);
	sprintf(buffer, "%i", info->acc);
	mlx_string_put(info->pt, info->wn, 1315, 226, c, "Iterations : ");
	mlx_string_put(info->pt, info->wn, 1445, 226, c, buffer);
	sprintf(buffer, "%f", (2 / info->xup - 1) * 10);
	put_bar_2(info, 323, 350);
	mlx_string_put(info->pt, info->wn, 1300, 323, c, "Zoom :");
	mlx_string_put(info->pt, info->wn, 1380, 323, c, buffer);
	mlx_string_put(info->pt, info->wn, 1510, 323, c, "%");
}

void	put_julia(t_info *info)
{
	char	buffer[50];
	int		c;

	c = ft_rgb(220, 220, 220);
	if (info->proj == 3 || info->proj == 4)
	{
		put_bar_2(info, 78, 145);
		mlx_string_put(info->pt, info->wn, 1400, 78, c, "a :");
		sprintf(buffer, "%f", info->julia.a);
		mlx_string_put(info->pt, info->wn, 1440, 78, c, buffer);
		mlx_string_put(info->pt, info->wn, 1400, 125, c, "b :");
		sprintf(buffer, "%f", info->julia.b);
		mlx_string_put(info->pt, info->wn, 1440, 125, c, buffer);
		mlx_string_put(info->pt, info->wn, 1214, 102, c, "Mouse[J]:");
		if (info->julia_cap)
			mlx_string_put(info->pt, info->wn, 1317, 102, c, "ON");
		else
			mlx_string_put(info->pt, info->wn, 1314, 102, c, "OFF");
	}
	else
	{
		put_bar_2(info, 78, 145);
	}
}

void	select_color(t_info *info)
{
	put_bar_2(info, 450, 470);
	if (info->color == 0)
		draw_cursor(info, 1270, 452);
	if (info->color == 1)
		draw_cursor(info, 1300, 452);
	if (info->color == 2)
		draw_cursor(info, 1330, 452);
	if (info->color == 3)
		draw_cursor(info, 1360, 452);
	if (info->color == 4)
		draw_cursor(info, 1390, 452);
	if (info->color == 5)
		draw_cursor(info, 1420, 452);
	if (info->color == 6)
		draw_cursor(info, 1450, 452);
	if (info->color == 7)
		draw_cursor(info, 1480, 452);
	if (info->color == 8)
		draw_cursor(info, 1510, 452);
	if (info->color == 9)
		draw_cursor(info, 1540, 452);
}

void	put_hud(t_info *info)
{
	char	buffer[50];
	int		c;

	c = ft_rgb(220, 220, 220);
	put_top_info(info);
	put_julia(info);
	select_color(info);
	put_bar_2(info, 573, 620);
	mlx_string_put(info->pt, info->wn, 1326, 573, c, "x :");
	sprintf(buffer, "%f", info->movex);
	mlx_string_put(info->pt, info->wn, 1370, 573, c, buffer);
	mlx_string_put(info->pt, info->wn, 1326, 600, c, "y :");
	sprintf(buffer, "%f", -(info->movey));
	mlx_string_put(info->pt, info->wn, 1370, 600, c, buffer);
}
