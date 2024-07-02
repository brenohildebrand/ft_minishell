/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_expand.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:57:05 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/30 20:46:06 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_i32	where_is_end(t_cstring token, t_i32 start)
{
	t_i32	i;

	i = start;
	while (token[i])
	{
		if (token[i] == '>')
			return (i - 1);
		else if (token[i] == '<')
			return (i - 1);
		else if (token[i] == '"')
			return (i - 1);
		else if (token[i] == '\'')
			return (i - 1);
		else if (token[i] == '|')
			return (i - 1);
		else if (token[i] == ' ' || (token[i] >= '\t' && token[i] <= '\r'))
			return (i - 1);
		else if (token[i] == '\0')
			return (i - 1);
		else
			i++;
	}
	return (i - 1);
}

t_none	mini_expand(t_mini mini)
{
	t_mini_list	node;
	t_i32		start;
	t_i32		end;

	node = mini->lexer->tokens;
	while (node)
	{
		if (node->type == WORD)
		{
			start = 0;
			while (node->token[start])
			{
				if (node->token[start] == '$')
				{
					end = where_is_end(node->token, start);
					start = expansion_expand(mini, node, start, end);
				}
				start++;
			}
		}
		node = node->next;
	}
	expansion_remove_quotes(mini);
	printf("\033[94m[%s:%d]\n(tokens)\033[0m ", __func__, __LINE__);
	mini_list_print(mini);
}
