# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nickras <nickras@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/09 12:52:06 by nickras           #+#    #+#              #
#    Updated: 2022/05/31 18:32:03 by nickras          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -*- Makefile -*-

NAMELIB = libftprintf.a
CC = gcc

SRC = ft_printf.c handlers.c hexa.c
LIBFT_PATH		=	libft
LIBFT			=	$(LIBFT_PATH)/libft.a

FLAGS = -Wall -Wextra -Werror -g -std=c99

RM = rm -rf

#If objeft doesnt exist, it will create one
OBJS =      $(SRC:.c=.o)												
$(NAMELIB): $(LIBFT) $(OBJS)
	cp	$(LIBFT) $(NAMELIB)
	ar rcs $(NAMELIB) $(OBJS)

$(LIBFT):
	make -C $(LIBFT_PATH) all

all: $(NAMELIB)
	
clean:
	make -C $(LIBFT_PATH) clean
	$(RM) $(OBJS)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(NAMELIB)

# if object file doesnt exist, or soruce file has changed, (refers to) two different files
%.o: %.c
	$(CC) $(FLAGS) -c $^  -o $@

re: fclean all

.PHONY: all fclean re bonus libft