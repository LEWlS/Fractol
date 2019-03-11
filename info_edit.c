/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_edit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:17:22 by lbonnete          #+#    #+#             */
/*   Updated: 2019/03/11 17:07:16 by lbonnete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	reset_info(t_info *info)
{
	info->x1 = 0;
	info->y1 = 0;
	info->x2 = 0;
	info->y2 = 0;
	info->amp = 1;
	info->w = 32;
	info->set = 0;
	info->pas = 50;
	info->wh = 1080;
	info->ww = 1920;
	info->ih = info->wh - 50;
	info->iw = 6 * info->ww / 8;
	info->sx = info->iw / 2;
	info->sy = 5 * info->ih / 100;
	info->ix = info->ww / 8;
	info->iy = 75;
	info->proj = 1;
}
