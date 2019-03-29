/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_edit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:17:22 by lbonnete          #+#    #+#             */
/*   Updated: 2019/03/29 14:34:28 by lbonnete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	reset_info(t_info *info)
{
	info->ww = 1600;
	info->wh = 900;
	info->iw = info->ww - 400;
	info->ih = info->wh;
	info->ix = 0;
	info->iy = 0;
	info->xup = 2;
	info->xdown = -2;
	info->yup = 2;
	info->ydown = -2;
	info->pas = 0.1;
	info->acc = 50;
	info->movex = 0;
	info->movey = 0;
	info->color = 9;
	info->julia_cap = 1;
	info->mand = 1;
	info->drag = 0;
	info->hud = 1;
	info->nb_thrd = 20;
}

void	reset_info_0(t_info *info)
{
	info->xup = 2;
	info->xdown = -2;
	info->yup = 2;
	info->ydown = -2;
	info->acc = 100;
	info->movex = 0;
	info->movey = 0;
	info->drag = 0;
}
