/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_parse_command.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:39:07 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/10 18:26:17 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_mini_cmd_tree	mini_parse_command(t_mini mini)
{
	t_mini_cmd_tree	tree;
	t_mini_list		list_copy;	

	tree = mini_cmd_tree_create(mini);
	while (42)
	{
		if (mini_parser_is_word(mini))
		{
			list_copy = mini_list_copy(mini, mini->parser->cursor);
			mini_cmd_tree_append_word(mini, tree, list_copy);
		}
		else if (mini_parser_is_redir(mini))
		{
			mini_parser_next(mini);
			if (mini_parser_is_word(mini))
			{
				list_copy = mini_list_copy(mini, mini->parser->cursor - 1);
				mini_cmd_tree_append_redir(mini, tree, list_copy);
				list_copy = mini_list_copy(mini, mini->parser->cursor);
				mini_cmd_tree_append_word(mini, tree, list_copy);
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
