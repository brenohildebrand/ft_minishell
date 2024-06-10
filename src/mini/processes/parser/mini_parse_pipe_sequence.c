/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_parse_pipe_sequence.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:38:01 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/10 18:19:17 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_mini_pipe_tree	mini_parse_pipe_sequence(t_mini mini)
{
	t_mini_pipe_tree	tree;
	t_mini_cmd_tree		command;
	
	tree = mini_pipe_tree_create(mini);
	command = mini_parse_command(mini);
	if (command == NULL)
	{
		mini_pipe_tree_destroy(mini, tree);
		return (NULL);
	}
	else
	{
		mini_pipe_tree_append_command(mini, tree, command);
		while (mini_parser_is_pipe(mini))
		{
			mini_parser_next(mini);
			if (mini_parser_is_end(mini))
			{
				mini->parser->could_be_completed = TRUE;
				mini_pipe_tree_destroy(mini, tree);
				return (NULL);
			}
			command = mini_parse_command(mini);
			if (command == NULL)
			{
				break ;
			}
			else
			{
				mini_pipe_tree_append_command(mini, tree, command);
			}
		}
		if (mini_parser_is_end(mini))
			return (tree);
		mini_parser_set_syntax_error(mini);
		mini_pipe_tree_destroy(mini, tree);
		return (NULL);
	}
}
