/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 01:14:35 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/31 18:38:16 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_H
# define MINI_H

# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "i8.h"
# include "u8.h"
# include "i32.h"
# include "u32.h"
# include "i64.h"
# include "u64.h"
# include "any.h"
# include "none.h"
# include "bool.h"
# include "memory.h"
# include "cstring.h"
# include "string.h"
# include "memory_tree.h"
# include "memory_stack.h"
# include "linked_list.h"
# include "binary_tree.h"
# include "hash_table.h"
# include "stack.h"
# include "lua.h"
# include "contexts/lexer.h"
# include "contexts/parser.h"
# include "contexts/input.h"
# include "contexts/config.h"

# define ENABLE_DEBUGGER
# ifdef ENABLE_DEBUGGER
#  include <stdio.h>
# endif

# define ENABLE_LUA
# ifdef ENABLE_LUA
#  include <lua5.4/lua.h>
#  include <lua5.4/lauxlib.h>
#  include <lua5.4/lualib.h>
# endif

# define PROMPT "mini> "
# define MULTILINE_PROMPT "> "

typedef struct s_mini_context	*t_mini_context;
typedef t_mini_context			t_mini;

struct s_mini_context {
	t_memtree			memtree;
	t_memstack			memstack;
	t_i32				argc;
	t_cstring_array		argv;
	t_i32				i;
	t_i32				j;
	t_i32				k;
	t_cstring			str;
	t_bool				is_multiline;
	t_bool				is_statement_complete;
	t_config_context	config;
	t_input_context		input;
	t_lexer				lexer;
	t_parser_context	parser;
	t_i32				exit_status;
};

t_mini	mini_create(t_i32 argc, t_cstring_array argv);
t_mem	mini_alloc(t_mini mini, t_u32 size);
t_none	mini_free(t_mini mini, t_mem mem);
t_none	mini_read(t_mini mini);
t_none	mini_evaluate(t_mini mini);
t_none	mini_readline(t_mini mini);
t_none	mini_tokenize(t_mini mini);
t_none	mini_parse(t_mini mini);
t_none	mini_quit(t_mini mini);
t_none	mini_assert(t_mini mini);
t_none	mini_get_cwd(t_mini mini);

#endif