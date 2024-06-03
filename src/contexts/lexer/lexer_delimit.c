/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_delimit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 21:20:26 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/03 09:39:24 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

/**
 * See '2.10.1 Shell Grammar Lexical Conventions' 
*/
t_none	lexer_delimit(t_mini mini)
{
	const t_lexer	lexer = mini->lexer;
	t_token			new_token;

	if (lexer->buffer_length == 0)
		return ;
	new_token = lexer_token_new(mini);
	new_token->length = lexer->buffer_length;
	mini->str = mini_alloc(mini, lexer->buffer_length + 1);
	mini->i = 0;
	while (mini->i < lexer->buffer_length + 1)
	{
		mini->str[mini->i] = lexer->buffer[mini->i];
		mini->i++;
	}
	mini_free(mini, lexer->buffer);
	lexer->buffer = NULL;
	lexer->buffer_length = 0;
	lexer->buffer_size = 0;
	new_token->value = mini->str;
	new_token->type = 0;
	linked_list_append(mini, lexer->tokens, new_token);
}
