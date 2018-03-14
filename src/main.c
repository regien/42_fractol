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
//	env->pix[++i] = color >> 8;
//	env->pix[++i] = color >> 16;
}

void	draw_colorpix(int x, int y, int i, t_total *envi)
{
	unsigned int	color;
	t_
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
	int color;

	int maxiterations;

	int x;
	int y;

//	x = -1;
	y = -1;

	movex = 0;
	movey = 0;

	zoom = 1;
	maxiterations = 300;

	cre = -0.7;
	cim = 0.27015;
	
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
			color =	0xFFFFFF;
//			color++;
			//draw the f pixel
			draw_point(x, y, color, envi);
		}
	}
	mlx_put_image_to_window(envi->mlx, envi->win, envi->img, 0, 0);


	mlx_loop(envi->mlx);
	return (0);
}