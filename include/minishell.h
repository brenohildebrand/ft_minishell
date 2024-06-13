/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduardocoelho <eduardocoelho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 21:53:49 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/13 18:34:57 by eduardocoel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define ENABLE_DEBUGGER
# define ENABLE_LUA

# include <fcntl.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <readline/readline.h>
# include <readline/history.h>
#include  <errno.h>

# include "mini/primitives/i8.h"
# include "mini/primitives/u8.h"
# include "mini/primitives/i32.h"
# include "mini/primitives/u32.h"
# include "mini/primitives/i64.h"
# include "mini/primitives/u64.h"
# include "mini/primitives/any.h"
# include "mini/primitives/bool.h"
# include "mini/primitives/none.h"
# include "mini/primitives/memory.h"
# include "mini/primitives/cstring.h"
# include "mini/compounds/mini_list.h"
# include "mini/compounds/mini_tree.h"
# include "mini/systems/memtree.h"
# include "mini/systems/memstack.h"
# include "mini/processes/reader.h"
# include "mini/processes/lexer.h"
# include "mini/processes/expansion.h"
# include "mini/processes/parser.h"
# include "mini/processes/heredoc.h"
# include "mini/processes/eval.h"
# include "mini/contexts/shared.h"
# include "mini/contexts/signals.h"
# include "mini/contexts/config.h"

# ifdef ENABLE_DEBUGGER
#  include <stdio.h>
# endif

# define PROMPT "mini> "
# define MULTILINE_PROMPT "> "

# define MEMORY_ALLOCATION_ERROR 1
# define MEMSTACK_OVERFLOW_ERROR 2
# define HEREDOC_FILE_ERROR 3
# define SIGNALS_ERROR 4
# define LUA_ERROR 5

typedef struct s_mini	*t_mini;

struct s_mini {
	t_config	config;
	t_shared	shared;
	t_signals	signals;
	t_reader	reader;
	t_lexer		lexer;
	t_expansion	expansion;
	t_parser	parser;
	t_heredoc	heredoc;
	t_eval		eval;
};

t_mini	mini_create(t_i32 argc, t_i8 **argv);
t_none	mini_assert(t_mini mini, t_bool condition, t_u8 code);
t_none	mini_quit(t_mini mini, t_u8 code);
t_mem	mini_alloc(t_mini mini, t_u32 size);
t_none	mini_free(t_mini mini, t_mem mem);
t_bool	mini_is_complete(t_mini mini);
t_none	mini_read(t_mini mini);
t_none	mini_tokenize(t_mini mini);
t_none	mini_expand(t_mini mini);
t_none	mini_parse(t_mini mini);
t_none	mini_eval(t_mini mini);
t_none	mini_reset(t_mini mini);
t_none	mini_heredoc(t_mini mini);

t_i32	ft_strlen(t_cstring str);
t_cstring	ft_strdup(const t_cstring str);
t_cstring	ft_strchr(t_cstring s, t_i32 c);
t_cstring	ft_strnstr(const t_cstring big, const t_cstring little, size_t len);
t_cstring	ft_substr(t_cstring s, t_u32 start, t_i32 len);
t_i32	ft_isalnum(t_i32 c);
t_i32	ft_isdigit(t_i32 c);
t_none	ft_putstr(t_cstring str);

#endif