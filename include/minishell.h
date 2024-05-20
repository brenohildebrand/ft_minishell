/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:52:50 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/20 18:25:13 by bhildebr         ###   ########.fr       */
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
# include "memtree.h"
# include "cstring.h"
// # include "linked_list.h"
// # include "binary_tree.h"

# define DEBUG

# ifdef DEBUG
#  include <stdio.h>
# endif

# define PROMPT "mini> "

typedef struct s_mini	*t_mini;

struct s_mini {
	t_memtree	memtree;
	t_cstring	line;
	// t_list		list;
	// t_btree		btree;
	t_i32		exit_status;
};

// enum					e_token_type
// {
// 	AND = 1,
// 	OR,
// 	PIPE,
// 	OPEN_PAREN,
// 	CLOSE_PAREN,
// 	REDIR_APPEND,
// 	REDIR_HEREDOC,
// 	REDIR_IN,
// 	REDIR_OUT,
// 	SPACES,
// 	END,
// 	WORD,
// };

// void		*mini_alloc(t_minishell mini, t_u32 size);
// void		mini_free(t_minishell mini, void *address);
// void		mini_quit(t_minishell mini);
// t_minishell	new_minishell(void);
// void		destroy_minishell(t_minishell mini);
// t_i32		syntax_error(t_minishell mini, char *token);
// void		reset_minishell(t_minishell mini);
// t_i32		set_exit_status(t_minishell mini, t_i32 status);
// t_i32		get_exit_status(t_minishell mini);
t_mem		mini_alloc(t_mini mini, unsigned int size);
t_mini		mini_new(void);
t_none		mini_assert(t_mini mini, t_bool condition, t_cstring message);
t_none		mini_quit(t_mini mini);
t_none		mini_read(t_mini mini);
t_none		mini_evaluate(t_mini mini);
t_none		mini_print(t_mini mini);
t_cstring	mini_get_prompt(t_mini mini);

#endif