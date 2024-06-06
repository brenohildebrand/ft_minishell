/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_expand.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:57:05 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/06 13:08:01 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#ifdef ENABLE_DEBUGGER

t_none	mini_expand(t_mini mini)
{
	const t_lexer	lexer = mini->lexer;
	t_mini_token	token;
	t_list_node		node;

	node = lexer->tokens->head;
	if (node == NULL)
		return ;
	while (node)
	{
		token = (t_mini_token)node->value;
		if (token->value[0] == '$')
		{
			lexer_expand_word(mini, node);
		}
		else if (token->value[0] == '"')
		{
			lexer_expand_dquotes(mini, node);	
		}
		node = node->next;
	}
	node = lexer->tokens->head;
	printf("\033[94m[%s:%d]\n(tokens)\033[0m ", __func__, __LINE__);
	while (node)
	{
		token = (t_mini_token)node->value;
		printf("%s", token->value);
		if (node->next)
			printf(", ");
		node = node->next;
	}
	printf("\n");
}

#else

#endif