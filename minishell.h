/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 18:22:01 by bhildebr          #+#    #+#             */
/*   Updated: 2024/07/02 21:03:39 by bhildebr         ###   ########.fr       */
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

# define PROMPT "mini> "
# define MULTILINE_PROMPT "> "

# define TRUE 1
# define FALSE 0

# define SUCCESS 0
# define FAILURE 1

# define MINI_ERROR 1

typedef char					t_i8;
typedef unsigned char			t_u8;
typedef int						t_i32;
typedef unsigned int			t_u32;
typedef long long int			t_i64;
typedef unsigned long long int	t_u64;

typedef t_i32					t_bool;
typedef void					t_none;
typedef void					*t_any;

typedef char					*t_cstring;
typedef char					**t_cstring_array;

typedef struct s_memtree		*t_memtree;
typedef t_memtree				*t_memtree_ptr;

typedef struct s_fdtree			*t_fdtree;

typedef struct s_signals		*t_signals;
typedef struct s_shared			*t_shared;
typedef struct s_reader			*t_reader;
typedef struct s_lexer			*t_lexer;
typedef struct s_expansion		*t_expansion;
typedef struct s_parser			*t_parser;
typedef struct s_heredoc		*t_heredoc;
typedef struct s_eval			*t_eval;

typedef struct s_mini			*t_mini;

typedef struct s_mini_list		*t_mini_list;

typedef t_none					(*t_fn)(t_mini);

struct s_memtree {
	t_memtree	ltree;
	t_memtree	rtree;
	t_any		address;
	t_i32		height;
};

struct s_fdtree {
	t_fdtree	ltree;
	t_fdtree	rtree;
	t_i32		fd;
	t_i32		height;
};

struct s_signals {};

struct s_shared {
	t_i32		argc;
	t_i8		**argv;
	t_i8		**envp;
	t_i8		**env;
	t_memtree	memtree;
	t_fdtree	fdtree;
	t_i32		exit_code;
	t_bool		is_statement_complete;
	t_bool		is_grammar_wrong;
	t_bool		is_heredoc_complete;
};

struct s_reader {
	t_cstring	line;
	t_cstring	statement;
	t_cstring	prompt;
	t_cstring	multiline_prompt;
};

struct s_lexer {
	t_mini_list	tokens;
	t_cstring	cursor;
	t_i32		start;
	t_i32		end;
	t_i32		state;
	t_i32		table[7][8];
};

struct s_expansion {};

struct s_parser {};

struct s_heredoc {};

struct s_eval {};

struct s_mini {
	t_shared	shared;
	t_signals	signals;
	t_reader	reader;
	t_lexer		lexer;
	t_expansion	expansion;
	t_parser	parser;
	t_heredoc	heredoc;
	t_eval		eval;
};

struct s_mini_list {
	t_mini_list	next;
	t_mini_list	previous;
	t_cstring	token;
	t_i32		type;
};

enum e_mini_list_type {
	PIPE,
	REDIR_IN,
	REDIR_OUT,
	REDIR_HEREDOC,
	REDIR_APPEND,
	DOUBLE_QUOTES,
	SINGLE_QUOTES,
	WORD,
	END
};

#endif