/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:20:15 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/03 17:47:35 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "contexts/mini.h"

# define LEXER_MODE_ORDINARY 1
# define LEXER_MODE_HEREDOC 2

# define TOKEN_AND_IF "&&"
# define TOKEN_CATEGORY_AND_IF "&&"
# define TOKEN_CATEGORY_OR_IF "||"
# define TOKEN_CATEGORY_DLESS ""
# define TOKEN_CATEGORY_DGREAT

typedef struct s_lexer_context	*t_lexer_context;
typedef t_lexer_context			t_lexer;

struct s_lexer_context {
	t_i32			mode;
	t_cstring		cursor;
	t_i32			index;
	t_i32			state;
	t_i32			table[7][8];
	t_list			tokens;
};

t_none	lexer_create(t_mini mini);
t_none	lexer_reset(t_mini mini);

t_token	lexer_token_new(t_mini mini);
t_i32	lexer_token_type_cstring(t_cstring str);

t_none	lexer_ordinary(t_mini mini);
t_none	lexer_heredoc(t_mini mini);
t_none	lexer_first_rule(t_mini mini);
t_none	lexer_second_rule(t_mini mini);
t_none	lexer_third_rule(t_mini mini);
t_none	lexer_fourth_rule(t_mini mini);
t_none	lexer_fifth_rule(t_mini mini);
t_none	lexer_sixth_rule(t_mini mini);
t_none	lexer_seventh_rule(t_mini mini);
t_none	lexer_eighth_rule(t_mini mini);
t_none	lexer_ninth_rule(t_mini mini);
t_none	lexer_tenth_rule(t_mini mini);
t_none	lexer_delimit(t_mini mini);

t_bool	lexer_try_operator(t_mini mini);
t_bool	lexer_try(t_mini mini, t_cstring operator);

t_none	lexer_add_character(t_mini mini);
t_none	lexer_discard_character(t_mini mini);

t_i32	lexer_next_state(t_mini mini);
t_bool	lexer_is_final_state(t_mini mini);

#endif