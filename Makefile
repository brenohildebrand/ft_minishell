# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/09 16:37:24 by bhildebr          #+#    #+#              #
#    Updated: 2024/05/09 16:37:24 by bhildebr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -MMD -MP
LIBS = -lreadline

SOURCES = 	src/main.c \
			src/parser/check_redirect_rule.c \
			src/parser/get_next_token.c \
			src/parser/build_execution_tree.c \
			src/parser/check_syntax.c \
			src/parser/split_tokens_into_tree.c \
			src/parser/parser.c \
			src/parser/check_parenthesis_rule.c \
			src/parser/get_previous_token.c \
			src/parser/check_control_operator_rule.c \
			src/linked_list/new_linked_list.c \
			src/token/new_token.c \
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
			src/memory_tree/remove_from_memory_tree.c \
			src/lexer/get_token_type.c \
			src/lexer/push_to_token_list.c \
			src/lexer/move_to_next_quote.c \
			src/lexer/get_token_length.c \
			src/lexer/check_open_syntax.c \
			src/lexer/lexer.c \
			src/lexer/get_word_length.c

OBJECTS = 	src/main.o \
			src/parser/check_redirect_rule.o \
			src/parser/get_next_token.o \
			src/parser/build_execution_tree.o \
			src/parser/check_syntax.o \
			src/parser/split_tokens_into_tree.o \
			src/parser/parser.o \
			src/parser/check_parenthesis_rule.o \
			src/parser/get_previous_token.o \
			src/parser/check_control_operator_rule.o \
			src/linked_list/new_linked_list.o \
			src/token/new_token.o \
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
			src/memory_tree/remove_from_memory_tree.o \
			src/lexer/get_token_type.o \
			src/lexer/push_to_token_list.o \
			src/lexer/move_to_next_quote.o \
			src/lexer/get_token_length.o \
			src/lexer/check_open_syntax.o \
			src/lexer/lexer.o \
			src/lexer/get_word_length.o

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
			src/parser/check_redirect_rule.d \
			src/parser/get_next_token.d \
			src/parser/build_execution_tree.d \
			src/parser/check_syntax.d \
			src/parser/split_tokens_into_tree.d \
			src/parser/parser.d \
			src/parser/check_parenthesis_rule.d \
			src/parser/get_previous_token.d \
			src/parser/check_control_operator_rule.d \
			src/linked_list/new_linked_list.d \
			src/token/new_token.d \
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
			src/memory_tree/remove_from_memory_tree.d \
			src/lexer/get_token_type.d \
			src/lexer/push_to_token_list.d \
			src/lexer/move_to_next_quote.d \
			src/lexer/get_token_length.d \
			src/lexer/check_open_syntax.d \
			src/lexer/lexer.d \
			src/lexer/get_word_length.d

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