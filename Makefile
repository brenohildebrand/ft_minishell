# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/29 18:10:21 by bhildebr          #+#    #+#              #
#    Updated: 2024/04/29 18:10:21 by bhildebr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -MMD -MP
LIBS = -lreadline

SOURCES = 	src/main.c \
			src/memory_tree/create_memory_tree.c \
			src/memory_tree/update_memory_tree_height.c \
			src/memory_tree/destroy_memory_tree.c \
			src/memory_tree/rebalance_memory_tree.c \
			src/memory_tree/get_memory_tree_height.c \
			src/memory_tree/search_in_memory_tree.c \
			src/memory_tree/insert_in_memory_tree.c \
			src/memory_tree/remove_from_memory_tree.c

OBJECTS = 	src/main.o \
			src/memory_tree/create_memory_tree.o \
			src/memory_tree/update_memory_tree_height.o \
			src/memory_tree/destroy_memory_tree.o \
			src/memory_tree/rebalance_memory_tree.o \
			src/memory_tree/get_memory_tree_height.o \
			src/memory_tree/search_in_memory_tree.o \
			src/memory_tree/insert_in_memory_tree.o \
			src/memory_tree/remove_from_memory_tree.o

HEADERS = 	include/memory_tree.h \
			include/minishell.h

DEPENDS = 	src/main.d \
			src/memory_tree/create_memory_tree.d \
			src/memory_tree/update_memory_tree_height.d \
			src/memory_tree/destroy_memory_tree.d \
			src/memory_tree/rebalance_memory_tree.d \
			src/memory_tree/get_memory_tree_height.d \
			src/memory_tree/search_in_memory_tree.d \
			src/memory_tree/insert_in_memory_tree.d \
			src/memory_tree/remove_from_memory_tree.d

INCLUDES = 	-iquote include

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(INCLUDES) -o $(NAME) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJECTS) $(DEPENDS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

-include $(DEPENDS)

.PHONY: all clean fclean re