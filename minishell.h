/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 18:22:01 by bhildebr          #+#    #+#             */
/*   Updated: 2024/07/03 14:55:06 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <fcntl.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/ioctl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>

# include "libft.h"

# define PROMPT "mini> "
# define MULTILINE_PROMPT "> "

# define TRUE 1
# define FALSE 0

# define SUCCESS 0
# define FAILURE 1

typedef struct s_shared	t_shared;

typedef struct s_reader	t_reader;

typedef struct s_mini	t_mini;

struct s_shared {
	int		argc;
	char	**argv;
	char	**envp;
	int		is_statement_complete;
};

struct s_mini {
	t_shared	*shared;
	t_reader	*reader;
};

// typedef struct s_signals			*t_signals;
// typedef struct s_shared				*t_shared;
// typedef struct s_reader				*t_reader;
// typedef struct s_lexer				*t_lexer;
// typedef struct s_expansion			*t_expansion;
// typedef struct s_parser				*t_parser;
// typedef struct s_heredoc			*t_heredoc;
// typedef struct s_eval				*t_eval;

// typedef struct s_mini				*t_mini;

// struct s_memtree {
// 	t_memtree	ltree;
// 	t_memtree	rtree;
// 	t_any		address;
// 	t_i32		height;
// };

// struct s_fdtree {
// 	t_fdtree	ltree;
// 	t_fdtree	rtree;
// 	t_i32		fd;
// 	t_i32		height;
// };

// struct s_signals {};

// struct s_shared {
// 	t_i32		argc;
// 	t_i8		**argv;
// 	t_i8		**envp;
// 	t_i8		**env;
// 	t_memtree	memtree;
// 	t_fdtree	fdtree;
// 	t_i32		exit_code;
// 	t_bool		is_statement_complete;
// 	t_bool		is_grammar_wrong;
// 	t_bool		is_heredoc_complete;
// };

// struct s_reader {
// 	t_cstring	line;
// 	t_cstring	statement;
// 	t_cstring	prompt;
// 	t_cstring	multiline_prompt;
// };

// struct s_lexer {
// 	t_mini_list	tokens;
// 	t_cstring	cursor;
// 	t_i32		start;
// 	t_i32		end;
// 	t_i32		state;
// 	t_i32		table[7][8];
// };

// struct s_expansion {
// 	t_mini_list	tokens;
// 	t_bool		is_in_single_quotes;
// 	t_bool		is_in_double_quotes;
// };

// struct s_parser {};

// struct s_heredoc {};

// struct s_eval {};

// struct s_mini {
// 	t_shared	shared;
// 	t_signals	signals;
// 	t_reader	reader;
// 	t_lexer		lexer;
// 	t_expansion	expansion;
// 	t_parser	parser;
// 	t_heredoc	heredoc;
// 	t_eval		eval;
// };

// struct s_mini_list {
// 	t_mini_list	next;
// 	t_mini_list	previous;
// 	t_cstring	token;
// 	t_i32		type;
// };

// enum e_token_type {
// 	PIPE,
// 	REDIR_IN,
// 	REDIR_OUT,
// 	REDIR_HEREDOC,
// 	REDIR_APPEND,
// 	DOUBLE_QUOTES,
// 	SINGLE_QUOTES,
// 	WORD,
// 	END
// };

// struct s_mini_command {
// 	t_mini_list	words;
// 	t_mini_list	redirs;
// };

#endif