/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 15:23:13 by lbonnete          #+#    #+#             */
/*   Updated: 2019/03/28 17:59:05 by lbonnete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int		ft_close(t_info *info)
{
	mlx_destroy_window(info->pt, info->wn);
	exit(0);
	return (0);
}

int		error_1(void)
{
	write(1, "Usage : ./fractol <fractal name>\n", 33);
	write(1, "Mandelbrot(1-2)\nMandelbar(3-4)\nJulia(5-6)\n", 42);
	return (0);
}

int		bibli(char *str, t_info *info)
{
	if (!ft_strcmp(str, "Mandelbrot") || !ft_strcmp(str, "mandelbrot"))
	{
		info->proj = 1;
		return (1);
	}
	if (!ft_strcmp(str, "Mandelbar") || !ft_strcmp(str, "mandelbar"))
	{
		info->proj = 1;
		info->mand = -1;
		return (1);
	}
	if (!ft_strcmp(str, "Julia") || !ft_strcmp(str, "julia"))
	{
		info->proj = 3;
		return (1);
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_info info;

	if (ac != 2)
		return (error_1());
	else
	{
		reset_info(&info);
		if (!bibli(av[1], &info))
			return (error_1());
		info.pt = mlx_init();
		info.wn = mlx_new_window(info.pt, info.ww, info.wh, "Fractol");
		put_font(&info);
		drawer(&info);
		mlx_hook(info.wn, 6, 0, mouse_move, &info);
		mlx_hook(info.wn, 4, 0, mouse_press, &info);
		mlx_hook(info.wn, 5, 0, mouse_release, &info);
		mlx_hook(info.wn, 17, 0, ft_close, &info);
		mlx_hook(info.wn, 2, 0, deal_key, &info);
		mlx_loop(info.pt);
	}
	return (0);
}
