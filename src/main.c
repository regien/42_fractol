/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regien <gmalpart@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 08:15:02 by regien            #+#    #+#             */
/*   Updated: 2018/04/24 23:42:14 by regien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

/*
** These functions were modfied from the previus project (FDF)
** and just being refactorized to work with this project
** which at some point it way simplier
*/

void	draw_point(int x, int y, int iter, t_total *env)
{
	int				i;
	int				e;
//	unsigned int	color;
//	float			which;

	if (x > WINW || y > WINH || x < 0 \
			|| y < 0)
		return ;
	i = (x) + (y * env->s_line / 4);
	if (i > WINH * WINW)
		return ;
//	which = env->which;
//	color = env->colors[(int)which];
	env->pix[i] = env->color[iter % 100];
	env->pix[++i] = env->color[iter % 100] >> 8;
	env->pix[++i] = env->color[iter % 100] >> 16;
}

int		*get_color(int first, int last)
{
	int		i;
	t_rgb	swaper[3];
	int		*color;

	i = -1;
	color = ft_memalloc(sizeof(int) * 100);
//	swaper = ft_memalloc(sizeof(t_rgb) * 3);
	swaper[0].r = (float)(first >> 16 & 0xFF);
	swaper[1].r = (float)(last >> 16 & 0xFF);
	swaper[0].g = (float)(first >> 8 & 0xFF);
	swaper[1].g = (float)(last >> 8 & 0xFF);
	swaper[0].b = (float)(first & 0xFF);
	swaper[1].b = (float)(last & 0xFF);
	while (++i < 100)
	{
		swaper[2].r = (float)((swaper[0].r * i) / 100) + \
		(float)(swaper[1].r * (100 - i) / 100);
		swaper[2].g = (float)((swaper[0].g * i) / 100) + \
		(float)(swaper[1].g * (100 - i) / 100);
		swaper[2].b = (float)((swaper[0].b * i) / 100) + \
		(float)(swaper[1].b * (100 - i) / 100);
		color[i] = (int)swaper[2].r << 16 | (int)swaper[2].g << 8 |\
		(int)swaper[2].b;
	}
	return (color);
}

/*
		newre = 1.5 * (x - WINW / 2) / (0.5 * zoom * WINW) + movex;
		newim = (y - WINH / 2) / (0.5 * zoom * WINH) + movey;

		int i;
		i = -1;
		while (++i < maxiterations)
			{
				oldre = newre;
				oldim = newim;
				
				newre = oldre  * oldre - oldim * oldim + cre;
				newim = 2 * oldre * oldim + cim;

				if ((newre * newre + newim * newim) > 4)u)
	while()
}
*/

int		draw_julia(int x, int y, t_total *envi)
{
	double	newre;
	double	newim;
	double	oldre;
	double	oldim;
	int		i;
	
	newre = 1.5 * (x - WINW / 2) / (0.5 * envi->scale *WINW) \
	+ envi->trax;
	newim = (y - WINH / 2) / (0.5 * envi->scale * WINH) \
	+ envi->tray;
	i = -1;
	while (++i < envi->max)
	{
		oldre = newre;
		oldim = newim;
		newre = oldre * oldre - oldim * oldim + envi->hola;
		newim = 2 * oldre * oldim + envi->holb;
		if ((newre * newre + newim * newim) > 4)
			break;
	}
	return (i);
}

/*
int		draw_mandelbrot(int x, int y, t_total *envi)
{
	double	pr;
	double	pi;
	double	newre;
	double	newim;
	double	oldre;
	double	oldim;
	int		i;

	i = -1;
	newre = 0;
	newim = 0;
	
	pr = 1.5 * (x - WINW / 2) / (0.5 * envi->scale * WINW) + envi->trax;
	pi = (y - WINH / 2) / (0.5 * envi->scale * WINH) + envi->tray;
	while (i++ < envi->iter)
	{
		oldre = newre;
		oldim = newim;
		newre = oldre * oldre - oldim * oldim + pr;
		newim = 2 * oldre * oldim + pi;
		if ((newre * newre + newim * newim) > 4)
			break ;
	}
	return (i);
}
*/

int		draw_mandelbrot(int x, int y, t_total *envi)
{
	double	pr;
	double	pi;
	double	newre;
	double	newim;
	double	oldre;
	double	oldim;
	int		i;

	i = -1;
	newre = 0;
	newim = 0;
	
	pr = 1.5 * (x - WINW / 2) / (0.5 * envi->scale * WINW) + envi->trax;
	pi = (y - WINH / 2) / (0.5 * envi->scale * WINH) + envi->tray;
	while (i++ < envi->iter)
	{
		oldre = newre;
		oldim = newim;
		newre = oldre * oldre - oldim * oldim + pr;
		newim = 2 * oldre * oldim + pi;
		if ((newre * newre + newim * newim) > 4)
			break ;
	}
	return (i);
}

/*
int		draw_julia(int x, int y, t_total *envi)
{
	double	za;
	double	zb;
	double	temp;
	int		i;

	za = ((4 * x / WINW - 2) / envi->scale) +
		((envi->trax / WINW));
	zb = ((-4 * y / WINH + 2) / envi->scale) +
		((envi->tray / WINH));
	i = -1;
	while (za * za + zb * zb <= 4 && ++i < envi->max)
	{
		temp = za;
		za = za * za - zb * zb + envi->hola;
		zb = 2 * temp * zb + envi->holb;
	}
	return (i);
}
*/

void	draw_fractol(t_total *envi)
{
	// initialize mutlithreading right here, it would be easier
	// commom gerardo
	int		x;
	int		y;

	y = -1;
	while (++y < WINH)
	{
		x = -1;
		while (++x < WINW)
			draw_point(x, y, draw_mandelbrot(x, y, envi), envi);
	}
}
	
void	init_values(t_total *envi)
{
	envi->scale = 1.0;
	envi->trax = 0;
	envi->tray = 0;
	envi->iter = 45;
	envi->hola = -0.7;
	envi->holb = 0.27015;
	envi->blocked = 0;
	envi->max = 45;
	envi->color = get_color(0xFFFFFF, 0x234513);
}


void		redraw(t_total *envi)
{
	envi->img = mlx_new_image(envi->mlx, WINW, WINH);
	envi->pix = (int*)mlx_get_data_addr(envi->img, &(envi->bits), \
				&(envi->s_line), &(envi->endian));
	// or draw fractol
	draw_fractol(envi);
	mlx_put_image_to_window(envi->mlx, envi->win, envi->img, \
	0, 0);
	mlx_destroy_image(envi->mlx, envi->img);
}

void	loophole(t_total *envi)
{
	envi->max = 45;
	envi->pressed = ft_memalloc(sizeof(t_keys));
//	infi_draw(envi);
	init_values(envi);
	mlx_hook(envi->win, 2, 0, key_pressed, envi);
	mlx_hook(envi->win, 3, 0, key_release, envi);
	mlx_hook(envi->win, 17, 0, exit_hook, envi);
	mlx_expose_hook(envi->win, expose_hook, envi);
	mlx_hook(envi->win, 4, 5, mouse_hook, envi);
	mlx_hook(envi->win, 6,  64, mouse_move, envi);
	mlx_loop(envi->mlx);
}


int	main(int ac, char **av)
{
	t_total *envi;

	envi = ft_memalloc(sizeof(t_total));

	envi->mlx = mlx_init();
	envi->win = mlx_new_window(envi->mlx, WINW, WINH, "fractol_MEX_version");
//	envi->img = mlx_new_image(envi->mlx, WINW, WINH);
//	envi->pix = (int*)mlx_get_data_addr(envi->img, &(envi->bits), 
//				&(envi->s_line), &(envi->endian));

	envi->draw = 1;

	// initializing first fractol
	/*
	double	cre;
	double	cim;
	
	double	newre;
	double	newim;
	double	oldre;
	double	oldim;
	
	double	zoom;
	double	movex;
	double	movey;

	// you know, hexadecimal not so hard to find
	int *color;

	int maxiterations;

	int x;
	int y;

//	x = -1;
	y = -1;

	movex = 0;
	movey = 0;

	zoom = 1;
	maxiterations = 150;

	cre = -0.7;
	cim = 0.27015;
	
	color = get_color(0xFFFFFF, 0x234513);

		
	while (++y < WINH)
	{
		x = -1;
		while (++x < WINW)
		{
			newre = 1.5 * (x - WINW / 2) / (0.5 * zoom * WINW) + movex;
			newim = (y - WINH / 2) / (0.5 * zoom * WINH) + movey;

			int i;

			i = -1;
			while (++i < maxiterations)
			{
				oldre = newre;
				oldim = newim;
				
				newre = oldre  * oldre - oldim * oldim + cre;
				newim = 2 * oldre * oldim + cim;

				if ((newre * newre + newim * newim) > 4)
					break;
			}
			
			// you have to change the color to make it interactive
//			color++;
			//draw the f pixel
			draw_point(x, y, color[i % 100], envi);
		}
	}
	mlx_put_image_to_window(envi->mlx, envi->win, envi->img, 0, 0);

*/
	loophole(envi);
	return (0);
}
