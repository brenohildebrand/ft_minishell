/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 01:14:35 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/05 21:56:42 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_H
# define MINI_H

# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>

// # include "i8.h"
// # include "u8.h"
// # include "i32.h"
// # include "u32.h"
// # include "i64.h"
// # include "u64.h"
// # include "any.h"
// # include "none.h"
// # include "bool.h"
// # include "memory.h"

// # include "types.h"
// # include "memory_tree.h"
// # include "memory_stack.h"
// # include "contexts/shared.h"
// # include "contexts/config.h"
// # include "contexts/reader.h"
// # include "contexts/lexer.h"
// # include "contexts/expansion.h"
// # include "contexts/parser.h"
// # include "contexts/eval.h"

# define ENABLE_DEBUGGER
# ifdef ENABLE_DEBUGGER
#  include <stdio.h>
# endif

# define ENABLE_LUA
# ifdef ENABLE_LUA
#  include <lua5.4/lua.h>
#  include <lua5.4/lauxlib.h>
#  include <lua5.4/lualib.h>
#  include "lua.h"
# endif

# define PROMPT "mini> "
# define MULTILINE_PROMPT "> "

typedef struct s_mini_context	*t_mini_context;
typedef t_mini_context			t_mini;

struct s_mini_context {
	t_i32		argc;
	t_i8		*argv;
	t_shared	shared;
	t_config	config;
	t_reader	reader;
	t_lexer		lexer;
	t_expansion	expansion;
	t_parser	parser;
	t_eval		eval;
};

typedef struct s_mini_token		*t_mini_token;

struct s_mini_token {
	t_cstring	value;
	t_i32		length;
	t_i32		type;
};

enum e_mini_token_type {
	REDIR_IN,
	REDIR_OUT,
	REDIR_HEREDOC,
	REDIR_APPEND,
	PIPE,
	DOUBLE_QUOTES,
	SINGLE_QUOTES,
	WORD,
};

typedef struct s_mini_list		*t_mini_list;

struct s_mini_list {
	t_mini_list		next;
	t_mini_list		previous;
	t_mini_token	token;
};

typedef t_none					(*t_mini_function)(t_mini mini);
typedef	t_mini_function			t_mini_fn; 

typedef struct s_mini_tree		*t_mini_tree;

struct s_mini_tree {
	t_mini_tree		*children;
	t_mini_fn		evaluate;
};

t_mini	mini_create(t_i32 argc, t_i8 *argv);
t_mem	mini_alloc(t_mini mini, t_u32 size);
t_none	mini_free(t_mini mini, t_mem mem);
t_none	mini_read(t_mini mini);
t_none	mini_expand(t_mini mini);
t_none	mini_tokenize(t_mini mini);
t_none	mini_parse(t_mini mini);
t_none	mini_execute(t_mini mini);
t_none	mini_quit(t_mini mini);
t_none	mini_assert(t_mini mini);
t_none	mini_get_cwd(t_mini mini);
t_bool	mini_is_statement_complete(t_mini mini);

#endif