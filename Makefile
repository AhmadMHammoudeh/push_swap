# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahhammou <ahhammou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/11 08:21:23 by ahhammou          #+#    #+#              #
#    Updated: 2022/01/25 08:10:33 by ahhammou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap.a

SOURCES = basic_functions.c bin_sort.c brut_bin_sort.c handlers.c sorters.c

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar cr $(NAME) $(OBJECTS) 
	gcc $(NAME) -o push_swap
	
$(OBJECTS): $(SOURCES)
	gcc $(CFLAGS) -c $^ -I.

clean:
	rm -f $(OBJECTS)
	rm -f *.gch

fclean: clean
	rm -f $(NAME)
	rm -f push_swap

re: fclean all

.PHONY: all clean fclean re  
