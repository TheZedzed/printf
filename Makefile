# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azeraoul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/18 11:57:47 by azeraoul          #+#    #+#              #
#    Updated: 2021/02/25 11:55:25 by azeraoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	libftprintf.a

SRC 	:=	$(addprefix srcs/, extract_param.c format_param.c ft_printf.c \
			parse_param.c set_convsize.c set_llist.c  set_param.c utils.c \
			extract_dblparam.c gtoa.c exptoa.c utils3.c utils2.c set_length.c)
OBJ 	:=	$(SRC:.c=.o)

DEP		:=	includes/

CC		:=	gcc
CFLAGS	+=	-Wall -Wextra -Werror
RM		:=	rm -f
AR		:=	ar -qv

all: $(NAME)

$(NAME): libft $(OBJ)
		$(AR) $(NAME) $(OBJ)

srcs/%.o: srcs/%.c
		$(CC) $(CFLAGS) -I$(DEP) -o $@ -c $<

libft:
	make -C libft/
	mv libft/libft.a $(NAME)
	make clean -C libft/

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

bonus: $(NAME)
	
re: fclean all

.PHONY: clean fclean re all libft
