/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_automaton.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:11:11 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/06 13:08:01 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	lexer_automaton(t_mini mini)
{
	const t_lexer	lexer = mini->lexer;

	lexer->state = 0;
	lexer->start = 0;
	lexer->end = 0;
	lexer->cursor = mini->input->line;
	if (lexer->tokens)
		linked_list_destroy(mini, lexer->tokens);
	lexer->tokens = linked_list_new(mini);
	while (42)
	{
		lexer_next_state(mini);
		if (lexer_is_final_state(mini))
		{
			lexer_delimit(mini);
			if (lexer->cursor[lexer->start] == '\0')
				break ;
		}
		else
		{
			lexer->end++;
			if (lexer->state == 0)
				lexer->start++;
		}
	}
}
