# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: regien <gmalpart@student.42.us.org>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/05 20:46:22 by regien            #+#    #+#              #
#    Updated: 2018/03/14 20:45:03 by gmalpart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol_test 
NAMEFINAL = fractol
LIB = libft/
MLX = minilibx/
OSXMLX = minilibx_macos_sierra/
CFLAGS = -Wall -Wextra -Werror
CC = gcc

# linux flags - position of the includes mayvary
# library position may vary per distribution
LFLAGS = -L/usr/include/../lib -lXext -lX11 -lm
# OSX flags- frameworks
MFLAGS = -framework OpenGL -framework AppKit
CFILES = main.c \
		 handlers.c \
		 hooks.c

HEADERS = -I includes -I libft/includes -I minilibx_macos_elcapitan

CSTFILES = $(addprefix src/, $(CFILES))

LILIB =		$(LIB)libft.a \
			$(MLX)libmlx_Linux.a

OSXLIB =	$(LIB)libft.a \
			$(OSXMLX)libmlx.a

# These options are here in case the lib needs to be recompiled.
# LIBM, LIBC, LIBF will run rules re, clean and fclean inside the libft folder
LIBM = $(MAKE) $(LIB) re
LIBC = $(MAKE) $(LIB) clean
LIBF = $(MAKE) $(LIB) fclean

# These options are here in case the minilibx needs to be recompiled.
# LIBM, LIBC, LIBF will run rules re, clean and fclean inside the libft folder
MLXM = $(MAKE) $(MLX) re
MLXC = $(MAKE) $(MLX) clean

# These options are here in case the minilibx needs to be recompiled.
# LIBM, LIBC, LIBF will run rules re, clean and fclean inside the libft folder
OSXMLXM = $(MAKE) $(OSXMLX) re
OSXMLXC = $(MAKE) $(OSXMLX) clean

OBJECTS = $(CFILES:.c=.o)

all: $(NAME)

# It will compile by default for Osx(sierra) with his specific minilibx
$(NAME):
	@$(LIBM)
	@$(OSXMLXM)
	@$(CC) $(CFLAGS) $(HEADERS) $(CSTFILES) $(OSXLIB) $(MFLAGS) -o $(NAMEFINAL)

# not compiling with flags yet becuase of linux errors
# linux erros != mac errors
linux:
	@$(LIBM)
	@$(MLXM)
	@$(CC) $(HEADERS) $(CSTFILES) $(LILIB) $(LFLAGS) -o $(NAMEFINAL)
#gcc main.c minilibx/libmlx_Linux.a -L/usr/include/../lib -lXext -lX11 -lm

# this is for compiling fast without spamming your terminal / lINUX
compli:
	$(CC) -g $(HEADERS) $(CSTFILES) $(LILIB) $(LFLAGS) -o $(NAME)

# fast compile for macosx version / MACOSX
# flags deactivated for testing objectives 
comp:
	$(CC) -g $(HEADERS) $(CSTFILES) $(OSXLIB) -Iminilibx_macos_sierra $(MFLAGS) -o $(NAME)

norm:
	norminette $(CSTFILES) Makefile includes/fractol.h

clean:
	@$(LIBC)
	@/bin/rm -f $(OBJECTS)

fclean:
	@$(LIBF)
	@/bin/rm -f $(OBJECTS) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
