/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regien <gmalpart@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 08:15:22 by regien            #+#    #+#             */
/*   Updated: 2018/03/11 08:15:24 by regien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <stdio.h>

# define ESCAPE -1
# define KEY_C 8
# define KEY_ESC 53
# define KEY_W 2
# define KEY_S 0
# define KEY_A 1
# define KEY_D 13
# define KEY_E 14
# define KEY_Q 12
# define KEY_R 15
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_G 17

# define WINW 1200
# define WINH 800
# define MIN(X, Y)	((X) < (Y) ? (X) : (Y))
# define MAX(X, Y)	((X) < (Y) ? (Y) : (X))

typedef struct		s_keys
{
	int				q:1;
	int				e:1;
	int				w:1;
	int				s:1;
	int				a:1;
	int				d:1;
	int				left:1;
	int				down:1;
	int				right:1;
	int				up:1;
}					t_keys;
	
typedef struct		s_rgb
{
	float			r;
	float			g;
	float			b;
}					t_rgb;

typedef struct		s_total
{
	void			*mlx;
	void			*win;

	void			*img;
	int				*pix;
	int				bits;
	int				s_line;
	int				endian;
	int				*color;
	t_keys			*pressed;

	// fractal general control
	int				iter;

	// translation
	int				trax;
	int				tray;
	
	// draw controls
	int				draw;
}					t_total;


/*
** MAIN
*/

void	infi_draw(t_total *envi);
void	draw_everything(t_total *envi);


/*
** HANDLERS
*/

void	fillit_print_usage(char *arg);
void	general_exit(int error_code, char *mensaje);
int		destroy_exit(int error_code, char *mensaje, t_total *envi);
int		destroy_regular_exit(int error_code, t_total *envi);
int		exit_hook(t_total *envi);

/*
** HOOKS
*/

int			expose_hook(t_total *envi);
int			mouse_hook(int keycode, int x, int y, t_total *envi);
int			my_key_function(t_total *envi);
int			key_pressed(int keycode, t_total *envi);
int			key_release(int keycode, t_total *envi);

#endif
