/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_remove_quotes.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 20:22:43 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/30 20:47:19 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	expansion_remove_quotes(t_mini mini)
{
	t_mini_list	node;
	t_i32		i;
	t_bool		is_in_single_quotes;
	t_bool		is_in_double_quotes;
	t_cstring	dup;

	is_in_single_quotes = FALSE;
	is_in_double_quotes = FALSE;
	node = mini->lexer->tokens;
	while (node)
	{
		if (node->type == WORD)
		{
			i = 0;
			while (node->token[i])
			{
				if (node->token[i] == '\'')
				{
					if (is_in_single_quotes || !is_in_double_quotes)
					{
						is_in_single_quotes = !is_in_single_quotes;
						dup = node->token;
						node->token = cstring_remove(mini, node->token, i, i);
						mini_free(mini, dup);
					}
				}
				if (node->token[i] == '"')
				{
					if (is_in_double_quotes || !is_in_single_quotes)
					{
						is_in_double_quotes = !is_in_double_quotes;
						dup = node->token;
						node->token = cstring_remove(mini, node->token, i, i);
						mini_free(mini, dup);
					}
				}
				i++;
			}
		}
		node = node->next;
	}
}
