# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlamtaou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 20:22:58 by rlamtaou          #+#    #+#              #
#    Updated: 2023/11/28 20:23:10 by rlamtaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC= ft_printf.c\
	 ft_tools.c

OBJ= $(SRC:.c=.o)
CC= cc
CFLAGS= -Wall -Wextra  -Werror 
RM= rm -f
AR= ar -rc

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
