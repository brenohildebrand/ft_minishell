/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:20:15 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/30 14:43:13 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "contexts/mini.h"

# define LEXER_CONTEXT_MODE_ORDINARY 1
# define LEXER_CONTEXT_MODE_HEREDOC 2

# define LEXER_CONTEXT_FLAG_IS_OPERATOR
# define LEXER_CONTEXT_FLAG_IS_WORD
# define LEXER_CONTEXT_FLAG_IS_QUOTED
# define LEXER_CONTEXT_FLAG_HAS_APPLIED_RULE

# define TOKEN_AND_IF "&&"
# define TOKEN_CATEGORY_AND_IF "&&"
# define TOKEN_CATEGORY_OR_IF "||"
# define TOKEN_CATEGORY_DLESS ""
# define TOKEN_CATEGORY_DGREAT

typedef struct s_lexer_context	*t_lexer_context;
typedef t_lexer_context			t_lexer;

typedef struct s_token	*t_token;

struct s_lexer_context {
	t_cstring		line;
	t_cstring		cursor;
	t_cstring		buffer;
	t_linked_list	tokens;
	t_i32			flags;
};

struct s_token {
	t_cstring	value;
	t_u32		length;
	t_i32		type;	
};

enum e_token_type {
	AND,
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

t_lexer	lexer_new(t_mini mini);
t_none	lexer_reset(t_mini mini);

t_token	token_new(t_mini mini);
t_i32	token_type_cstring(t_cstring str);

void	lexer_ordinary(t_mini mini);
void	lexer_heredoc(t_mini mini);
void	lexer_first_rule(t_mini mini);
void	lexer_second_rule(t_mini mini);
void	lexer_third_rule(t_mini mini);
void	lexer_fourth_rule(t_mini mini);
void	lexer_fifth_rule(t_mini mini);
void	lexer_sixth_rule(t_mini mini);
void	lexer_seventh_rule(t_mini mini);
void	lexer_eighth_rule(t_mini mini);
void	lexer_ninth_rule(t_mini mini);
void	lexer_tenth_rule(t_mini mini);
void	lexer_cut(t_mini mini);

#endif