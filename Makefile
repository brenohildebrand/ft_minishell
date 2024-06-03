# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/03 14:59:40 by bhildebr          #+#    #+#              #
#    Updated: 2024/06/03 14:59:40 by bhildebr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -MMD -MP
LIBS = -lreadline -llua5.4

minishell_sources = 	src/main.c \
		src/contexts/config/config_create.c \
		src/contexts/config/config_create_lua_state.c \
		src/contexts/config/config_destroy_lua_state.c \
		src/contexts/config/config_get_path.c \
		src/contexts/config/config_get_prompt.c \
		src/contexts/input/input_create.c \
		src/contexts/input/input_get_prompt.c \
		src/contexts/lexer/lexer_add_character.c \
		src/contexts/lexer/lexer_create.c \
		src/contexts/lexer/lexer_delimit.c \
		src/contexts/lexer/lexer_discard_character.c \
		src/contexts/lexer/lexer_eighth_rule.c \
		src/contexts/lexer/lexer_fifth_rule.c \
		src/contexts/lexer/lexer_first_rule.c \
		src/contexts/lexer/lexer_fourth_rule.c \
		src/contexts/lexer/lexer_heredoc.c \
		src/contexts/lexer/lexer_ninth_rule.c \
		src/contexts/lexer/lexer_ordinary.c \
		src/contexts/lexer/lexer_reset.c \
		src/contexts/lexer/lexer_second_rule.c \
		src/contexts/lexer/lexer_seventh_rule.c \
		src/contexts/lexer/lexer_sixth_rule.c \
		src/contexts/lexer/lexer_tenth_rule.c \
		src/contexts/lexer/lexer_third_rule.c \
		src/contexts/lexer/lexer_token_get_type.c \
		src/contexts/lexer/lexer_token_new.c \
		src/contexts/lexer/lexer_try.c \
		src/contexts/lexer/lexer_try_operator.c \
		src/contexts/mini/mini_alloc.c \
		src/contexts/mini/mini_assert.c \
		src/contexts/mini/mini_create.c \
		src/contexts/mini/mini_evaluate.c \
		src/contexts/mini/mini_execute.c \
		src/contexts/mini/mini_expand.c \
		src/contexts/mini/mini_free.c \
		src/contexts/mini/mini_get_cwd.c \
		src/contexts/mini/mini_is_statement_complete.c \
		src/contexts/mini/mini_parse.c \
		src/contexts/mini/mini_quit.c \
		src/contexts/mini/mini_read.c \
		src/contexts/mini/mini_tokenize.c \
		src/contexts/parser/parser_create.c \
		src/cstring/cstring_copy.c \
		src/cstring/cstring_dirname.c \
		src/cstring/cstring_get_length.c \
		src/cstring/cstring_is_not_empty.c \
		src/cstring/cstring_join.c \
		src/cstring/cstring_to_stderr.c \
		src/cstring/cstring_to_stdout.c \
		src/linked_list/linked_list_append.c \
		src/linked_list/linked_list_destroy.c \
		src/linked_list/linked_list_new.c \
		src/linked_list/linked_list_node_destroy.c \
		src/linked_list/linked_list_node_new.c \
		src/lua/lua_loadfile.c \
		src/memory_stack/memstack_create.c \
		src/memory_stack/memstack_destroy.c \
		src/memory_stack/memstack_load.c \
		src/memory_stack/memstack_load_any.c \
		src/memory_stack/memstack_load_i32.c \
		src/memory_stack/memstack_load_i64.c \
		src/memory_stack/memstack_load_i8.c \
		src/memory_stack/memstack_load_u32.c \
		src/memory_stack/memstack_load_u64.c \
		src/memory_stack/memstack_load_u8.c \
		src/memory_stack/memstack_unload_any.c \
		src/memory_stack/memstack_unload_i32.c \
		src/memory_stack/memstack_unload_i64.c \
		src/memory_stack/memstack_unload_i8.c \
		src/memory_stack/memstack_unload_u32.c \
		src/memory_stack/memstack_unload_u64.c \
		src/memory_stack/memstack_unload_u8.c \
		src/memory_tree/memtree_create.c \
		src/memory_tree/memtree_destroy.c \
		src/memory_tree/memtree_get_height.c \
		src/memory_tree/memtree_insert.c \
		src/memory_tree/memtree_rebalance.c \
		src/memory_tree/memtree_remove.c \
		src/memory_tree/memtree_update_height.c

minishell_objects = 	src/main.o \
		src/contexts/config/config_create.o \
		src/contexts/config/config_create_lua_state.o \
		src/contexts/config/config_destroy_lua_state.o \
		src/contexts/config/config_get_path.o \
		src/contexts/config/config_get_prompt.o \
		src/contexts/input/input_create.o \
		src/contexts/input/input_get_prompt.o \
		src/contexts/lexer/lexer_add_character.o \
		src/contexts/lexer/lexer_create.o \
		src/contexts/lexer/lexer_delimit.o \
		src/contexts/lexer/lexer_discard_character.o \
		src/contexts/lexer/lexer_eighth_rule.o \
		src/contexts/lexer/lexer_fifth_rule.o \
		src/contexts/lexer/lexer_first_rule.o \
		src/contexts/lexer/lexer_fourth_rule.o \
		src/contexts/lexer/lexer_heredoc.o \
		src/contexts/lexer/lexer_ninth_rule.o \
		src/contexts/lexer/lexer_ordinary.o \
		src/contexts/lexer/lexer_reset.o \
		src/contexts/lexer/lexer_second_rule.o \
		src/contexts/lexer/lexer_seventh_rule.o \
		src/contexts/lexer/lexer_sixth_rule.o \
		src/contexts/lexer/lexer_tenth_rule.o \
		src/contexts/lexer/lexer_third_rule.o \
		src/contexts/lexer/lexer_token_get_type.o \
		src/contexts/lexer/lexer_token_new.o \
		src/contexts/lexer/lexer_try.o \
		src/contexts/lexer/lexer_try_operator.o \
		src/contexts/mini/mini_alloc.o \
		src/contexts/mini/mini_assert.o \
		src/contexts/mini/mini_create.o \
		src/contexts/mini/mini_evaluate.o \
		src/contexts/mini/mini_execute.o \
		src/contexts/mini/mini_expand.o \
		src/contexts/mini/mini_free.o \
		src/contexts/mini/mini_get_cwd.o \
		src/contexts/mini/mini_is_statement_complete.o \
		src/contexts/mini/mini_parse.o \
		src/contexts/mini/mini_quit.o \
		src/contexts/mini/mini_read.o \
		src/contexts/mini/mini_tokenize.o \
		src/contexts/parser/parser_create.o \
		src/cstring/cstring_copy.o \
		src/cstring/cstring_dirname.o \
		src/cstring/cstring_get_length.o \
		src/cstring/cstring_is_not_empty.o \
		src/cstring/cstring_join.o \
		src/cstring/cstring_to_stderr.o \
		src/cstring/cstring_to_stdout.o \
		src/linked_list/linked_list_append.o \
		src/linked_list/linked_list_destroy.o \
		src/linked_list/linked_list_new.o \
		src/linked_list/linked_list_node_destroy.o \
		src/linked_list/linked_list_node_new.o \
		src/lua/lua_loadfile.o \
		src/memory_stack/memstack_create.o \
		src/memory_stack/memstack_destroy.o \
		src/memory_stack/memstack_load.o \
		src/memory_stack/memstack_load_any.o \
		src/memory_stack/memstack_load_i32.o \
		src/memory_stack/memstack_load_i64.o \
		src/memory_stack/memstack_load_i8.o \
		src/memory_stack/memstack_load_u32.o \
		src/memory_stack/memstack_load_u64.o \
		src/memory_stack/memstack_load_u8.o \
		src/memory_stack/memstack_unload_any.o \
		src/memory_stack/memstack_unload_i32.o \
		src/memory_stack/memstack_unload_i64.o \
		src/memory_stack/memstack_unload_i8.o \
		src/memory_stack/memstack_unload_u32.o \
		src/memory_stack/memstack_unload_u64.o \
		src/memory_stack/memstack_unload_u8.o \
		src/memory_tree/memtree_create.o \
		src/memory_tree/memtree_destroy.o \
		src/memory_tree/memtree_get_height.o \
		src/memory_tree/memtree_insert.o \
		src/memory_tree/memtree_rebalance.o \
		src/memory_tree/memtree_remove.o \
		src/memory_tree/memtree_update_height.o

minishell_headers = 	include/any.h \
		include/binary_tree.h \
		include/bool.h \
		include/cstring.h \
		include/function.h \
		include/hash_table.h \
		include/i32.h \
		include/i64.h \
		include/i8.h \
		include/linked_list.h \
		include/lua.h \
		include/memory.h \
		include/memory_stack.h \
		include/memory_tree.h \
		include/none.h \
		include/stack.h \
		include/string.h \
		include/u32.h \
		include/u64.h \
		include/u8.h \
		include/config.h \
		include/input.h \
		include/lab.h \
		include/lexer.h \
		include/mini.h \
		include/parser.h

minishell_depends = 	src/main.d \
		src/contexts/config/config_create.d \
		src/contexts/config/config_create_lua_state.d \
		src/contexts/config/config_destroy_lua_state.d \
		src/contexts/config/config_get_path.d \
		src/contexts/config/config_get_prompt.d \
		src/contexts/input/input_create.d \
		src/contexts/input/input_get_prompt.d \
		src/contexts/lexer/lexer_add_character.d \
		src/contexts/lexer/lexer_create.d \
		src/contexts/lexer/lexer_delimit.d \
		src/contexts/lexer/lexer_discard_character.d \
		src/contexts/lexer/lexer_eighth_rule.d \
		src/contexts/lexer/lexer_fifth_rule.d \
		src/contexts/lexer/lexer_first_rule.d \
		src/contexts/lexer/lexer_fourth_rule.d \
		src/contexts/lexer/lexer_heredoc.d \
		src/contexts/lexer/lexer_ninth_rule.d \
		src/contexts/lexer/lexer_ordinary.d \
		src/contexts/lexer/lexer_reset.d \
		src/contexts/lexer/lexer_second_rule.d \
		src/contexts/lexer/lexer_seventh_rule.d \
		src/contexts/lexer/lexer_sixth_rule.d \
		src/contexts/lexer/lexer_tenth_rule.d \
		src/contexts/lexer/lexer_third_rule.d \
		src/contexts/lexer/lexer_token_get_type.d \
		src/contexts/lexer/lexer_token_new.d \
		src/contexts/lexer/lexer_try.d \
		src/contexts/lexer/lexer_try_operator.d \
		src/contexts/mini/mini_alloc.d \
		src/contexts/mini/mini_assert.d \
		src/contexts/mini/mini_create.d \
		src/contexts/mini/mini_evaluate.d \
		src/contexts/mini/mini_execute.d \
		src/contexts/mini/mini_expand.d \
		src/contexts/mini/mini_free.d \
		src/contexts/mini/mini_get_cwd.d \
		src/contexts/mini/mini_is_statement_complete.d \
		src/contexts/mini/mini_parse.d \
		src/contexts/mini/mini_quit.d \
		src/contexts/mini/mini_read.d \
		src/contexts/mini/mini_tokenize.d \
		src/contexts/parser/parser_create.d \
		src/cstring/cstring_copy.d \
		src/cstring/cstring_dirname.d \
		src/cstring/cstring_get_length.d \
		src/cstring/cstring_is_not_empty.d \
		src/cstring/cstring_join.d \
		src/cstring/cstring_to_stderr.d \
		src/cstring/cstring_to_stdout.d \
		src/linked_list/linked_list_append.d \
		src/linked_list/linked_list_destroy.d \
		src/linked_list/linked_list_new.d \
		src/linked_list/linked_list_node_destroy.d \
		src/linked_list/linked_list_node_new.d \
		src/lua/lua_loadfile.d \
		src/memory_stack/memstack_create.d \
		src/memory_stack/memstack_destroy.d \
		src/memory_stack/memstack_load.d \
		src/memory_stack/memstack_load_any.d \
		src/memory_stack/memstack_load_i32.d \
		src/memory_stack/memstack_load_i64.d \
		src/memory_stack/memstack_load_i8.d \
		src/memory_stack/memstack_load_u32.d \
		src/memory_stack/memstack_load_u64.d \
		src/memory_stack/memstack_load_u8.d \
		src/memory_stack/memstack_unload_any.d \
		src/memory_stack/memstack_unload_i32.d \
		src/memory_stack/memstack_unload_i64.d \
		src/memory_stack/memstack_unload_i8.d \
		src/memory_stack/memstack_unload_u32.d \
		src/memory_stack/memstack_unload_u64.d \
		src/memory_stack/memstack_unload_u8.d \
		src/memory_tree/memtree_create.d \
		src/memory_tree/memtree_destroy.d \
		src/memory_tree/memtree_get_height.d \
		src/memory_tree/memtree_insert.d \
		src/memory_tree/memtree_rebalance.d \
		src/memory_tree/memtree_remove.d \
		src/memory_tree/memtree_update_height.d

minishell_includes = 	-iquote include

all:
	@./script/generate_makefile > /dev/null 2>&1
	@$(MAKE) --no-print-directory $(NAME) 2>&1

$(NAME): $(minishell_objects)
	$(CC) $(CFLAGS) $(minishell_objects) $(minishell_includes) -o $(NAME) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) $(minishell_includes) -c $< -o $@

clean:
	$(RM) $(minishell_objects) $(minishell_depends)

fclean: clean
	$(RM) $(NAME)

re: fclean all

norm: 
	@norminette -R CheckForbiddenSourceHeader

val:
	valgrind --leak-check=full --trace-children=yes --show-leak-kinds=all --suppressions=readline.supp ./$(NAME)

run: all
	@./minishell

make:
	@./script/generate_makefile > /dev/null 2>&1

-include $(minishell_depends)

.PHONY: all clean fclean re norm val run make