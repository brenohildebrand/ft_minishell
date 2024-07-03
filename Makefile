# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/02 20:18:31 by bhildebr          #+#    #+#              #
#    Updated: 2024/07/02 20:18:31 by bhildebr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -MMD -MP
LIBS = -lreadline -llua5.4

minishell_sources = 	src/main.c \
		src/mini/mini_alloc.c \
		src/mini/mini_assert.c \
		src/mini/mini_close.c \
		src/mini/mini_create.c \
		src/mini/mini_eval.c \
		src/mini/mini_free.c \
		src/mini/mini_get_cwd.c \
		src/mini/mini_is_complete.c \
		src/mini/mini_is_statement_complete.c \
		src/mini/mini_open.c \
		src/mini/mini_parse.c \
		src/mini/mini_quit.c \
		src/mini/mini_reset.c \
		src/mini/compounds/mini_list/mini_list_append.c \
		src/mini/compounds/mini_list/mini_list_clear.c \
		src/mini/compounds/mini_list/mini_list_destroy.c \
		src/mini/compounds/mini_list/mini_list_print.c \
		src/mini/compounds/mini_tree/mini_cmd_tree_create.c \
		src/mini/compounds/mini_tree/mini_cmd_tree_destroy.c \
		src/mini/compounds/mini_tree/mini_cmd_tree_list_append.c \
		src/mini/compounds/mini_tree/mini_cmd_tree_list_create.c \
		src/mini/compounds/mini_tree/mini_cmd_tree_list_destroy.c \
		src/mini/compounds/mini_tree/mini_cmd_tree_list_realloc.c \
		src/mini/compounds/mini_tree/mini_pipe_tree_create.c \
		src/mini/compounds/mini_tree/mini_pipe_tree_destroy.c \
		src/mini/compounds/mini_tree/mini_pipe_tree_print.c \
		src/mini/contexts/shared/shared_create.c \
		src/mini/contexts/signals/signals_create.c \
		src/mini/contexts/signals/signals_handler.c \
		src/mini/contexts/signals/signals_sigint_handler.c \
		src/mini/contexts/signals/signals_sigquit_handler.c \
		src/mini/primitives/cstring/cstring_add.c \
		src/mini/primitives/cstring/cstring_array_copy.c \
		src/mini/primitives/cstring/cstring_compare.c \
		src/mini/primitives/cstring/cstring_copy.c \
		src/mini/primitives/cstring/cstring_dirname.c \
		src/mini/primitives/cstring/cstring_get_length.c \
		src/mini/primitives/cstring/cstring_get_subcstring.c \
		src/mini/primitives/cstring/cstring_is_not_empty.c \
		src/mini/primitives/cstring/cstring_join.c \
		src/mini/primitives/cstring/cstring_remove.c \
		src/mini/primitives/cstring/cstring_split.c \
		src/mini/primitives/cstring/cstring_to_stderr.c \
		src/mini/primitives/cstring/cstring_to_stdout.c \
		src/mini/primitives/i32/i32_to_cstring.c \
		src/mini/primitives/i8/i8_is_whitespace.c \
		src/mini/primitives/memory/mem_copy_from_to.c \
		src/mini/primitives/memory/mem_set.c \
		src/mini/primitives/memory/mem_sub.c \
		src/mini/primitives/u8/u8_to_cstring.c \
		src/mini/processes/eval/eval_builtin.c \
		src/mini/processes/eval/eval_cd.c \
		src/mini/processes/eval/eval_close_pipes.c \
		src/mini/processes/eval/eval_close_redirs.c \
		src/mini/processes/eval/eval_command.c \
		src/mini/processes/eval/eval_commands.c \
		src/mini/processes/eval/eval_create.c \
		src/mini/processes/eval/eval_create_pipes.c \
		src/mini/processes/eval/eval_echo.c \
		src/mini/processes/eval/eval_env.c \
		src/mini/processes/eval/eval_executable.c \
		src/mini/processes/eval/eval_exit.c \
		src/mini/processes/eval/eval_export.c \
		src/mini/processes/eval/eval_is_builtin.c \
		src/mini/processes/eval/eval_is_corner_case.c \
		src/mini/processes/eval/eval_pipe.c \
		src/mini/processes/eval/eval_pwd.c \
		src/mini/processes/eval/eval_redirs.c \
		src/mini/processes/eval/eval_reset.c \
		src/mini/processes/eval/eval_unset.c \
		src/mini/processes/eval/eval_update_exit_code.c \
		src/mini/processes/eval/eval_update_path.c \
		src/mini/processes/eval/eval_words.c \
		src/mini/processes/eval/export_env_val.c \
		src/mini/processes/expansion/expansion_create.c \
		src/mini/processes/expansion/expansion_expand.c \
		src/mini/processes/expansion/expansion_expand_dquotes.c \
		src/mini/processes/expansion/expansion_expand_word.c \
		src/mini/processes/expansion/expansion_getenv.c \
		src/mini/processes/expansion/expansion_remove_quotes.c \
		src/mini/processes/expansion/expansion_reset.c \
		src/mini/processes/expansion/mini_expand.c \
		src/mini/processes/heredoc/heredoc_create.c \
		src/mini/processes/heredoc/heredoc_read.c \
		src/mini/processes/heredoc/heredoc_reset.c \
		src/mini/processes/heredoc/heredoc_update_tree.c \
		src/mini/processes/heredoc/heredoc_write.c \
		src/mini/processes/heredoc/mini_handle_heredoc.c \
		src/mini/processes/lexer/lexer_automaton.c \
		src/mini/processes/lexer/lexer_automaton_delimit.c \
		src/mini/processes/lexer/lexer_automaton_init.c \
		src/mini/processes/lexer/lexer_automaton_is_end_of_statement.c \
		src/mini/processes/lexer/lexer_automaton_is_final_state.c \
		src/mini/processes/lexer/lexer_automaton_is_whitespace.c \
		src/mini/processes/lexer/lexer_automaton_next_state.c \
		src/mini/processes/lexer/lexer_automaton_typefy.c \
		src/mini/processes/lexer/lexer_create.c \
		src/mini/processes/lexer/lexer_debug.c \
		src/mini/processes/lexer/lexer_reset.c \
		src/mini/processes/lexer/mini_tokenize.c \
		src/mini/processes/parser/parser_create.c \
		src/mini/processes/parser/parser_get_token.c \
		src/mini/processes/parser/parser_is_end.c \
		src/mini/processes/parser/parser_is_pipe.c \
		src/mini/processes/parser/parser_is_redir.c \
		src/mini/processes/parser/parser_is_word.c \
		src/mini/processes/parser/parser_next_token.c \
		src/mini/processes/parser/parser_print_syntax_error.c \
		src/mini/processes/parser/parser_reset.c \
		src/mini/processes/parser/parser_set_syntax_error.c \
		src/mini/processes/parser/parse_command.c \
		src/mini/processes/parser/parse_pipe_sequence.c \
		src/mini/processes/reader/mini_read.c \
		src/mini/processes/reader/reader_assume_statement_is_complete.c \
		src/mini/processes/reader/reader_create.c \
		src/mini/processes/reader/reader_create_multiline_prompt.c \
		src/mini/processes/reader/reader_create_prompt.c \
		src/mini/processes/reader/reader_debug.c \
		src/mini/processes/reader/reader_readline.c \
		src/mini/processes/reader/reader_reset.c \
		src/mini/processes/reader/reader_update_statement.c \
		src/mini/systems/fdtree/fdtree_create.c \
		src/mini/systems/fdtree/fdtree_destroy.c \
		src/mini/systems/fdtree/fdtree_get_height.c \
		src/mini/systems/fdtree/fdtree_insert.c \
		src/mini/systems/fdtree/fdtree_rebalance.c \
		src/mini/systems/fdtree/fdtree_remove.c \
		src/mini/systems/fdtree/fdtree_update_height.c \
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
		src/mini/systems/memtree/memtree_update_height.c \
		src/mini/utils_ft/utils_lib_ft.c \
		src/mini/utils_ft/utils_lib_ft_2.c \
		src/mini/utils_ft/utils_lib_ft_3.c

minishell_objects = 	src/main.o \
		src/mini/mini_alloc.o \
		src/mini/mini_assert.o \
		src/mini/mini_close.o \
		src/mini/mini_create.o \
		src/mini/mini_eval.o \
		src/mini/mini_free.o \
		src/mini/mini_get_cwd.o \
		src/mini/mini_is_complete.o \
		src/mini/mini_is_statement_complete.o \
		src/mini/mini_open.o \
		src/mini/mini_parse.o \
		src/mini/mini_quit.o \
		src/mini/mini_reset.o \
		src/mini/compounds/mini_list/mini_list_append.o \
		src/mini/compounds/mini_list/mini_list_clear.o \
		src/mini/compounds/mini_list/mini_list_destroy.o \
		src/mini/compounds/mini_list/mini_list_print.o \
		src/mini/compounds/mini_tree/mini_cmd_tree_create.o \
		src/mini/compounds/mini_tree/mini_cmd_tree_destroy.o \
		src/mini/compounds/mini_tree/mini_cmd_tree_list_append.o \
		src/mini/compounds/mini_tree/mini_cmd_tree_list_create.o \
		src/mini/compounds/mini_tree/mini_cmd_tree_list_destroy.o \
		src/mini/compounds/mini_tree/mini_cmd_tree_list_realloc.o \
		src/mini/compounds/mini_tree/mini_pipe_tree_create.o \
		src/mini/compounds/mini_tree/mini_pipe_tree_destroy.o \
		src/mini/compounds/mini_tree/mini_pipe_tree_print.o \
		src/mini/contexts/shared/shared_create.o \
		src/mini/contexts/signals/signals_create.o \
		src/mini/contexts/signals/signals_handler.o \
		src/mini/contexts/signals/signals_sigint_handler.o \
		src/mini/contexts/signals/signals_sigquit_handler.o \
		src/mini/primitives/cstring/cstring_add.o \
		src/mini/primitives/cstring/cstring_array_copy.o \
		src/mini/primitives/cstring/cstring_compare.o \
		src/mini/primitives/cstring/cstring_copy.o \
		src/mini/primitives/cstring/cstring_dirname.o \
		src/mini/primitives/cstring/cstring_get_length.o \
		src/mini/primitives/cstring/cstring_get_subcstring.o \
		src/mini/primitives/cstring/cstring_is_not_empty.o \
		src/mini/primitives/cstring/cstring_join.o \
		src/mini/primitives/cstring/cstring_remove.o \
		src/mini/primitives/cstring/cstring_split.o \
		src/mini/primitives/cstring/cstring_to_stderr.o \
		src/mini/primitives/cstring/cstring_to_stdout.o \
		src/mini/primitives/i32/i32_to_cstring.o \
		src/mini/primitives/i8/i8_is_whitespace.o \
		src/mini/primitives/memory/mem_copy_from_to.o \
		src/mini/primitives/memory/mem_set.o \
		src/mini/primitives/memory/mem_sub.o \
		src/mini/primitives/u8/u8_to_cstring.o \
		src/mini/processes/eval/eval_builtin.o \
		src/mini/processes/eval/eval_cd.o \
		src/mini/processes/eval/eval_close_pipes.o \
		src/mini/processes/eval/eval_close_redirs.o \
		src/mini/processes/eval/eval_command.o \
		src/mini/processes/eval/eval_commands.o \
		src/mini/processes/eval/eval_create.o \
		src/mini/processes/eval/eval_create_pipes.o \
		src/mini/processes/eval/eval_echo.o \
		src/mini/processes/eval/eval_env.o \
		src/mini/processes/eval/eval_executable.o \
		src/mini/processes/eval/eval_exit.o \
		src/mini/processes/eval/eval_export.o \
		src/mini/processes/eval/eval_is_builtin.o \
		src/mini/processes/eval/eval_is_corner_case.o \
		src/mini/processes/eval/eval_pipe.o \
		src/mini/processes/eval/eval_pwd.o \
		src/mini/processes/eval/eval_redirs.o \
		src/mini/processes/eval/eval_reset.o \
		src/mini/processes/eval/eval_unset.o \
		src/mini/processes/eval/eval_update_exit_code.o \
		src/mini/processes/eval/eval_update_path.o \
		src/mini/processes/eval/eval_words.o \
		src/mini/processes/eval/export_env_val.o \
		src/mini/processes/expansion/expansion_create.o \
		src/mini/processes/expansion/expansion_expand.o \
		src/mini/processes/expansion/expansion_expand_dquotes.o \
		src/mini/processes/expansion/expansion_expand_word.o \
		src/mini/processes/expansion/expansion_getenv.o \
		src/mini/processes/expansion/expansion_remove_quotes.o \
		src/mini/processes/expansion/expansion_reset.o \
		src/mini/processes/expansion/mini_expand.o \
		src/mini/processes/heredoc/heredoc_create.o \
		src/mini/processes/heredoc/heredoc_read.o \
		src/mini/processes/heredoc/heredoc_reset.o \
		src/mini/processes/heredoc/heredoc_update_tree.o \
		src/mini/processes/heredoc/heredoc_write.o \
		src/mini/processes/heredoc/mini_handle_heredoc.o \
		src/mini/processes/lexer/lexer_automaton.o \
		src/mini/processes/lexer/lexer_automaton_delimit.o \
		src/mini/processes/lexer/lexer_automaton_init.o \
		src/mini/processes/lexer/lexer_automaton_is_end_of_statement.o \
		src/mini/processes/lexer/lexer_automaton_is_final_state.o \
		src/mini/processes/lexer/lexer_automaton_is_whitespace.o \
		src/mini/processes/lexer/lexer_automaton_next_state.o \
		src/mini/processes/lexer/lexer_automaton_typefy.o \
		src/mini/processes/lexer/lexer_create.o \
		src/mini/processes/lexer/lexer_debug.o \
		src/mini/processes/lexer/lexer_reset.o \
		src/mini/processes/lexer/mini_tokenize.o \
		src/mini/processes/parser/parser_create.o \
		src/mini/processes/parser/parser_get_token.o \
		src/mini/processes/parser/parser_is_end.o \
		src/mini/processes/parser/parser_is_pipe.o \
		src/mini/processes/parser/parser_is_redir.o \
		src/mini/processes/parser/parser_is_word.o \
		src/mini/processes/parser/parser_next_token.o \
		src/mini/processes/parser/parser_print_syntax_error.o \
		src/mini/processes/parser/parser_reset.o \
		src/mini/processes/parser/parser_set_syntax_error.o \
		src/mini/processes/parser/parse_command.o \
		src/mini/processes/parser/parse_pipe_sequence.o \
		src/mini/processes/reader/mini_read.o \
		src/mini/processes/reader/reader_assume_statement_is_complete.o \
		src/mini/processes/reader/reader_create.o \
		src/mini/processes/reader/reader_create_multiline_prompt.o \
		src/mini/processes/reader/reader_create_prompt.o \
		src/mini/processes/reader/reader_debug.o \
		src/mini/processes/reader/reader_readline.o \
		src/mini/processes/reader/reader_reset.o \
		src/mini/processes/reader/reader_update_statement.o \
		src/mini/systems/fdtree/fdtree_create.o \
		src/mini/systems/fdtree/fdtree_destroy.o \
		src/mini/systems/fdtree/fdtree_get_height.o \
		src/mini/systems/fdtree/fdtree_insert.o \
		src/mini/systems/fdtree/fdtree_rebalance.o \
		src/mini/systems/fdtree/fdtree_remove.o \
		src/mini/systems/fdtree/fdtree_update_height.o \
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
		src/mini/systems/memtree/memtree_update_height.o \
		src/mini/utils_ft/utils_lib_ft.o \
		src/mini/utils_ft/utils_lib_ft_2.o \
		src/mini/utils_ft/utils_lib_ft_3.o

minishell_headers = 	include/minishell.h \
		include/mini_list.h \
		include/mini_tree.h \
		include/shared.h \
		include/signals.h \
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
		include/heredoc.h \
		include/lexer.h \
		include/parser.h \
		include/reader.h \
		include/fdtree.h \
		include/memstack.h \
		include/memtree.h

minishell_depends = 	src/main.d \
		src/mini/mini_alloc.d \
		src/mini/mini_assert.d \
		src/mini/mini_close.d \
		src/mini/mini_create.d \
		src/mini/mini_eval.d \
		src/mini/mini_free.d \
		src/mini/mini_get_cwd.d \
		src/mini/mini_is_complete.d \
		src/mini/mini_is_statement_complete.d \
		src/mini/mini_open.d \
		src/mini/mini_parse.d \
		src/mini/mini_quit.d \
		src/mini/mini_reset.d \
		src/mini/compounds/mini_list/mini_list_append.d \
		src/mini/compounds/mini_list/mini_list_clear.d \
		src/mini/compounds/mini_list/mini_list_destroy.d \
		src/mini/compounds/mini_list/mini_list_print.d \
		src/mini/compounds/mini_tree/mini_cmd_tree_create.d \
		src/mini/compounds/mini_tree/mini_cmd_tree_destroy.d \
		src/mini/compounds/mini_tree/mini_cmd_tree_list_append.d \
		src/mini/compounds/mini_tree/mini_cmd_tree_list_create.d \
		src/mini/compounds/mini_tree/mini_cmd_tree_list_destroy.d \
		src/mini/compounds/mini_tree/mini_cmd_tree_list_realloc.d \
		src/mini/compounds/mini_tree/mini_pipe_tree_create.d \
		src/mini/compounds/mini_tree/mini_pipe_tree_destroy.d \
		src/mini/compounds/mini_tree/mini_pipe_tree_print.d \
		src/mini/contexts/shared/shared_create.d \
		src/mini/contexts/signals/signals_create.d \
		src/mini/contexts/signals/signals_handler.d \
		src/mini/contexts/signals/signals_sigint_handler.d \
		src/mini/contexts/signals/signals_sigquit_handler.d \
		src/mini/primitives/cstring/cstring_add.d \
		src/mini/primitives/cstring/cstring_array_copy.d \
		src/mini/primitives/cstring/cstring_compare.d \
		src/mini/primitives/cstring/cstring_copy.d \
		src/mini/primitives/cstring/cstring_dirname.d \
		src/mini/primitives/cstring/cstring_get_length.d \
		src/mini/primitives/cstring/cstring_get_subcstring.d \
		src/mini/primitives/cstring/cstring_is_not_empty.d \
		src/mini/primitives/cstring/cstring_join.d \
		src/mini/primitives/cstring/cstring_remove.d \
		src/mini/primitives/cstring/cstring_split.d \
		src/mini/primitives/cstring/cstring_to_stderr.d \
		src/mini/primitives/cstring/cstring_to_stdout.d \
		src/mini/primitives/i32/i32_to_cstring.d \
		src/mini/primitives/i8/i8_is_whitespace.d \
		src/mini/primitives/memory/mem_copy_from_to.d \
		src/mini/primitives/memory/mem_set.d \
		src/mini/primitives/memory/mem_sub.d \
		src/mini/primitives/u8/u8_to_cstring.d \
		src/mini/processes/eval/eval_builtin.d \
		src/mini/processes/eval/eval_cd.d \
		src/mini/processes/eval/eval_close_pipes.d \
		src/mini/processes/eval/eval_close_redirs.d \
		src/mini/processes/eval/eval_command.d \
		src/mini/processes/eval/eval_commands.d \
		src/mini/processes/eval/eval_create.d \
		src/mini/processes/eval/eval_create_pipes.d \
		src/mini/processes/eval/eval_echo.d \
		src/mini/processes/eval/eval_env.d \
		src/mini/processes/eval/eval_executable.d \
		src/mini/processes/eval/eval_exit.d \
		src/mini/processes/eval/eval_export.d \
		src/mini/processes/eval/eval_is_builtin.d \
		src/mini/processes/eval/eval_is_corner_case.d \
		src/mini/processes/eval/eval_pipe.d \
		src/mini/processes/eval/eval_pwd.d \
		src/mini/processes/eval/eval_redirs.d \
		src/mini/processes/eval/eval_reset.d \
		src/mini/processes/eval/eval_unset.d \
		src/mini/processes/eval/eval_update_exit_code.d \
		src/mini/processes/eval/eval_update_path.d \
		src/mini/processes/eval/eval_words.d \
		src/mini/processes/eval/export_env_val.d \
		src/mini/processes/expansion/expansion_create.d \
		src/mini/processes/expansion/expansion_expand.d \
		src/mini/processes/expansion/expansion_expand_dquotes.d \
		src/mini/processes/expansion/expansion_expand_word.d \
		src/mini/processes/expansion/expansion_getenv.d \
		src/mini/processes/expansion/expansion_remove_quotes.d \
		src/mini/processes/expansion/expansion_reset.d \
		src/mini/processes/expansion/mini_expand.d \
		src/mini/processes/heredoc/heredoc_create.d \
		src/mini/processes/heredoc/heredoc_read.d \
		src/mini/processes/heredoc/heredoc_reset.d \
		src/mini/processes/heredoc/heredoc_update_tree.d \
		src/mini/processes/heredoc/heredoc_write.d \
		src/mini/processes/heredoc/mini_handle_heredoc.d \
		src/mini/processes/lexer/lexer_automaton.d \
		src/mini/processes/lexer/lexer_automaton_delimit.d \
		src/mini/processes/lexer/lexer_automaton_init.d \
		src/mini/processes/lexer/lexer_automaton_is_end_of_statement.d \
		src/mini/processes/lexer/lexer_automaton_is_final_state.d \
		src/mini/processes/lexer/lexer_automaton_is_whitespace.d \
		src/mini/processes/lexer/lexer_automaton_next_state.d \
		src/mini/processes/lexer/lexer_automaton_typefy.d \
		src/mini/processes/lexer/lexer_create.d \
		src/mini/processes/lexer/lexer_debug.d \
		src/mini/processes/lexer/lexer_reset.d \
		src/mini/processes/lexer/mini_tokenize.d \
		src/mini/processes/parser/parser_create.d \
		src/mini/processes/parser/parser_get_token.d \
		src/mini/processes/parser/parser_is_end.d \
		src/mini/processes/parser/parser_is_pipe.d \
		src/mini/processes/parser/parser_is_redir.d \
		src/mini/processes/parser/parser_is_word.d \
		src/mini/processes/parser/parser_next_token.d \
		src/mini/processes/parser/parser_print_syntax_error.d \
		src/mini/processes/parser/parser_reset.d \
		src/mini/processes/parser/parser_set_syntax_error.d \
		src/mini/processes/parser/parse_command.d \
		src/mini/processes/parser/parse_pipe_sequence.d \
		src/mini/processes/reader/mini_read.d \
		src/mini/processes/reader/reader_assume_statement_is_complete.d \
		src/mini/processes/reader/reader_create.d \
		src/mini/processes/reader/reader_create_multiline_prompt.d \
		src/mini/processes/reader/reader_create_prompt.d \
		src/mini/processes/reader/reader_debug.d \
		src/mini/processes/reader/reader_readline.d \
		src/mini/processes/reader/reader_reset.d \
		src/mini/processes/reader/reader_update_statement.d \
		src/mini/systems/fdtree/fdtree_create.d \
		src/mini/systems/fdtree/fdtree_destroy.d \
		src/mini/systems/fdtree/fdtree_get_height.d \
		src/mini/systems/fdtree/fdtree_insert.d \
		src/mini/systems/fdtree/fdtree_rebalance.d \
		src/mini/systems/fdtree/fdtree_remove.d \
		src/mini/systems/fdtree/fdtree_update_height.d \
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
		src/mini/systems/memtree/memtree_update_height.d \
		src/mini/utils_ft/utils_lib_ft.d \
		src/mini/utils_ft/utils_lib_ft_2.d \
		src/mini/utils_ft/utils_lib_ft_3.d

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