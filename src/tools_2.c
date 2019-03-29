/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 13:43:23 by lbonnete          #+#    #+#             */
/*   Updated: 2019/03/29 13:45:25 by lbonnete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	color_it(int x, int y, t_info *info, int n)
{
	if (info->color == 0)
		img_mod(x, y, info, ft_rgb(255, 255, 255));
	if (info->color == 1)
		img_mod(x, y, info, ft_rgb(90 * n * n, n, n * n));
	if (info->color == 2)
		img_mod(x, y, info, ft_rgb(n * n, 90 * n, n * n));
	if (info->color == 3)
		img_mod(x, y, info, ft_rgb(n * n, n, 90 * n * n));
	if (info->color == 4)
		img_mod(x, y, info, ft_rgb(n * n * n, n * n * n, n * n * n));
	if (info->color == 5)
		img_mod(x, y, info, ft_rgb(x * y * n * n, y * n, x * n * n));
	if (info->color == 6)
		img_mod(x, y, info, ft_rgb(x * n * y, y * n * x, x * y * n));
	if (info->color == 7)
		img_mod(x, y, info, ft_rgb(3, 3, 4 * n + 4));
	if (info->color == 9)
		img_mod(x, y, info, ft_rgb(12, 5, 3 * n + 30));
	if (info->color == 8)
		img_mod(x, y, info, ft_rgb(10 * n, 10 * n, 10 * n));
}
