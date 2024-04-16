# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 16:43:21 by bhildebr          #+#    #+#              #
#    Updated: 2024/04/16 16:43:21 by bhildebr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -MMD -MP
LIBS = -lreadline

SOURCES = 	src/prompt_and_wait_for_input.c \
			src/initialize_minishell_state.c \
			src/create_minishell_state.c \
			src/destroy_minishell_state.c \
			src/main.c \
			src/ft_bzero.c \
			src/allocate_minishell_state.c

OBJECTS = 	src/prompt_and_wait_for_input.o \
			src/initialize_minishell_state.o \
			src/create_minishell_state.o \
			src/destroy_minishell_state.o \
			src/main.o \
			src/ft_bzero.o \
			src/allocate_minishell_state.o

HEADERS = 	include/utils.h \
			include/cstring.h \
			include/minishell.h

DEPENDS = 	src/prompt_and_wait_for_input.d \
			src/initialize_minishell_state.d \
			src/create_minishell_state.d \
			src/destroy_minishell_state.d \
			src/main.d \
			src/ft_bzero.d \
			src/allocate_minishell_state.d

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