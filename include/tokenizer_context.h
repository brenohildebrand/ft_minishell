/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_context.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:57:23 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/25 19:10:43 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_CONTEXT_H
# define TOKENIZER_CONTEXT_H

# include "minishell.h"

# define TOKENIZER_MODE_ORDINARY 1
# define TOKENIZER_MODE_HEREDOC 2

typedef struct s_tokenizer_context	*t_tokenizer_context;

struct s_tokenizer_context {
	t_cstring	line;
	t_i32		delimiter_start;
	t_i32		delimiter_end;
	t_i32		index;
	t_i32		mode;
	t_bool		completed;
	t_bool		is_single_quoted;
	t_bool		is_double_quoted;
	t_bool		is_word;
	t_bool		is_operator;
	t_bool		is_inside_a_token;
	t_bool		is_outside_a_token;
	t_bool		was_rule_applied;
};

t_tokenizer_context	tokenizer_context_new(t_mini mini, t_cstring cursor);

#endif