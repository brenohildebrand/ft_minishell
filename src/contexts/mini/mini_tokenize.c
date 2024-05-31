/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_tokenize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:07:35 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/30 22:10:58 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

t_none	mini_tokenize(t_mini mini)
{
	// const t_lexer	context = mini->lexer;

	// lexer_reset(mini);
	// while (context->has_finished == FALSE)
	// {
	// 	if (context->mode == LEXER_MODE_ORDINARY)
	// 	{
	// 		mini_lexer_ordinary(mini);
	// 	}
	// 	else if (context->mode == LEXER_MODE_HEREDOC)
	// 	{
	// 		mini_lexer_heredoc(mini);
	// 	}
	// }
	// #ifdef DEBUG
	// 	t_linked_list_node	node;
	// 	t_token			token;
		
	// 	node = context->tokens->head;
	// 	if (node)
	// 	{
	// 		printf("\033[94m[%s:%d] (tokens)\033[0m\n", __func__, __LINE__);
	// 	}
	// 	while (node)
	// 	{
	// 		token = (t_token)node->value;
	// 		printf("{\n\tlength: %u,\n\ttype: %d,\n\tvalue: %s\n}\n", token->length, token->type, token->value);
	// 		node = node->next;
	// 	}
	// #endif
	(void)mini;
}
