/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_expand.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:57:05 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/06 21:50:01 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#ifdef ENABLE_DEBUGGER

t_none	mini_expand(t_mini mini)
{
	// t_mini_list	node;

	// node = mini->lexer->tokens;
	// while (node)
	// {
	// 	if (node->token[0] == '$')
	// 	{
	// 		mini_expansion_expand_word(mini, node);
	// 	}
	// 	else if (node->token[0] == '"')
	// 	{
	// 		mini_expansion_expand_dquotes(mini, node);	
	// 	}
	// 	node = node->next;
	// }
	// node = mini->lexer->tokens;
	// printf("\033[94m[%s:%d]\n(tokens)\033[0m ", __func__, __LINE__);
	// while (node)
	// {
	// 	printf("%s", node->token);
	// 	if (node->next)
	// 		printf(", ");
	// 	node = node->next;
	// }
	// printf("\n");
	(void)mini;
}

#else

#endif