/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:39:42 by bhildebr          #+#    #+#             */
/*   Updated: 2024/04/30 17:41:46 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"
#include "linked_list.h"
#include "binary_tree.h"
#include "token.h"

t_i32	parser(t_linked_list tokens, t_binary_tree execution_tree)
{
	t_linked_list_node	current_node;
	t_token				current_token;
	t_token				next_token;

	current_node = tokens->head;
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
	execution_tree = build_execution_tree(tokens);
	return (SUCCESS);
}
