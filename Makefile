# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/16 19:08:01 by bhildebr          #+#    #+#              #
#    Updated: 2024/05/16 19:08:01 by bhildebr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -MMD -MP
LIBS = -lreadline

SOURCES = 	src/main.c \
			src/binary_tree/new_binary_tree.c \
			src/executor/executor.c \
			src/lexer/check_open_syntax.c \
			src/lexer/get_subcstring.c \
			src/lexer/get_token_length.c \
			src/lexer/get_token_type.c \
			src/lexer/get_word_length.c \
			src/lexer/lexer.c \
			src/lexer/move_to_next_quote.c \
			src/lexer/push_to_token_list.c \
			src/linked_list/destroy_linked_list.c \
			src/linked_list/destroy_linked_list_node.c \
			src/linked_list/new_linked_list.c \
			src/linked_list/new_linked_list_node.c \
			src/memory_tree/create_memory_tree.c \
			src/memory_tree/destroy_memory_tree.c \
			src/memory_tree/get_memory_tree_height.c \
			src/memory_tree/insert_in_memory_tree.c \
			src/memory_tree/rebalance_memory_tree.c \
			src/memory_tree/remove_from_memory_tree.c \
			src/memory_tree/search_in_memory_tree.c \
			src/memory_tree/update_memory_tree_height.c \
			src/minishell/destroy_minishell.c \
			src/minishell/mini_alloc.c \
			src/minishell/mini_free.c \
			src/minishell/mini_quit.c \
			src/minishell/new_minishell.c \
			src/minishell/reset_minishell.c \
			src/minishell/set_exit_status.c \
			src/minishell/syntax_error.c \
			src/parser/parser.c \
			src/token/destroy_token.c \
			src/token/new_token.c \
			src/utils/ft_strncmp.c

OBJECTS = 	src/main.o \
			src/binary_tree/new_binary_tree.o \
			src/executor/executor.o \
			src/lexer/check_open_syntax.o \
			src/lexer/get_subcstring.o \
			src/lexer/get_token_length.o \
			src/lexer/get_token_type.o \
			src/lexer/get_word_length.o \
			src/lexer/lexer.o \
			src/lexer/move_to_next_quote.o \
			src/lexer/push_to_token_list.o \
			src/linked_list/destroy_linked_list.o \
			src/linked_list/destroy_linked_list_node.o \
			src/linked_list/new_linked_list.o \
			src/linked_list/new_linked_list_node.o \
			src/memory_tree/create_memory_tree.o \
			src/memory_tree/destroy_memory_tree.o \
			src/memory_tree/get_memory_tree_height.o \
			src/memory_tree/insert_in_memory_tree.o \
			src/memory_tree/rebalance_memory_tree.o \
			src/memory_tree/remove_from_memory_tree.o \
			src/memory_tree/search_in_memory_tree.o \
			src/memory_tree/update_memory_tree_height.o \
			src/minishell/destroy_minishell.o \
			src/minishell/mini_alloc.o \
			src/minishell/mini_free.o \
			src/minishell/mini_quit.o \
			src/minishell/new_minishell.o \
			src/minishell/reset_minishell.o \
			src/minishell/set_exit_status.o \
			src/minishell/syntax_error.o \
			src/parser/parser.o \
			src/token/destroy_token.o \
			src/token/new_token.o \
			src/utils/ft_strncmp.o

HEADERS = 	include/binary_tree.h \
			include/executor.h \
			include/lexer.h \
			include/linked_list.h \
			include/memory_tree.h \
			include/minishell.h \
			include/parser.h \
			include/token.h \
			include/types.h \
			include/utils.h

DEPENDS = 	src/main.d \
			src/binary_tree/new_binary_tree.d \
			src/executor/executor.d \
			src/lexer/check_open_syntax.d \
			src/lexer/get_subcstring.d \
			src/lexer/get_token_length.d \
			src/lexer/get_token_type.d \
			src/lexer/get_word_length.d \
			src/lexer/lexer.d \
			src/lexer/move_to_next_quote.d \
			src/lexer/push_to_token_list.d \
			src/linked_list/destroy_linked_list.d \
			src/linked_list/destroy_linked_list_node.d \
			src/linked_list/new_linked_list.d \
			src/linked_list/new_linked_list_node.d \
			src/memory_tree/create_memory_tree.d \
			src/memory_tree/destroy_memory_tree.d \
			src/memory_tree/get_memory_tree_height.d \
			src/memory_tree/insert_in_memory_tree.d \
			src/memory_tree/rebalance_memory_tree.d \
			src/memory_tree/remove_from_memory_tree.d \
			src/memory_tree/search_in_memory_tree.d \
			src/memory_tree/update_memory_tree_height.d \
			src/minishell/destroy_minishell.d \
			src/minishell/mini_alloc.d \
			src/minishell/mini_free.d \
			src/minishell/mini_quit.d \
			src/minishell/new_minishell.d \
			src/minishell/reset_minishell.d \
			src/minishell/set_exit_status.d \
			src/minishell/syntax_error.d \
			src/parser/parser.d \
			src/token/destroy_token.d \
			src/token/new_token.d \
			src/utils/ft_strncmp.d

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