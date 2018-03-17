/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 20:34:12 by gmalpart          #+#    #+#             */
/*   Updated: 2018/03/14 20:34:35 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Print General usage.
*/

void	fillit_print_usage(char *arg)
{
	ft_putstr("usage ");
	ft_putstr(arg);
//  imrpimir todas las funciones, seas pendejo y hazlo
//	ft_putstr(" valid_file.fdf\n");
	exit(-1);
}

/*
** General Exit.
*/


void	general_exit(int error_code, char *mensaje)
{
	if (error_code < 0)
		ft_putstr(mensaje);
	exit(error_code);
}

// revisar esta funcion porque se supone que debe cerrar la ventana de
// manera correcta
int		destroy_exit(int error_code, char *mensaje, t_total *envi)
{
	mlx_destroy_window(envi->mlx, envi->win);
	if (error_code < 0)
		ft_putstr(mensaje);
//	free_everything(envi);
	exit(error_code);
	return (0);
}

int		destroy_regular_exit(int error_code, t_total *envi)
{
	mlx_destroy_window(envi->mlx, envi->win);
	exit(error_code);
	return (0);
}