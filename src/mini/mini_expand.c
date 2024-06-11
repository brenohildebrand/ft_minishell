/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_expand.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:57:05 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/11 17:34:30 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#ifdef ENABLE_DEBUGGER

static t_i32	where_is_end(
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

static t_i32	expand(t_mini mini, t_mini_list node, t_i32 start, t_i32 end)
{
	t_cstring	key;
	t_cstring	value;
	t_i32		value_length;

	if (start == end)
	{
		return (start);
	}
	else if (start == end - 1 && node->token[end] == '?')
	{
		value = mini_u8_to_cstring(mini, mini->shared->exit_code);
	}
	else
	{
		key = mini_cstring_get_subcstring(mini, node->token, start + 1, end);
		value = mini_cstring_copy(mini, getenv(key));
	}
	value_length = cstring_get_length(value);
	mini_cstring_remove(mini, &node->token, start, end);
	mini_cstring_add(mini, &node->token, start, value);
	mini_free(mini, key);
	mini_free(mini, value);
	return (start + value_length);
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
				printf("node->token[i]: %c\n", node->token[i]);
				if (node->token[i] == '$')
				{
					start = i;
					end = where_is_end(node->token, i);
					i = expand(mini, node, start, end);
				}
				else if (node->token[i] == '"')
				{
					// is_in_dquotes = !is_in_dquotes;
				}
				i++;
			}
		}
		node = node->next;
	}
	node = mini->lexer->tokens;
	printf("\033[94m[%s:%d]\n(tokens)\033[0m ", __func__, __LINE__);
	while (node)
	{
		printf("%s", node->token);
		if (node->next)
			printf(", ");
		node = node->next;
	}
	printf("\n");
}

#else

#endif