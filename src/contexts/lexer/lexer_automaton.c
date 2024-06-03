/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_automaton.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:11:11 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/03 17:47:08 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

t_none	lexer_automaton(t_mini mini)
{
	// para cada letrinha
	// ve se tah num estado final
	// se tiver fecha o token e avanca letrinha se tiver mais pra avancar
	// se nao pega o proximo estado e continua
	

	const t_lexer	lexer = mini->lexer;

	lexer->state = 0;
	lexer->index = 0;
	while (42)
	{
		if (lexer_is_final_state(mini))
		{
			lexer_delimit(mini);
			if (lexer->cursor[lexer->index] == '\0')
				break ;
		}
		else
		{
			lexer->state = lexer_next_state(mini);
		}
	}
}
