/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:17:18 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/16 19:30:37 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

#include "minishell.h"
#include "token.h"

t_i32	check_open_syntax(t_cstring line);
t_i32	get_token_length(t_cstring line, t_i32 type);
t_i32	get_token_type(t_cstring line);
t_i32	get_word_length(t_cstring line);
t_i32	lexer(t_minishell mini);
void	move_to_next_quote(
	t_cstring line,
	t_i32 *index,
	t_i32 *single_quote,
	t_i32 *double_quote
);
void	push_to_token_list(
	t_minishell mini,
	t_token token
);

#endif