/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:11:58 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/15 00:08:51 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	mini_parse(t_mini mini)
{
	t_mini_pipe_sequence_tree	tree;
	t_mini_cmd_tree_list		command_list;
	t_mini_cmd_tree				command;
	t_mini_list					node;
	t_i32						i;

	mini_parser_reset(mini);
	if (mini_parser_get_token(mini) == END)
	{
		mini->parser->tree = NULL;
	}
	else
	{
		mini->parser->tree = mini_parse_pipe_sequence(mini);
		if (mini->parser->tree)
		{
			if (mini->parser->found_heredoc)
			{
				if (mini->shared->is_statement_complete == TRUE)
				{
					mini->shared->is_heredoc_complete = FALSE;
				}
			}
		}
		else if (mini->parser->could_be_completed)
		{
			mini->shared->is_statement_complete = FALSE;
		}
		else
		{
			mini_parser_print_syntax_error(mini);
			mini_reset(mini);
		}
	}
	printf("\033[94m[%s:%d]\n(command)\033[0m ", __func__, __LINE__);
	tree = mini->parser->tree;
	if (tree)
	{
		command_list = tree->command_list;
		i = 0;
		while (i < command_list->length)
		{
			command = command_list->elements[i];
			node = command->words;
			while (node && node->token)
			{
				printf("%s ", node->token);
				node = node->next;
			}
			node = command->redirs;
			while (node && node->token)
			{
				if (node->next && node->token)
					printf("%s ", node->token);
				else
					printf("%s", node->token);
				node = node->next;
			}
			if (i + 1 < command_list->length)
				printf("| ");
			else
				printf("\n");
			i++;
		}	
	}
	else
	{
		printf("\n");
	}
}
