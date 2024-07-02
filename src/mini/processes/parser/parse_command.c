/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:39:07 by bhildebr          #+#    #+#             */
/*   Updated: 2024/07/01 10:33:45 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_mini_cmd_tree	parse_command(t_mini mini)
{
	
	t_mini_cmd_tree	tree;
	t_bool			is_heredoc;
	
	tree = mini_cmd_tree_create(mini);
	while (42)
	{
		if (parser_is_word(mini))
		{
			mini_list_append(mini, &(tree->words), mini->parser->cursor->token, mini->parser->cursor->type);
		}
		else if (parser_is_redir(mini))
		{
			if (parser_get_token(mini) == REDIR_HEREDOC)
				is_heredoc = TRUE;
			else
				is_heredoc = FALSE;
			parser_next_token(mini);
			if (parser_is_word(mini))
			{
				if (is_heredoc)
					mini->shared->is_heredoc_complete = FALSE;
				mini_list_append(mini, &(tree->redirs), mini->parser->cursor->previous->token, mini->parser->cursor->previous->type);
				mini_list_append(mini, &(tree->redirs), mini->parser->cursor->token, mini->parser->cursor->type);
			}
			else
			{
				parser_set_syntax_error(mini);
				mini_cmd_tree_destroy(mini, tree);
				return (NULL);
			}
		}
		else
		{
			break ;
		}
		parser_next_token(mini);
	}
	return (tree);
}
