/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_lexer_automaton_init.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:41:01 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/06 15:42:46 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	mini_lexer_automaton_init(t_mini mini)
{
	mini->lexer->state = 0;
	mini->lexer->start = 0;
	mini->lexer->end = 0;
	mini->lexer->cursor = mini->reader->statement;
	if (mini->lexer->tokens)
	{
		mini_list_clear(mini, &mini->lexer->tokens);
	}
}
