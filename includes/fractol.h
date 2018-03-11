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

# define WINW 400
# define WINH 300

typedef struct		s_total
{
	void			*mlx;
	void			*win;

	void			*img;
	int				*pix;
	int				bits;
	int				s_line;
	int				endian;
}					t_total;


#endif
