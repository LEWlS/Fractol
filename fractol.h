/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 15:12:45 by lbonnete          #+#    #+#             */
/*   Updated: 2019/03/11 16:31:22 by lbonnete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef	struct	s_complex
{
	float			a;
	float			b;
}				t_complex;

typedef	struct	s_info
{
	int			proj;
	void		*pt;
	void		*wn;
	int			fd;
	int			sx;
	int			sy;
	int			x1;
	int			y1;
	int			x2;
	int			y2;
	int			y_origine;
	int			pas;
	int			amp;
	int			w;
	int			set;
	int			wh;
	int			ww;
	char		*addr;
	void		*im;
	char		*cw;
	char		*csx;
	char		*csy;
	char		*cpas;
	char		*camp;
	char		*cproj;
	int			ih;
	int			iw;
	int			ix;
	int			iy;
}				t_info;

int		deal_key(int key, t_info *info);
void	reset_info(t_info *info);
void    mandelbrot(t_info *info);
#endif
