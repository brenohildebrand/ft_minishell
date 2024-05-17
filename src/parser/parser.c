/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:50:04 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/16 19:44:43 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"

t_i32	parser(t_minishell mini)
{
	(void)mini;
	return (SUCCESS);

	t_linked_list_node	current_node;
	t_token				current_token;
	t_token				next_token;

	current_node = mini->list->head;
	while (current_node)
	{
		current_token = (t_token)current_node->value;
		if (current_node->next)
		{
			next_token = ((t_token)current_node->next)->value;
		}
		else
		{
			next_token = NULL;
		}
		if (current_token->type == REDIR_HEREDOC && next_token && next_token->type == WORD)
			if (create_heredoc_file(current_node->next) != SUCCESS)
				return (*get_exit_status());
		if (check_syntax(current_node) != SUCCESS)
			return (set_exit_status(SYNTAX_ERROR));
		current_node = current_node->next;
	}
	mini->tree = build_execution_tree(mini->list);
	return (SUCCESS);
}
