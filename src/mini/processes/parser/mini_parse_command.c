/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_parse_command.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:39:07 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/10 16:26:45 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_mini_tree	mini_parse_command(t_mini mini)
{
	t_mini_list	words;
	t_mini_list	redirs;
	t_mini_list	copy;

	words = NULL;
	redirs = NULL;
	while (42)
	{
		if (mini_parser_get_token(mini) == WORD)
		{
			copy = mini_list_copy(mini, mini->parser->cursor);
			mini_list_append(mini, words, copy);
		}
		else if (mini_parser_get_token(mini) == REDIR)
		{
			mini_parse_next_token(mini);
			if (mini_parse_get_token(mini) == WORD)
			{
				copy = mini_list_copy(mini, mini->parser->cursor - 1);
				mini_list_append(mini, redirs, copy);
				copy = mini_list_copy(mini, mini->parser->cursor);
				mini_list_append(mini, redirs, copy);
			}
			else
			{
				mini_set_syntax_error(mini);
				mini_list_clear(mini, words);
				mini_list_clear(mini, redirs);
				return (NULL);
			}
		}
		else
		{
			break ;
		}
		mini_parser_next_token(mini);
	}

	t_mini_tree	tree;
	
	// leave it in the list format

	// create tree from words and redirs + words
	// start with the redirs in order putting the filename as the second child
	// and the next redir as the first child
	// if there's no next redir put the command as the first child.
	// if there's no command put nothing.

	// go through redirs
	// 	create a node with that redir type 
}
