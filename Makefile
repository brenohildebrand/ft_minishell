# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
<<<<<<< HEAD
#    Created: 2024/04/17 19:36:04 by bhildebr          #+#    #+#              #
#    Updated: 2024/04/17 19:36:04 by bhildebr         ###   ########.fr        #
=======
#    Created: 2024/04/29 16:01:12 by bhildebr          #+#    #+#              #
#    Updated: 2024/04/29 16:01:12 by bhildebr         ###   ########.fr        #
>>>>>>> feat: creates a foundation for the minishell
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -MMD -MP
LIBS = -lreadline

<<<<<<< HEAD
SOURCES = 	src/memory_tree/create_memory_tree.c \
			src/memory_tree/destroy_memory_tree.c \
			src/memory_tree/get_memory_tree_height.c \
			src/memory_tree/insert_in_memory_tree.c \
			src/memory_tree/rebalance_memory_tree.c \
			src/memory_tree/remove_from_memory_tree.c \
			src/memory_tree/search_in_memory_tree.c \
			src/memory_tree/update_memory_tree_height.c \
			src/minishell/allocate_minishell_state.c \
			src/minishell/create_minishell_state.c \
			src/minishell/destroy_minishell_state.c \
			src/minishell/ft_bzero.c \
			src/minishell/initialize_minishell_state.c \
			src/minishell/main.c \
			src/minishell/minishell_allocate.c \
			src/minishell/minishell_deallocate.c \
			src/minishell/prompt_and_wait_for_input.c

OBJECTS = 	src/memory_tree/create_memory_tree.o \
			src/memory_tree/destroy_memory_tree.o \
			src/memory_tree/get_memory_tree_height.o \
			src/memory_tree/insert_in_memory_tree.o \
			src/memory_tree/rebalance_memory_tree.o \
			src/memory_tree/remove_from_memory_tree.o \
			src/memory_tree/search_in_memory_tree.o \
			src/memory_tree/update_memory_tree_height.o \
			src/minishell/allocate_minishell_state.o \
			src/minishell/create_minishell_state.o \
			src/minishell/destroy_minishell_state.o \
			src/minishell/ft_bzero.o \
			src/minishell/initialize_minishell_state.o \
			src/minishell/main.o \
			src/minishell/minishell_allocate.o \
			src/minishell/minishell_deallocate.o \
			src/minishell/prompt_and_wait_for_input.o

HEADERS = 	include/cstring.h \
			include/minishell.h \
			include/utils.h

DEPENDS = 	src/memory_tree/create_memory_tree.d \
			src/memory_tree/destroy_memory_tree.d \
			src/memory_tree/get_memory_tree_height.d \
			src/memory_tree/insert_in_memory_tree.d \
			src/memory_tree/rebalance_memory_tree.d \
			src/memory_tree/remove_from_memory_tree.d \
			src/memory_tree/search_in_memory_tree.d \
			src/memory_tree/update_memory_tree_height.d \
			src/minishell/allocate_minishell_state.d \
			src/minishell/create_minishell_state.d \
			src/minishell/destroy_minishell_state.d \
			src/minishell/ft_bzero.d \
			src/minishell/initialize_minishell_state.d \
			src/minishell/main.d \
			src/minishell/minishell_allocate.d \
			src/minishell/minishell_deallocate.d \
			src/minishell/prompt_and_wait_for_input.d
=======
SOURCES = 	src/main.c

OBJECTS = 	src/main.o

HEADERS = 	include/minishell.h

DEPENDS = 	src/main.d
>>>>>>> feat: creates a foundation for the minishell

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