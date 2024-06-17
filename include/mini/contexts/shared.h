/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 00:05:49 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/16 19:20:29 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_H
# define SHARED_H

# include "minishell.h"

typedef struct s_shared_context	*t_shared_context;
typedef t_shared_context		t_shared;

struct s_shared_context {
	t_i32		argc;
	t_i8		**argv;
	t_i8		**envp;
	t_i8		**env;
	t_memtree	memtree;
	t_memstack	memstack;
	t_i32		exit_code;
	t_bool		is_statement_complete;
	t_bool		is_grammar_wrong;
	t_bool		is_heredoc_complete;
};

t_none	mini_shared_create(t_mini mini, t_i32 argc, t_i8 **argv, t_i8 **envp);

#endif