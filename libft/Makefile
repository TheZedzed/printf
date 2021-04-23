# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azeraoul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/18 11:57:47 by azeraoul          #+#    #+#              #
#    Updated: 2021/02/24 07:07:43 by azeraoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	libft.a

SRC 	:=	ft_memset.c ft_memcpy.c \
			ft_strlen.c ft_isdigit.c \
			ft_strchr.c ft_itoa.c \
			ft_atoi.c ft_calloc.c ft_strdup.c \
			ft_strjoin.c ft_bzero.c

OBJ 	:=	$(SRC:.c=.o)
DEP		:=	.

CC		:=	gcc
CFLAGS	+=	-Wall -Wextra -Werror
RM		:=	rm -f
AR		:=	ar -rcs

all: $(NAME)

$(NAME): $(OBJ)
		$(AR) $(NAME) $(OBJ)

%.o: %.c
		$(CC) $(CFLAGS) -I$(DEP) -o $@ -c $<

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all
