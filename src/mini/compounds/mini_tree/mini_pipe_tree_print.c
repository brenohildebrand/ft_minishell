/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_pipe_tree_print.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 20:32:25 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/17 13:55:34 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	mini_pipe_tree_print(t_mini mini, t_mini_pipe_tree tree)
{
	(void)mini;
	t_mini_cmd_tree_list		command_list;
	t_mini_cmd_tree				command;
	t_mini_list					node;
	t_i32						i;

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
