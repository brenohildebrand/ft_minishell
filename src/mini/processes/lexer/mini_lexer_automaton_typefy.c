/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_lexer_automaton_typefy.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:58:08 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/06 15:59:14 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_i32	mini_lexer_automaton_typefy(t_mini mini)
{
	if (mini->lexer->state == 100)
		return (MINI_TOKEN_WORD);
	else if (mini->lexer->state == 101)
		return (MINI_TOKEN_GT);
	else if (mini->lexer->state == 102)
		return (MINI_TOKEN_DGT);
	else if (mini->lexer->state == 103)
		return (MINI_TOKEN_LT);
	else if (mini->lexer->state == 104)
		return (MINI_TOKEN_DLT);
	else if (mini->lexer->state == 105)
		return (MINI_TOKEN_PIPE);
	else if (mini->lexer->state == 106)
		return (MINI_TOKEN_DQUOTES);
	else if (mini->lexer->state == 107)
		return (MINI_TOKEN_SQUOTES);
	else
	{
		write(STDERR_FILENO, "What the heck?!\n", 17);
		mini_quit(mini);
	}
	return (0);
}
