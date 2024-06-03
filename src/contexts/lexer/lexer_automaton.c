/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_automaton.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:11:11 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/03 18:51:31 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

t_none	lexer_automaton(t_mini mini)
{
	const t_lexer	lexer = mini->lexer;

	lexer->state = 0;
	lexer->index = 0;
	linked_list_destroy(mini, lexer->tokens);
	lexer->tokens = linked_list_new(mini);
	while (42)
	{
		lexer_next_state(mini);
		if (lexer_is_final_state(mini))
		{
			lexer_delimit(mini);
			if (lexer->cursor[lexer->index] == '\0')
				break ;	
		}
		lexer->index++;
	}
}
