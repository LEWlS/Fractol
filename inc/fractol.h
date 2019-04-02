/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 15:12:45 by lbonnete          #+#    #+#             */
/*   Updated: 2019/04/02 17:07:14 by lbonnete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx/mlx.h"
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>

# define NB_THREADS_MAX 1000

typedef struct s_mthrds	t_mthrds;
typedef struct s_thrd	t_thrd;
typedef	struct s_info	t_info;
typedef	struct s_complex	t_complex;

struct			s_complex
{
	double		a;
	double		b;
};

struct			s_thrd
{
	int			id;
	t_info		*info;
	int			n;
	t_complex	c;
	t_complex	z;

};

struct			s_mthrds
{
	pthread_t	threads[NB_THREADS_MAX];
	t_thrd		thrd[NB_THREADS_MAX];
};

struct			s_info
{
	void		*pt;
	void		*wn;
	double		xup;
	double		xdown;
	double		yup;
	double		ydown;
	double		movex;
	double		movey;
	int			wh;
	int			ww;
	char		*addr;
	void		*im;
	int			ih;
	int			iw;
	int			ix;
	int			iy;
	int			x1;
	int			y1;
	int			ydiff;
	double		pas;
	int			acc;
	int			proj;
	int			color;
	char		julia_cap;
	int			mand;
	char		drag;
	char		hud;
	int			nb_thrd;
	t_complex	julia;
	t_mthrds	mthrds;
};

int				deal_key(int key, t_info *info);
void			deal_key_2(int key, t_info *info);
void			deal_key_3(int key, t_info *info);
void			deal_key_4(int key, t_info *info);
void			deal_key_5(int key, t_info *info);
int				key_press(int keycode, t_info *info);
int				key_release(int keycode, void *param);
int				mouse_press(int button, int x, int y, t_info *info);
void			mouse_press_2(int x, int y, t_info *info);
void			mouse_press_3(int x, int y, t_info *info);
int				mouse_release(int button, int x, int y, t_info *info);
int				mouse_move(int x, int y, t_info *info);
int				ft_close(t_info *info);
void			reset_info_0(t_info *info);

void			color_it(int x, int y, t_info *info, int n);
int				ft_rgb(int r, int g, int b);

void			reset_info(t_info *info);
void			*mandelbrot(void *thrds);
void			*mandelbrot_3(void *thrds);
void			*julia(void *thrds);
void			*julia_3(void *thrds);
void			drawer(t_info *info);

int				boucle_mandelbrot_2(t_complex z, t_complex c, t_info *info);
int				boucle_mandelbrot_3(t_complex z, t_complex c, t_info *info);
int				boucle_julia_2(t_complex z, t_complex c, t_info *info);
int				boucle_julia_3(t_complex z, t_complex c, t_info *info);

int				ft_strcmp(const char *s1, const char *s2);
void			preset_julia(int key, t_info *info);
void			*choose(t_info *info);

void			img_mod(int x, int y, t_info *info, int hexvalue);
void			img_mod_hud(int x, int y, t_info *info, int hexvalue);
void			put_hud(t_info *info);
void			put_font(t_info *info);
void			put_commands(t_info *info);
void			put_bar_1(t_info *info, int y1, int y2);
void			put_bar_2(t_info *info, int y1, int y2);
void			select_color(t_info *info);
void			draw_cursor(t_info *info, int x, int y);

void			ft_multithreading(t_info *info);
#endif
