/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_parse_command.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:39:07 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/12 20:58:25 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_mini_cmd_tree	mini_parse_command(t_mini mini)
{
	
	t_mini_cmd_tree	tree;
	
	tree = mini_cmd_tree_create(mini);
	while (42)
	{
		if (mini_parser_is_word(mini))
		{
			mini_list_append(mini, &(tree->words), mini->parser->cursor->token, mini->parser->cursor->type);
		}
		else if (mini_parser_is_redir(mini))
		{
			mini_parser_next_token(mini);
			if (mini_parser_is_word(mini))
			{
				mini_list_append(mini, &(tree->redirs), mini->parser->cursor->previous->token, mini->parser->cursor->previous->type);
				mini_list_append(mini, &(tree->redirs), mini->parser->cursor->token, mini->parser->cursor->type);
			}
			else
			{
				mini_parser_set_syntax_error(mini);
				mini_cmd_tree_destroy(mini, tree);
				return (NULL);
			}
		}
		else
		{
			break ;
		}
		mini_parser_next_token(mini);
	}
	return (tree);
}
