/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:16:24 by lbonnete          #+#    #+#             */
/*   Updated: 2019/04/02 12:16:24 by lbonnete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	mouse_move_2(int x, int y, t_info *info)
{
	float	a;
	float	b;
	float	c;
	float	d;

	a = x * 1.0;
	b = y * 1.0;
	x = (info->xup - info->xdown) / 2;
	c = info->x1 * 1.0;
	d = info->y1 * 1.0;
	a = ((a / info->iw) * (info->xup - info->xdown) - x) / 7;
	b = ((b / info->iw) * (info->xup - info->xdown) - x) / 7;
	c = ((c / info->iw) * (info->xup - info->xdown) - x) / 7;
	d = ((d / info->iw) * (info->xup - info->xdown) - x) / 7;
	info->movex += c - a;
	info->movey += d - b;
}

int		mouse_move(int x, int y, t_info *info)
{
	float	a;
	float	b;

	if (info->drag && x >= 0 && y >= 0 && x <= info->iw && y <= info->ih)
		mouse_move_2(x, y, info);
	if (info->julia_cap)
	{
		a = x * 1.0;
		b = y * 1.0;
		a = a / info->ww * info->iw;
		b = b / info->wh * info->ih;
		info->julia.a = (a / info->iw) * 4 - 2;
		info->julia.b = -((b / info->ih) * 4 - 2);
	}
	drawer(info);
	return (1);
}

int		mouse_press(int button, int x, int y, t_info *info)
{
	if (button == 1 && x >= 0 && y >= 0 && x <= info->iw && y <= info->ih)
	{
		info->x1 = x;
		info->y1 = y;
		info->drag = 1;
	}
	if (button == 5)
		mouse_press_3(x, y, info);
	if (button == 4)
		mouse_press_2(x, y, info);
	if (button == 2)
	{
		if (info->julia_cap)
			info->julia_cap = 0;
		else
			info->julia_cap = 1;
	}
	drawer(info);
	return (1);
}

int		mouse_release(int button, int x, int y, t_info *info)
{
	if (button == 1)
		info->drag = 0;
	(void)x;
	(void)y;
	drawer(info);
	return (1);
}
