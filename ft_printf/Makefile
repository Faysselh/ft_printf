# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fayel-ha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/07 17:15:53 by fayel-ha          #+#    #+#              #
#    Updated: 2020/10/16 01:59:54 by Fayel-ha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS = -Wall -Werror -Wextra

SRCS = ft_printf.c \
		ft_printstr.c \
		ft_print_utils.c \
		ft_printc.c \
		ft_fillstruct.c \
		ft_makestr.c \
		ft_printint.c \
		ft_print_x.c \
		ft_print_x_utils.c \
		ft_printd_utils.c \
		ft_printp.c \
		ft_printu.c \
		ft_printu_utils.c \
		ft_printx.c \
		ft_printx_utils.c \
		ft_putnbr_base.c \
		utils2.c

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) -c $(SRCS)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
clean:
	rm -f $(OBJ) $(OBJ_BON)

fclean: clean
	rm -f $(NAME)

re: fclean all
