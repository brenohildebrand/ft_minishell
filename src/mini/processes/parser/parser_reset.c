/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_reset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:36:32 by bhildebr          #+#    #+#             */
/*   Updated: 2024/07/01 10:34:37 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	parser_reset(t_mini mini)
{
	if (mini->parser->tree)
	{
		mini_pipe_tree_destroy(mini, mini->parser->tree);
	}
	mini->parser->tree = NULL;
	mini->parser->cursor = mini->lexer->tokens;
	mini->parser->found_heredoc = FALSE;
	mini->parser->could_be_completed = FALSE;
	if (mini->lexer->tokens)
		mini->parser->unexpected_token = mini->lexer->tokens->token;
	else
		mini->parser->unexpected_token = NULL;
}
