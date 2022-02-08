# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahhammou <ahhammou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/11 08:21:23 by ahhammou          #+#    #+#              #
#    Updated: 2022/01/31 15:55:37 by ahhammou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CFLAGS = -Wall -Wextra -Werror

SOURCES = basic_functions.c bin_sort.c brut_bin_sort.c handlers.c sorters.c ft_split.c ft_calloc.c 

OBJECTS = $(SOURCES:.c=.o)

$(NAME): $(OBJECTS)
	gcc $(CFLAGS) $(SOURCES) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJECTS)
	rm -f *.gch

fclean: clean
	rm -f $(NAME)
	rm -f push_swap

re: fclean all

.PHONY: all clean fclean re  
