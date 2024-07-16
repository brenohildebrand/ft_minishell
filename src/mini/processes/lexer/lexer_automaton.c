/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_automaton.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:30:27 by bhildebr          #+#    #+#             */
/*   Updated: 2024/07/13 00:56:42 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	lexer_automaton(t_mini mini)
{
	lexer_automaton_init(mini);
	while (42)
	{
		lexer_automaton_next_state(mini);
		if (lexer_automaton_is_final_state(mini))
		{
			lexer_automaton_delimit(mini);
			if (lexer_automaton_is_end_of_statement(mini))
				break ;
		}
	else
		{
			mini->lexer->end++;
			if (lexer_automaton_is_whitespace(mini))
				mini->lexer->start++;
		}
	}
}
