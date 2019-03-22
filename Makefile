# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgonzale <bgonzale@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/26 14:21:09 by bgonzale          #+#    #+#              #
#    Updated: 2019/03/21 23:32:48 by bgonzale         ###   ########.fr        #
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
		 ft_convtype.c \
		 ft_format.c \
		 ft_base.c \
		 ft_flags.c \
		 ft_c_conv.c \
		 ft_s_conv.c \
		 ft_p_conv.c \
		 ft_di_conv.c \
		 ft_di_conv_2.c \
		 ft_di_conv_3.c \
		 ft_o_conv.c \
		 ft_u_flag.c \
		 ft_x_flag.c \

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
