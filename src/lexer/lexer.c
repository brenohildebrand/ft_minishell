/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:22:21 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/16 19:18:20 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "linked_list.h"
#include "token.h"
#include "utils.h"

t_i32	lexer(t_minishell mini)
{
	t_i32		type;
	t_i32		length;
	t_cstring	value;

	if (mini->line == NULL || check_open_syntax(mini->line))
	{
		return (set_exit_status(mini, SYNTAX_ERROR));
	}
	while (*(mini->line))
	{
		length = 0;
		type = get_token_type(mini->line);
		if (type == SPACES)
		{
			(mini->line)++;
		}
		else
		{
			length = get_token_length(mini->line, type);
			// value = ft_substr(mini->line, 0, length);
			value = get_subcstring(mini, mini->line, 0, length);
			push_to_token_list(mini, mini->list, new_token(mini, type, value));
			mini->line += length;
		}
	}
	#ifdef DEBUG
		t_linked_list_node	current_node;
		t_token				current_token;

		if (mini->list == NULL)
		{
			printf("\033[94m(list) ");
			printf("\033[0m\n");
		}
		else
		{
			current_node = mini->list->head;
			printf("\033[94m(list) ");
			while (current_node)
			{
				current_token = (t_token)current_node->value;				
				printf("%s", current_token->value);
				current_node = current_node->next;
			}
			printf("\033[0m\n");
		}
	#endif
	return (SUCCESS);
}
