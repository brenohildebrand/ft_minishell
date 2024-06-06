/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_tokenize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:07:35 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/06 14:16:05 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#ifdef ENABLE_DEBUGGER

t_none	mini_tokenize(t_mini mini)
{
	const t_lexer	lexer = mini->lexer;
	t_mini_list		list;

	mini_lexer_update_mode(mini);
	if (lexer->mode == LEXER_MODE_ORDINARY)
	{
		mini_lexer_ordinary(mini);
	}
	else if (lexer->mode == LEXER_MODE_HEREDOC)
	{
		mini_lexer_heredoc(mini);
	}
	list = mini->lexer->tokens;
	printf("\033[94m[%s:%d]\n(tokens)\033[0m ", __func__, __LINE__);
	while (list)
	{
		printf("%s", list->token);
		if (node->next)
			printf(", ");
		node = node->next;
	}
	printf("\n");
}

#else

#endif

// t_none	mini_tokenize(t_mini mini)
// {
// 	const t_lexer	lexer = mini->lexer;

// 	lexer_reset(mini);
// 	while (!lexer->has_finished)
// 	{
// 		if (lexer->mode == LEXER_MODE_ORDINARY)
// 		{
// 			lexer_ordinary(mini);
// 		}
// 		else if (lexer->mode == LEXER_MODE_HEREDOC)
// 		{
// 			lexer_heredoc(mini);
// 		}
// 	}
// 	#ifdef ENABLE_DEBUGGER
// 		t_list_node	node;
// 		t_token		token;
		
// 		node = lexer->tokens->head;
// 		printf("\033[94m[%s:%d]\n(tokens)\033[0m\n", __func__, __LINE__);
// 		while (node)
// 		{
// 			token = (t_token)node->value;
// 			printf("{\n\tlength: %u,\n\ttype: %d,\n\tvalue: %s\n}\n", token->length, token->type, token->value);
// 			node = node->next;
// 		}
// 	#endif
// }
