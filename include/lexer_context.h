/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_context.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:57:23 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/25 21:24:16 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef lexer_CONTEXT_H
# define lexer_CONTEXT_H

# include "minishell.h"

# define LEXER_MODE_ORDINARY 1
# define LEXER_MODE_HEREDOC 2

typedef struct s_lexer_context	*t_lexer_context;

struct s_lexer_context {
	t_cstring	cursor;
	t_cstring	delimiter_start;
	t_cstring	delimiter_end;
	t_llist		tokens;
	t_i32		mode;
	t_bool		has_finished;
	t_bool		is_single_quoted;
	t_bool		is_double_quoted;
	t_bool		is_word;
	t_bool		is_operator;
	t_bool		is_empty;
	t_bool		has_applied_rule;
};

t_lexer_context	lexer_context_new(t_mini mini);
t_none			lexer_context_reset(t_mini mini);

#endif