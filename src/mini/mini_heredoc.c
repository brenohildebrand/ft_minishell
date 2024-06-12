/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:28:33 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/11 23:21:40 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	mini_heredoc(t_mini mini)
{
	t_mini_cmd_tree_list	command_list;
	t_i32					i;
	
	if (!mini->shared->is_heredoc_complete)
	{
		printf("TODO: implement mini_heredoc. Aborting.\n");
		mini_quit(mini, 0);
		// percorre os redir de cada comando na orderm q aparece
		// se for heredoc 
		// 	le as linhas e vai salvando num buffer
		//	ate achar delimiter\n
		//	escreve o resultado num arquivo temporario
		//  substitui o delimiter com o nome do arquivo temporario
		// cabou
		
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
}
