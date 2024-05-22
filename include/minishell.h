/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:52:50 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/22 14:38:38 by bhildebr         ###   ########.fr       */
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
# include "list.h"
# include "btree.h"
# include "htable.h"
# include "token.h"
# include "tokenizer.h"

# define DEBUG

# ifdef DEBUG
#  include <stdio.h>
# endif

# ifdef DEBUG
# endif

# define CUSTOM_PROMPT
# define PROMPT "mini> "
# define MULTILINE_PROMPT "> "

# define MINI_FLAG_MULTILINE			0
# define MINI_FLAG_STATEMENT_COMPLETED	2

# define MINI_TRANSITION_TABLE_WORD 0
# define MINI_TRANSITION_TABLE_GT 1
# define MINI_TRANSITION_TABLE_LT 2
# define MINI_TRANSITION_TABLE_DQUOTES 3
# define MINI_TRANSITION_TABLE_SQUOTES 4
# define MINI_TRANSITION_TABLE_PIPE 5
# define MINI_TRANSITION_TABLE_WSPACE 6
# define MINI_TRANSITION_TABLE_NULL 7

typedef struct s_mini	*t_mini;

struct s_mini {
	t_memtree	memtree;
	t_list		list;
	t_btree		btree;
	t_cstring	line;
	t_cstring	statement;
	t_i32		flags;
	t_htable	table;
};

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
t_i32		(*mini_get_transition_table(void))[8];

#endif