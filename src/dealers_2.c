/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealers_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 16:35:52 by lbonnete          #+#    #+#             */
/*   Updated: 2019/03/29 14:09:31 by lbonnete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	mouse_press_2(int x, int y, t_info *info)
{
	float a;
	float b;
	float e;

	e = (info->xup - info->xdown) / 2;
	a = x * 1.0;
	b = y * 1.0;
	info->xdown *= 1.1;
	info->xup *= 1.1;
	info->ydown *= 1.1;
	info->yup *= 1.1;
	info->movex += ((a / info->iw) * (info->xup - info->xdown) - e) / 8;
	info->movey += ((b / info->ih) * (info->yup - info->ydown) - e) / 8;
}

void	mouse_press_3(int x, int y, t_info *info)
{
	float a;
	float b;
	float e;

	a = x * 1.0;
	b = y * 1.0;
	e = (info->xup - info->xdown) / 2;
	info->xdown /= 1.1;
	info->xup /= 1.1;
	info->ydown /= 1.1;
	info->yup /= 1.1;
	info->movex += ((a / info->iw) * (info->xup - info->xdown) - e) / 8;
	info->movey += ((b / info->ih) * (info->yup - info->ydown) - e) / 8;
}

void	deal_key_4(int key, t_info *info)
{
	if (key == 18)
	{
		info->mand = 1;
		info->proj = 1;
	}
	else if (key == 38)
	{
		if (info->julia_cap)
			info->julia_cap = 0;
		else
			info->julia_cap = 1;
	}
	else if (key == 4)
	{
		if (info->hud)
			info->hud = 0;
		else
			info->hud = 1;
	}
}

void	deal_key_5(int key, t_info *info)
{
	if (key == 116)
	{
		info->nb_thrd++;
		printf("Number of threads set to : %i\n", info->nb_thrd);
	}
	else if (key == 121)
	{
		info->nb_thrd--;
		printf("Number of threads set to : %i\n", info->nb_thrd);
	}
}
