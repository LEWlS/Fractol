/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 16:23:07 by lbonnete          #+#    #+#             */
/*   Updated: 2019/04/02 17:01:50 by lbonnete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	img_mod(int x, int y, t_info *info, int hexvalue)
{
	int pos;

	pos = x * 4;
	pos += y * info->iw * 4;
	if (pos + 2 < info->iw * 4 * info->ih && pos >= 0)
	{
		info->addr[pos + 2] = hexvalue >> 16;
		info->addr[pos + 1] = hexvalue >> 8;
		info->addr[pos] = hexvalue;
	}
}

void	img_mod_hud(int x, int y, t_info *info, int hexvalue)
{
	int pos;

	pos = x * 4;
	pos += y * 400 * 4;
	if (pos + 2 < 400 * 4 * info->ydiff && pos >= 0)
	{
		info->addr[pos + 2] = hexvalue >> 16;
		info->addr[pos + 1] = hexvalue >> 8;
		info->addr[pos] = hexvalue;
	}
}

int		ft_rgb(int r, int g, int b)
{
	return (256 * 256 * (r) + 256 * (g) + (b));
}

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}

void	draw_cursor(t_info *info, int x, int y)
{
	int mx;
	int my;
	int sy;

	mx = x + 10;
	my = y + 3;
	sy = y;
	while (x < mx)
	{
		y = sy;
		while (y < my)
		{
			mlx_pixel_put(info->pt, info->wn, x, y, ft_rgb(220, 220, 220));
			y++;
		}
		x++;
	}
}
