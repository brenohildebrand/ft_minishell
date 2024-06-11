/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_expand.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:57:05 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/11 13:08:22 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#ifdef ENABLE_DEBUGGER

static t_i32	where_is_end(
	t_mini mini,
	t_cstring token,
	t_i32 start
){
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

static t_none	expand(t_mini mini, t_cstring token, t_i32 start, t_i32 end)
{
	t_cstring	key;
	t_cstring	value;
	
	if (start == end)
	{
		return ;
	}
	else if (start == end - 1 && token[end] == '?')
	{
		value = u8_to_cstring(mini->shared->exit_code);
	}
	else
	{
		key = mini_cstring_get_subcstring(mini, token, start + 1, end);
		value = mini_cstring_copy(mini, getenv(key));
	}
	mini_cstring_substitute(mini, start, end, value);
	mini_free(mini, key);
	mini_free(mini, value);
}

t_none	mini_expand(t_mini mini)
{
	t_mini_list	node;
	t_i32		i;
	t_i32		start;
	t_i32		end;

	node = mini->lexer->tokens;
	while (node)
	{
		if (node->type == WORD)
		{
			i = 0;
			while (node->token[i])
			{
				if (node->token[i] == '$')
				{
					start = i;
					end = where_is_end(mini, node->token, i);
					expand(mini, node->token, start, end);
				}
				else if (node->token[i] == '"')
				{
					// is_in_dquotes = !is_in_dquotes;
				}
				i++;
			}
			// look for $ and see if it's inside double quotes
			// if found
			//	start is at $
			//  end is at until it's a word or until before the closing double quotes
			// then start looking again from the next character
		}
		node = node->next;
	}
}

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

#else

#endif