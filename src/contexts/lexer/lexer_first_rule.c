/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_lexer_first_rule.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 19:14:30 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/25 20:07:04 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

/**
 * 1st rule:
 * If the end of input is recognized, the current token (if any) shall be 
 * delimited.
*/
t_none	mini_lexer_first_rule(t_mini mini)
{
	const t_lexer_context	context = mini->lexer_context;

	if ((*context->cursor) == '\0')
	{
		context->delimiter_end = context->cursor - 1;
		mini_lexer_cut(mini);
		context->has_applied_rule = TRUE;
		context->has_finished = TRUE;
	}
}
