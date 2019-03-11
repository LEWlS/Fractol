/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:16:24 by lbonnete          #+#    #+#             */
/*   Updated: 2019/03/11 15:48:28 by lbonnete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		deal_key(int key, t_info *info)
{
	mlx_clear_window(info->pt, info->wn);
	if (key == 82 || key == 29)
		reset_info(info);
	if (key == 53)
	{
		mlx_destroy_window(info->pt, info->wn);
		exit(0);
	}
	if (key == 51)
		mlx_clear_window(info->pt, info->wn);
	return (0);
}
