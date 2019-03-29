/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   font.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:04:26 by lbonnete          #+#    #+#             */
/*   Updated: 2019/03/29 13:54:18 by lbonnete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	put_bar_1(t_info *info, int y1, int y2)
{
	int x;
	int y;
	int bpp;
	int size_l;
	int endian;

	bpp = 32;
	size_l = 400 * 4;
	endian = 0;
	info->im = mlx_new_image(info->pt, 400, y2 - y1);
	info->addr = mlx_get_data_addr(info->im, &bpp, &size_l, &endian);
	x = 0;
	while (x < 400)
	{
		y = 0;
		while (y < y2 - y1)
		{
			info->ydiff = y2 - y1;
			img_mod_hud(x, y, info, ft_rgb(35, 39, 42));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(info->pt, info->wn, info->im, info->iw, y1);
	mlx_destroy_image(info->pt, info->im);
}

void	put_bar_2(t_info *info, int y1, int y2)
{
	int x;
	int y;
	int bpp;
	int size_l;
	int endian;

	bpp = 32;
	size_l = 400 * 4;
	endian = 0;
	info->im = mlx_new_image(info->pt, 400, y2 - y1);
	info->addr = mlx_get_data_addr(info->im, &bpp, &size_l, &endian);
	x = 0;
	while (x < 400)
	{
		y = 0;
		while (y < y2 - y1)
		{
			info->ydiff = y2 - y1;
			img_mod_hud(x, y, info, ft_rgb(44, 47, 51));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(info->pt, info->wn, info->im, info->iw, y1);
	mlx_destroy_image(info->pt, info->im);
}

void	put_commands(t_info *info)
{
	int		c;
	void	*p;

	p = info->pt;
	c = ft_rgb(220, 220, 220);
	mlx_string_put(p, info->wn, 1220, 750, c,\
	"Arrows to move     H to disable HUD");
	mlx_string_put(p, info->wn, 1210, 658, c,\
	"Left click to drag      0 to reset");
	mlx_string_put(p, info->wn, 1270, 704, c, "Right click to set Julia");
	mlx_string_put(p, info->wn, 1295, 274, c, "<  -    Zoom     +  >");
	mlx_string_put(p, info->wn, 1295, 392, c, "<  [    Color    ]  > ");
	mlx_string_put(p, info->wn, 1295, 181, c, "<  _  Iterations =  > ");
	mlx_string_put(p, info->wn, 1278, 807, c, "Num Pad for Julia Preset");
	mlx_string_put(p, info->wn, 1250,\
	427, c, "[ 0  1  2  3  4  5  6  7  8  9 ]");
	mlx_string_put(p, info->wn, 1297, 510, c, "");
	mlx_string_put(p, info->wn, 1220, 54, c, "Julia Settings :");
}

void	put_font(t_info *info)
{
	int c;

	c = ft_rgb(220, 220, 220);
	put_bar_2(info, 0, info->wh);
	put_bar_1(info, 0, 50);
	put_bar_1(info, 850, 900);
	put_bar_1(info, 165, 173);
	put_bar_1(info, 255, 263);
	put_bar_1(info, 366, 374);
	put_bar_1(info, 475, 483);
	put_bar_1(info, 552, 560);
	put_bar_1(info, 636, 644);
	put_bar_1(info, 780, 788);
	mlx_string_put(info->pt, info->wn, 1285, 865, c, "Lewis");
	mlx_string_put(info->pt, info->wn, 1346, 865, c, "Bonnetete");
	mlx_string_put(info->pt, info->wn, 1468, 865, c, "~ 2019 ~");
	mlx_string_put(info->pt, info->wn, 1288, 520, c, "1   2   3   4   5   6");
	mlx_string_put(info->pt, info->wn, 1325, 486, c, "Switch Fractal");
	put_commands(info);
	info->julia.a = 0;
	info->julia.b = 0;
}
