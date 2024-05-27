/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:52:50 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/27 15:14:17 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "none.h"
# include "bool.h"
# include "i64.h"
# include "i32.h"
# include "u32.h"
# include "i8.h"
# include "mem.h"
# include "any.h"
# include "memtree.h"
# include "cstring.h"
# include "linked_list.h"
# include "btree.h"
# include "htable.h"
# include "token.h"
# include "lua.h"
# include "mini_context.h"
# include "lexer_context.h"
# include "config_context.h"

# define DEBUG

# ifdef DEBUG
#  include <stdio.h>
# endif

# define LUA

# ifdef LUA
#  include <lua5.4/lua.h>
#  include <lua5.4/lauxlib.h>
#  include <lua5.4/lualib.h>
# endif

# define CUSTOM_PROMPT
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

typedef struct s_mini			*t_mini;

struct s_mini {
	t_mini_context		mini_context;
	t_lexer_context		lexer_context;
	t_config_context	config_context;
};

/**
 * Builtin
*/

/**
 * Minishell
*/
t_mem		mini_alloc(t_mini mini, unsigned int size);
t_none		mini_assert(t_mini mini, t_bool condition, t_cstring message);
t_none		mini_evaluate(t_mini mini);
t_none		mini_free(t_mini mini, t_mem mem);
t_cstring	mini_get_cwd(t_mini mini);
t_cstring	mini_get_prompt(t_mini mini);
t_mini		mini_new(void);
t_none		mini_parse(t_mini mini);
t_none		mini_quit(t_mini mini);
t_none		mini_read(t_mini mini);
t_none		mini_readline(t_mini mini);
t_none		mini_tokenize(t_mini mini);
t_bool		mini_check_flag(t_mini mini, t_i32 flag);
t_none		mini_setup(t_mini mini);
t_none		mini_load_config(t_mini mini);

/**
 * Lexer
*/ 
t_none		mini_lexer_ordinary(t_mini mini);
t_none		mini_lexer_heredoc(t_mini mini);
t_none		mini_lexer_first_rule(t_mini mini);
t_none		mini_lexer_second_rule(t_mini mini);
t_none		mini_lexer_third_rule(t_mini mini);
t_none		mini_lexer_fourth_rule(t_mini mini);
t_none		mini_lexer_fifth_rule(t_mini mini);
t_none		mini_lexer_sixth_rule(t_mini mini);
t_none		mini_lexer_seventh_rule(t_mini mini);
t_none		mini_lexer_eighth_rule(t_mini mini);
t_none		mini_lexer_ninth_rule(t_mini mini);
t_none		mini_lexer_tenth_rule(t_mini mini);
t_none		mini_lexer_cut(t_mini mini);


/**
 * Parser
*/

/**
 * Signal
*/

#endif