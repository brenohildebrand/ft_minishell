/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_lexer_automaton.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:30:27 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/06 22:17:04 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	mini_lexer_automaton(t_mini mini)
{
	mini_lexer_automaton_init(mini);
	while (42)
	{
		mini_lexer_automaton_next_state(mini);
		if (mini_lexer_automaton_is_final_state(mini))
		{
			mini_lexer_automaton_delimit(mini);
			if (mini_lexer_automaton_is_end_of_statement(mini))
				break ;
		}
		else
		{
			mini->lexer->end++;
			if (mini_lexer_automaton_is_whitespace(mini))
				mini->lexer->start++;
		}
	}
}
