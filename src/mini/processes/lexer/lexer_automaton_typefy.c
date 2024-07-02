/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_automaton_typefy.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:58:08 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/30 20:13:57 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_i32	lexer_automaton_typefy(t_mini mini)
{
	if (mini->lexer->state == 100)
		return (WORD);
	else if (mini->lexer->state == 101)
		return (REDIR_OUT);
	else if (mini->lexer->state == 102)
		return (REDIR_APPEND);
	else if (mini->lexer->state == 103)
		return (REDIR_IN);
	else if (mini->lexer->state == 104)
		return (REDIR_HEREDOC);
	else if (mini->lexer->state == 105)
		return (PIPE);
	else if (mini->lexer->state == 106)
		return (DOUBLE_QUOTES);
	else if (mini->lexer->state == 107)
		return (SINGLE_QUOTES);
	else
	{
		write(STDERR_FILENO, "What the heck?!\n", 17);
		mini_quit(mini, 42);
	}
	return (0);
}
