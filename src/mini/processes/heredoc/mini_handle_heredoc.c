/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_handle_heredoc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:28:33 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/16 20:34:38 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	mini_handle_heredoc(t_mini mini)
{
	t_mini_cmd_tree_list		command_list;
	t_i32						i;

	if (!mini->shared->is_heredoc_complete)
	{
		command_list = mini->parser->tree->command_list;
		i = 0;
		while (i < command_list->length)
		{
			mini->heredoc->redirs = command_list->elements[i]->redirs;
			while (mini->heredoc->redirs)
			{
				if (mini->heredoc->redirs->type == REDIR_HEREDOC)
				{
					mini_heredoc_read(mini);
					mini_heredoc_write(mini);
					mini_heredoc_update_tree(mini);
				}
				mini->heredoc->redirs = mini->heredoc->redirs->next;
			}
			i++;
		}
	}
	printf("\033[94m[%s:%d]\n(command)\033[0m ", __func__, __LINE__);
	mini_pipe_tree_print(mini, mini->parser->tree);
}
