/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 20:29:23 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/28 10:58:26 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN

# include "minishell.h"

typedef struct s_token	*t_token;

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

t_token	token_new(t_mini mini);
t_i32	token_type_cstring(t_cstring str);

#endif