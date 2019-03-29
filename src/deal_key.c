/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 15:54:29 by lbonnete          #+#    #+#             */
/*   Updated: 2019/03/29 14:21:50 by lbonnete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	deal_key_3(int key, t_info *info)
{
	if (key <= 18 || key == 38)
		deal_key_4(key, info);
	else if (key == 20)
	{
		info->mand = -1;
		info->proj = 1;
	}
	else if (key == 19)
	{
		info->mand = 1;
		info->proj = 2;
	}
	else if (key == 21)
	{
		info->mand = -1;
		info->proj = 2;
	}
	else if (key == 23)
	{
		info->proj = 3;
		deal_key(88, info);
	}
	else if (key == 22)
		info->proj = 4;
}

void	deal_key_2(int key, t_info *info)
{
	if (key <= 23 || key == 38)
		deal_key_3(key, info);
	else if (key == 24)
		info->acc++;
	else if (key == 27)
		info->acc--;
	else if (key == 33)
		if (info->color > 0)
			info->color--;
	if (key == 30)
		if (info->color < 9)
			info->color++;
	if (key == 53)
		ft_close(info);
	else if (key == 69)
	{
		info->xup /= 1.02;
		info->xdown /= 1.02;
		info->yup /= 1.02;
		info->ydown /= 1.02;
	}
}

int		deal_key(int key, t_info *info)
{
	if (key == 121 || key == 116)
		deal_key_5(key, info);
	if (key == 82 || key == 29)
		reset_info_0(info);
	else if (key <= 92 && key >= 83)
		preset_julia(key, info);
	else if (key == 78)
	{
		info->xup *= 1.02;
		info->xdown *= 1.02;
		info->yup *= 1.02;
		info->ydown *= 1.02;
	}
	else if (key == 126)
		info->movey -= info->xup / 100;
	else if (key == 124)
		info->movex += info->xup / 100;
	else if (key == 125)
		info->movey += info->xup / 100;
	else if (key == 123)
		info->movex -= info->xup / 100;
	else if (key <= 69)
		deal_key_2(key, info);
	drawer(info);
	return (0);
}

void	preset_julia_2(int key, t_info *info)
{
	if (key == 87)
	{
		info->julia.a = 0.285;
		info->julia.b = 0.01;
	}
	else if (key == 88)
	{
		info->julia.a = -1.476;
		info->julia.b = 0;
	}
	else if (key == 89)
	{
		info->julia.a = (-1) * (0.4);
		info->julia.b = 0.6;
	}
	else if (key == 91)
	{
		info->julia.a = -0.8;
		info->julia.b = 0.156;
	}
	else if (key == 92)
	{
		info->julia.a = -0.038088;
		info->julia.b = 0.9754633;
	}
}

void	preset_julia(int key, t_info *info)
{
	if (key == 83)
	{
		info->julia.a = 0.3;
		info->julia.b = 0.5;
	}
	else if (key == 84)
	{
		info->julia.a = 0.285;
		info->julia.b = 0.01;
	}
	else if (key == 85)
	{
		info->julia.a = (-1) * 1.417022285618;
		info->julia.b = 0.0;
	}
	else if (key == 86)
	{
		info->julia.a = 0.285;
		info->julia.b = 0.013;
	}
	else if (key > 86)
		preset_julia_2(key, info);
}
