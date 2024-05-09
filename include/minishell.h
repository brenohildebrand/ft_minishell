/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:52:50 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/09 16:36:34 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "types.h"

# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "memory_tree.h"
# include "linked_list.h"
# include "binary_tree.h"

# define DEBUG

# define PROMPT "minishell> "
# define SUCCESS 0
# define FAILURE 1
# define SYNTAX_ERROR 2

typedef struct s_minishell	*t_minishell;

struct s_minishell {
	t_memory_tree	memtree;
	t_cstring		line;
	t_linked_list	list;
	t_binary_tree	tree;
	t_i32			exit_status;
};

enum					e_token_type
{
	AND = 1,
	OR,
	PIPE,
	OPEN_PAREN,
	CLOSE_PAREN,
	REDIR_APPEND,
	REDIR_HEREDOC,
	REDIR_IN,
	REDIR_OUT,
	SPACES,
	END,
	WORD,
};

void		*mini_alloc(t_minishell mini, t_u32 size);
void		mini_free(t_minishell mini, void *address);
t_minishell	new_minishell(void);
t_i32		syntax_error(char *token);

#endif