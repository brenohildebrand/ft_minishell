/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 18:22:01 by bhildebr          #+#    #+#             */
/*   Updated: 2024/07/02 19:02:19 by bhildebr         ###   ########.fr       */
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
typedef struct s_fdtree			*t_fdtree;

typedef struct s_mini			*t_mini;

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

struct s_mini {
	// t_shared	shared;
	// t_signals	signals;
	// t_reader	reader;
	// t_lexer		lexer;
	// t_expansion	expansion;
	// t_parser	parser;
	// t_heredoc	heredoc;
	// t_eval		eval;
};

#endif