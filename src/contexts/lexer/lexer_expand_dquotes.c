/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_expand_dquotes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:06:03 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/04 21:11:29 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

t_none	lexer_expand_dquotes(t_mini mini, t_list_node node)
{
	t_mini_token	token;
	t_i32			start;
	t_i32			end;

	token = (t_mini_token)node->value;
	start = 0;
	end = 0;
	while (token->value[start] && token->value[start] != '$')
		start++;
	if (token->value[start])
	while (token->value[end] && !i8_is_whitespace(token->value[end]))
	{
		end++;
	}
	end -= 1;
	mini->str = cstring_get_subcstring(mini, token->value, start, end);
	
	token->value = lexer_expand(mini, mini->str);
	mini_free(mini, mini->str);
}
