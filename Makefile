# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/09 18:11:00 by bhildebr          #+#    #+#              #
#    Updated: 2024/05/09 18:11:00 by bhildebr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -MMD -MP
LIBS = -lreadline

SOURCES = 	src/main.c \
			src/linked_list/new_linked_list.c \
			src/token/new_token.c \
			src/minishell/mini_quit.c \
			src/minishell/set_exit_status.c \
			src/minishell/new_minishell.c \
			src/minishell/mini_free.c \
			src/minishell/mini_alloc.c \
			src/minishell/syntax_error.c \
			src/minishell/reset_for_next_iteration.c \
			src/binary_tree/new_binary_tree.c \
			src/executor/executor.c \
			src/memory_tree/create_memory_tree.c \
			src/memory_tree/update_memory_tree_height.c \
			src/memory_tree/destroy_memory_tree.c \
			src/memory_tree/rebalance_memory_tree.c \
			src/memory_tree/get_memory_tree_height.c \
			src/memory_tree/search_in_memory_tree.c \
			src/memory_tree/insert_in_memory_tree.c \
			src/memory_tree/remove_from_memory_tree.c

OBJECTS = 	src/main.o \
			src/linked_list/new_linked_list.o \
			src/token/new_token.o \
			src/minishell/mini_quit.o \
			src/minishell/set_exit_status.o \
			src/minishell/new_minishell.o \
			src/minishell/mini_free.o \
			src/minishell/mini_alloc.o \
			src/minishell/syntax_error.o \
			src/minishell/reset_for_next_iteration.o \
			src/binary_tree/new_binary_tree.o \
			src/executor/executor.o \
			src/memory_tree/create_memory_tree.o \
			src/memory_tree/update_memory_tree_height.o \
			src/memory_tree/destroy_memory_tree.o \
			src/memory_tree/rebalance_memory_tree.o \
			src/memory_tree/get_memory_tree_height.o \
			src/memory_tree/search_in_memory_tree.o \
			src/memory_tree/insert_in_memory_tree.o \
			src/memory_tree/remove_from_memory_tree.o

HEADERS = 	include/executor.h \
			include/types.h \
			include/token.h \
			include/lexer.h \
			include/memory_tree.h \
			include/minishell.h \
			include/linked_list.h \
			include/parser.h \
			include/binary_tree.h

DEPENDS = 	src/main.d \
			src/linked_list/new_linked_list.d \
			src/token/new_token.d \
			src/minishell/mini_quit.d \
			src/minishell/set_exit_status.d \
			src/minishell/new_minishell.d \
			src/minishell/mini_free.d \
			src/minishell/mini_alloc.d \
			src/minishell/syntax_error.d \
			src/minishell/reset_for_next_iteration.d \
			src/binary_tree/new_binary_tree.d \
			src/executor/executor.d \
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