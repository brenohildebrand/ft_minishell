/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 01:14:35 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/30 15:01:16 by bhildebr         ###   ########.fr       */
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
# include "cstring.h"
# include "string.h"
# include "memory_tree.h"
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

# define MINI_FLAG_MULTILINE 0
# define MINI_FLAG_STATEMENT_COMPLETED	2

# define MINI_TRANSITION_TABLE_WORD 0
# define MINI_TRANSITION_TABLE_GT 1
# define MINI_TRANSITION_TABLE_LT 2
# define MINI_TRANSITION_TABLE_DQUOTES 3
# define MINI_TRANSITION_TABLE_SQUOTES 4
# define MINI_TRANSITION_TABLE_PIPE 5
# define MINI_TRANSITION_TABLE_WSPACE 6
# define MINI_TRANSITION_TABLE_NULL 7

typedef struct s_mini_context	*t_mini_context;
typedef t_mini_context			t_mini;

struct s_mini_context {
	t_i32				argc;
	t_cstring_array		argv;
	t_stack				stack;
	t_i32				i;
	t_i32				j;
	t_i32				k;
	t_config_context	config;
	t_input_context		input;
	t_lexer_context		lexer;
	t_parser_context	parser;
};

t_mini		mini_new(void);
t_mem		mini_alloc(t_mini mini, unsigned int size);
t_none		mini_assert(t_mini mini, t_bool condition, t_cstring message);
t_none		mini_evaluate(t_mini mini);
t_none		mini_free(t_mini mini, t_mem mem);
t_cstring	mini_get_cwd(t_mini mini);
t_cstring	mini_get_prompt(t_mini mini);
t_none		mini_parse(t_mini mini);
t_none		mini_quit(t_mini mini);
t_none		mini_read(t_mini mini);
t_none		mini_readline(t_mini mini);
t_none		mini_tokenize(t_mini mini);
t_bool		mini_check_flag(t_mini mini, t_i32 flag);
t_none		mini_setup(t_mini mini);
t_none		mini_load_config(t_mini mini);

#endif