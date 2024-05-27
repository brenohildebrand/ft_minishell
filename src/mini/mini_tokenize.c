/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_tokenize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:07:35 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/27 11:06:40 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	mini_tokenize(t_mini mini)
{
	const t_lexer_context	context = mini->lexer_context;

	lexer_context_reset(mini);
	while (context->has_finished == FALSE)
	{
		if (context->mode == LEXER_MODE_ORDINARY)
		{
			mini_lexer_ordinary(mini);
		}
		else if (context->mode == LEXER_MODE_HEREDOC)
		{
			mini_lexer_heredoc(mini);
		}
	}
	#ifdef DEBUG
		t_linked_list_node	node;
		t_token		token;

		if (context->tokens->head)
		{
			node = context->tokens->head;
			while (node->next)
			{
				token = (t_token)node->value;
				printf("{length: %u, type: %d, value: %s}\n", token->length, token->type, token->value);
				node = node->next;
			}
		}
	#endif
}
