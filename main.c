/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 15:23:13 by lbonnete          #+#    #+#             */
/*   Updated: 2019/03/11 15:48:20 by lbonnete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int     main(int ac, char **av)
{
    t_info info;

    if (ac != 2)
	{
		ft_putendl("Usage : ./fractol <fractal name>");
		return (0);
	}
	ft_putendl(av[1]);
    reset_info(&info);
    info.pt = mlx_init();
	info.wn = mlx_new_window(info.pt, info.ww, info.wh, "fractol");
	mlx_key_hook(info.wn, deal_key, &info);
	mlx_loop(info.pt);
    return (0);
}