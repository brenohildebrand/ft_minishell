# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/07 01:19:53 by bhildebr          #+#    #+#              #
#    Updated: 2024/06/07 01:19:53 by bhildebr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -MMD -MP
LIBS = -lreadline -llua5.4

minishell_sources = 	src/main.c \
		src/mini/mini_alloc.c \
		src/mini/mini_assert.c \
		src/mini/mini_create.c \
		src/mini/mini_eval.c \
		src/mini/mini_expand.c \
		src/mini/mini_free.c \
		src/mini/mini_get_cwd.c \
		src/mini/mini_is_statement_complete.c \
		src/mini/mini_parse.c \
		src/mini/mini_quit.c \
		src/mini/mini_read.c \
		src/mini/mini_tokenize.c \
		src/mini/compounds/mini_list/mini_list_append.c \
		src/mini/compounds/mini_list/mini_list_clear.c \
		src/mini/contexts/config/mini_config_create.c \
		src/mini/contexts/config/mini_config_create_lua_state.c \
		src/mini/contexts/config/mini_config_create_multiline_prompt.c \
		src/mini/contexts/config/mini_config_create_path.c \
		src/mini/contexts/config/mini_config_create_prompt.c \
		src/mini/contexts/config/mini_config_destroy_lua_state.c \
		src/mini/contexts/shared/mini_shared_create.c \
		src/mini/primitives/cstring/cstring_get_length.c \
		src/mini/primitives/cstring/cstring_is_not_empty.c \
		src/mini/primitives/cstring/cstring_to_stderr.c \
		src/mini/primitives/cstring/cstring_to_stdout.c \
		src/mini/primitives/cstring/mini_cstring_copy.c \
		src/mini/primitives/cstring/mini_cstring_dirname.c \
		src/mini/primitives/cstring/mini_cstring_get_subcstring.c \
		src/mini/primitives/cstring/mini_cstring_join.c \
		src/mini/primitives/i32/i32_to_cstring.c \
		src/mini/primitives/i8/i8_is_whitespace.c \
		src/mini/primitives/memory/mem_copy_from_to.c \
		src/mini/primitives/memory/mini_mem_sub.c \
		src/mini/processes/eval/mini_eval_create.c \
		src/mini/processes/expansion/mini_expansion_create.c \
		src/mini/processes/expansion/mini_expansion_expand_dquotes.c \
		src/mini/processes/expansion/mini_expansion_expand_word.c \
		src/mini/processes/lexer/mini_lexer_automaton.c \
		src/mini/processes/lexer/mini_lexer_automaton_delimit.c \
		src/mini/processes/lexer/mini_lexer_automaton_init.c \
		src/mini/processes/lexer/mini_lexer_automaton_is_end_of_statement.c \
		src/mini/processes/lexer/mini_lexer_automaton_is_final_state.c \
		src/mini/processes/lexer/mini_lexer_automaton_is_whitespace.c \
		src/mini/processes/lexer/mini_lexer_automaton_next_state.c \
		src/mini/processes/lexer/mini_lexer_automaton_typefy.c \
		src/mini/processes/lexer/mini_lexer_create.c \
		src/mini/processes/lexer/mini_lexer_heredoc.c \
		src/mini/processes/lexer/mini_lexer_ordinary.c \
		src/mini/processes/lexer/mini_lexer_update_mode.c \
		src/mini/processes/parser/mini_parser_create.c \
		src/mini/processes/parser/mini_parse_pipe_sequence.c \
		src/mini/processes/reader/mini_reader_create.c \
		src/mini/processes/reader/mini_reader_create_multiline_prompt.c \
		src/mini/processes/reader/mini_reader_create_prompt.c \
		src/mini/systems/memstack/memstack_create.c \
		src/mini/systems/memstack/memstack_destroy.c \
		src/mini/systems/memstack/memstack_load.c \
		src/mini/systems/memstack/memstack_load_any.c \
		src/mini/systems/memstack/memstack_load_i32.c \
		src/mini/systems/memstack/memstack_load_i64.c \
		src/mini/systems/memstack/memstack_load_i8.c \
		src/mini/systems/memstack/memstack_load_u32.c \
		src/mini/systems/memstack/memstack_load_u64.c \
		src/mini/systems/memstack/memstack_load_u8.c \
		src/mini/systems/memstack/memstack_unload_any.c \
		src/mini/systems/memstack/memstack_unload_i32.c \
		src/mini/systems/memstack/memstack_unload_i64.c \
		src/mini/systems/memstack/memstack_unload_i8.c \
		src/mini/systems/memstack/memstack_unload_u32.c \
		src/mini/systems/memstack/memstack_unload_u64.c \
		src/mini/systems/memstack/memstack_unload_u8.c \
		src/mini/systems/memtree/memtree_create.c \
		src/mini/systems/memtree/memtree_destroy.c \
		src/mini/systems/memtree/memtree_get_height.c \
		src/mini/systems/memtree/memtree_insert.c \
		src/mini/systems/memtree/memtree_rebalance.c \
		src/mini/systems/memtree/memtree_remove.c \
		src/mini/systems/memtree/memtree_update_height.c

minishell_objects = 	src/main.o \
		src/mini/mini_alloc.o \
		src/mini/mini_assert.o \
		src/mini/mini_create.o \
		src/mini/mini_eval.o \
		src/mini/mini_expand.o \
		src/mini/mini_free.o \
		src/mini/mini_get_cwd.o \
		src/mini/mini_is_statement_complete.o \
		src/mini/mini_parse.o \
		src/mini/mini_quit.o \
		src/mini/mini_read.o \
		src/mini/mini_tokenize.o \
		src/mini/compounds/mini_list/mini_list_append.o \
		src/mini/compounds/mini_list/mini_list_clear.o \
		src/mini/contexts/config/mini_config_create.o \
		src/mini/contexts/config/mini_config_create_lua_state.o \
		src/mini/contexts/config/mini_config_create_multiline_prompt.o \
		src/mini/contexts/config/mini_config_create_path.o \
		src/mini/contexts/config/mini_config_create_prompt.o \
		src/mini/contexts/config/mini_config_destroy_lua_state.o \
		src/mini/contexts/shared/mini_shared_create.o \
		src/mini/primitives/cstring/cstring_get_length.o \
		src/mini/primitives/cstring/cstring_is_not_empty.o \
		src/mini/primitives/cstring/cstring_to_stderr.o \
		src/mini/primitives/cstring/cstring_to_stdout.o \
		src/mini/primitives/cstring/mini_cstring_copy.o \
		src/mini/primitives/cstring/mini_cstring_dirname.o \
		src/mini/primitives/cstring/mini_cstring_get_subcstring.o \
		src/mini/primitives/cstring/mini_cstring_join.o \
		src/mini/primitives/i32/i32_to_cstring.o \
		src/mini/primitives/i8/i8_is_whitespace.o \
		src/mini/primitives/memory/mem_copy_from_to.o \
		src/mini/primitives/memory/mini_mem_sub.o \
		src/mini/processes/eval/mini_eval_create.o \
		src/mini/processes/expansion/mini_expansion_create.o \
		src/mini/processes/expansion/mini_expansion_expand_dquotes.o \
		src/mini/processes/expansion/mini_expansion_expand_word.o \
		src/mini/processes/lexer/mini_lexer_automaton.o \
		src/mini/processes/lexer/mini_lexer_automaton_delimit.o \
		src/mini/processes/lexer/mini_lexer_automaton_init.o \
		src/mini/processes/lexer/mini_lexer_automaton_is_end_of_statement.o \
		src/mini/processes/lexer/mini_lexer_automaton_is_final_state.o \
		src/mini/processes/lexer/mini_lexer_automaton_is_whitespace.o \
		src/mini/processes/lexer/mini_lexer_automaton_next_state.o \
		src/mini/processes/lexer/mini_lexer_automaton_typefy.o \
		src/mini/processes/lexer/mini_lexer_create.o \
		src/mini/processes/lexer/mini_lexer_heredoc.o \
		src/mini/processes/lexer/mini_lexer_ordinary.o \
		src/mini/processes/lexer/mini_lexer_update_mode.o \
		src/mini/processes/parser/mini_parser_create.o \
		src/mini/processes/parser/mini_parse_pipe_sequence.o \
		src/mini/processes/reader/mini_reader_create.o \
		src/mini/processes/reader/mini_reader_create_multiline_prompt.o \
		src/mini/processes/reader/mini_reader_create_prompt.o \
		src/mini/systems/memstack/memstack_create.o \
		src/mini/systems/memstack/memstack_destroy.o \
		src/mini/systems/memstack/memstack_load.o \
		src/mini/systems/memstack/memstack_load_any.o \
		src/mini/systems/memstack/memstack_load_i32.o \
		src/mini/systems/memstack/memstack_load_i64.o \
		src/mini/systems/memstack/memstack_load_i8.o \
		src/mini/systems/memstack/memstack_load_u32.o \
		src/mini/systems/memstack/memstack_load_u64.o \
		src/mini/systems/memstack/memstack_load_u8.o \
		src/mini/systems/memstack/memstack_unload_any.o \
		src/mini/systems/memstack/memstack_unload_i32.o \
		src/mini/systems/memstack/memstack_unload_i64.o \
		src/mini/systems/memstack/memstack_unload_i8.o \
		src/mini/systems/memstack/memstack_unload_u32.o \
		src/mini/systems/memstack/memstack_unload_u64.o \
		src/mini/systems/memstack/memstack_unload_u8.o \
		src/mini/systems/memtree/memtree_create.o \
		src/mini/systems/memtree/memtree_destroy.o \
		src/mini/systems/memtree/memtree_get_height.o \
		src/mini/systems/memtree/memtree_insert.o \
		src/mini/systems/memtree/memtree_rebalance.o \
		src/mini/systems/memtree/memtree_remove.o \
		src/mini/systems/memtree/memtree_update_height.o

minishell_headers = 	include/minishell.h \
		include/mini_list.h \
		include/mini_tree.h \
		include/config.h \
		include/shared.h \
		include/any.h \
		include/bool.h \
		include/cstring.h \
		include/i32.h \
		include/i64.h \
		include/i8.h \
		include/memory.h \
		include/none.h \
		include/u32.h \
		include/u64.h \
		include/u8.h \
		include/eval.h \
		include/expansion.h \
		include/lexer.h \
		include/parser.h \
		include/reader.h \
		include/memstack.h \
		include/memtree.h

minishell_depends = 	src/main.d \
		src/mini/mini_alloc.d \
		src/mini/mini_assert.d \
		src/mini/mini_create.d \
		src/mini/mini_eval.d \
		src/mini/mini_expand.d \
		src/mini/mini_free.d \
		src/mini/mini_get_cwd.d \
		src/mini/mini_is_statement_complete.d \
		src/mini/mini_parse.d \
		src/mini/mini_quit.d \
		src/mini/mini_read.d \
		src/mini/mini_tokenize.d \
		src/mini/compounds/mini_list/mini_list_append.d \
		src/mini/compounds/mini_list/mini_list_clear.d \
		src/mini/contexts/config/mini_config_create.d \
		src/mini/contexts/config/mini_config_create_lua_state.d \
		src/mini/contexts/config/mini_config_create_multiline_prompt.d \
		src/mini/contexts/config/mini_config_create_path.d \
		src/mini/contexts/config/mini_config_create_prompt.d \
		src/mini/contexts/config/mini_config_destroy_lua_state.d \
		src/mini/contexts/shared/mini_shared_create.d \
		src/mini/primitives/cstring/cstring_get_length.d \
		src/mini/primitives/cstring/cstring_is_not_empty.d \
		src/mini/primitives/cstring/cstring_to_stderr.d \
		src/mini/primitives/cstring/cstring_to_stdout.d \
		src/mini/primitives/cstring/mini_cstring_copy.d \
		src/mini/primitives/cstring/mini_cstring_dirname.d \
		src/mini/primitives/cstring/mini_cstring_get_subcstring.d \
		src/mini/primitives/cstring/mini_cstring_join.d \
		src/mini/primitives/i32/i32_to_cstring.d \
		src/mini/primitives/i8/i8_is_whitespace.d \
		src/mini/primitives/memory/mem_copy_from_to.d \
		src/mini/primitives/memory/mini_mem_sub.d \
		src/mini/processes/eval/mini_eval_create.d \
		src/mini/processes/expansion/mini_expansion_create.d \
		src/mini/processes/expansion/mini_expansion_expand_dquotes.d \
		src/mini/processes/expansion/mini_expansion_expand_word.d \
		src/mini/processes/lexer/mini_lexer_automaton.d \
		src/mini/processes/lexer/mini_lexer_automaton_delimit.d \
		src/mini/processes/lexer/mini_lexer_automaton_init.d \
		src/mini/processes/lexer/mini_lexer_automaton_is_end_of_statement.d \
		src/mini/processes/lexer/mini_lexer_automaton_is_final_state.d \
		src/mini/processes/lexer/mini_lexer_automaton_is_whitespace.d \
		src/mini/processes/lexer/mini_lexer_automaton_next_state.d \
		src/mini/processes/lexer/mini_lexer_automaton_typefy.d \
		src/mini/processes/lexer/mini_lexer_create.d \
		src/mini/processes/lexer/mini_lexer_heredoc.d \
		src/mini/processes/lexer/mini_lexer_ordinary.d \
		src/mini/processes/lexer/mini_lexer_update_mode.d \
		src/mini/processes/parser/mini_parser_create.d \
		src/mini/processes/parser/mini_parse_pipe_sequence.d \
		src/mini/processes/reader/mini_reader_create.d \
		src/mini/processes/reader/mini_reader_create_multiline_prompt.d \
		src/mini/processes/reader/mini_reader_create_prompt.d \
		src/mini/systems/memstack/memstack_create.d \
		src/mini/systems/memstack/memstack_destroy.d \
		src/mini/systems/memstack/memstack_load.d \
		src/mini/systems/memstack/memstack_load_any.d \
		src/mini/systems/memstack/memstack_load_i32.d \
		src/mini/systems/memstack/memstack_load_i64.d \
		src/mini/systems/memstack/memstack_load_i8.d \
		src/mini/systems/memstack/memstack_load_u32.d \
		src/mini/systems/memstack/memstack_load_u64.d \
		src/mini/systems/memstack/memstack_load_u8.d \
		src/mini/systems/memstack/memstack_unload_any.d \
		src/mini/systems/memstack/memstack_unload_i32.d \
		src/mini/systems/memstack/memstack_unload_i64.d \
		src/mini/systems/memstack/memstack_unload_i8.d \
		src/mini/systems/memstack/memstack_unload_u32.d \
		src/mini/systems/memstack/memstack_unload_u64.d \
		src/mini/systems/memstack/memstack_unload_u8.d \
		src/mini/systems/memtree/memtree_create.d \
		src/mini/systems/memtree/memtree_destroy.d \
		src/mini/systems/memtree/memtree_get_height.d \
		src/mini/systems/memtree/memtree_insert.d \
		src/mini/systems/memtree/memtree_rebalance.d \
		src/mini/systems/memtree/memtree_remove.d \
		src/mini/systems/memtree/memtree_update_height.d

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