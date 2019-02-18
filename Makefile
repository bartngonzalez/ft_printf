# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgonzale <bgonzale@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/26 14:21:09 by bgonzale          #+#    #+#              #
#    Updated: 2019/02/04 18:14:04 by bgonzale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -c

HEADER = ft_printf.h

CFILES = ft_libft.c \
		 ft_printf.c \
		 ft_setformat.c \
		 ft_isflags.c \
		 ft_isminw.c \
		 ft_isprec.c \
		 ft_islen.c \
		 ft_convtype.c \
		 ft_format.c \
		 ft_base.c \
		 ft_flags.c \
		 ft_c_flag.c \
		 ft_s_flag.c \
		 ft_d_i_flag.c \
		 ft_o_flag.c \
		 ft_u_flag.c \
		 ft_x_flag.c \
		 ft_p_flag.c \

OBJS = $(CFILES:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -I.$(HEADER) $(CFILES)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all