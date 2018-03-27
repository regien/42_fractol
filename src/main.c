/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regien <gmalpart@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 08:15:02 by regien            #+#    #+#             */
/*   Updated: 2018/03/11 08:48:27 by regien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	draw_point(int x, int y, int color, t_total *env)
{
	int				i;
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
	env->pix[i] = color;
	env->pix[++i] = color >> 8;
	env->pix[++i] = color >> 16;
}


/*
void	draw_colorpix(int x, int y, int i, t_total *envi)
{
	unsigned int	color;
	t_
}
*/

/*
void	init_colors(t_total *envi)
{
	int		i;
	float	r[3];
	float	g[3];
	float	b[3];

	i = -1;
	envi->colors = ft_memalloc(sizeof(int) * 100);
	r[0] = (float)(COLOR1 >> 16 & 0xFF);
	r[1] = (float)(COLOR2 >> 16 & 0xFF);
	g[0] = (float)(COLOR1 >> 8 & 0xFF);
	g[1] = (float)(COLOR2 >> 8 & 0xFF);
	b[0] = (float)(COLOR1 & 0xFF);
	b[1] = (float)(COLOR2 & 0xFF);
	while (++i < 100)
	{
		r[2] = (float)(r[0] * i) / 100 + (float)(r[1] * (100 - i)) / 100;
		g[2] = (float)(g[0] * i) / 100 + (float)(g[1] * (100 - i)) / 100;
		b[2] = (float)(b[0] * i) / 100 + (float)(b[1] * (100 - i)) / 100;
		envi->colors[i] = (int)r[2] << 16 | (int)g[2] << 8 | (int)b[2];
	}
}
*/

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
void	draw_everything(t_total *envi)
{
	julia(envi);
}

void	infi_draw(t_total *envi)
{
	while(!envi->draw)
	{
		draw_everything(envi);
	}
}
*/



void	loophole(t_total *envi)
{
//;	mlx_expose_hook();
	envi->pressed = ft_memalloc(sizeof(t_keys));
//	infi_draw(envi);
	mlx_hook(envi->win, 2, 0, key_pressed, envi);
	mlx_hook(envi->win, 3, 0, key_release, envi);
	mlx_hook(envi->win, 17, 0, exit_hook, envi);
	mlx_expose_hook(envi->win, mouse_hook, envi);
	mlx_hook(envi->win, 4, 5, mouse_hook, envi);
	mlx_loop(envi->mlx);
}


int	main(int ac, char **av)
{
	t_total *envi;

	envi = ft_memalloc(sizeof(t_total));

	envi->mlx = mlx_init();
	envi->win = mlx_new_window(envi->mlx, WINW, WINH, "fractol_MEX_version");
	envi->img = mlx_new_image(envi->mlx, WINW, WINH);
	envi->pix = (int*)mlx_get_data_addr(envi->img, &(envi->bits), \
				&(envi->s_line), &(envi->endian));

	envi->draw = 1;

	// initializing first fractol
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
	maxiterations = 450;

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


	loophole(envi);
	return (0);
}