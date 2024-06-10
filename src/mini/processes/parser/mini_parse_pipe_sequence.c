/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_parse_pipe_sequence.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:38:01 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/10 15:09:50 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_mini_tree	mini_parse_pipe_sequence(t_mini mini)
{
	t_mini_tree	tree;
	t_mini_tree	child;

	child = mini_parse_command(mini);
	if (child == NULL)
	{
		return (NULL);
	}
	else
	{
		tree = mini_tree_create(mini);
		mini_tree_add_child(mini, tree, child);
		while (mini_parser_get_token(mini) == PIPE)
		{
			mini_parser_next_token(mini);
			if (mini_parser_get_token(mini) == END)
			{
				mini->parser->could_be_completed = TRUE;
				mini_tree_destroy(tree);
				return (NULL);
			}
			child = mini_parse_command(mini);
			if (child == NULL)
				break ;
			else
				mini_tree_add_child(mini, tree, child);
		}
		if (mini_parse_get_token(mini) != END)
		{
			mini_parser_set_syntax_error(mini);
			mini_tree_destroy(mini, tree);
			return (NULL);
		}
		return (tree);
	}
}
