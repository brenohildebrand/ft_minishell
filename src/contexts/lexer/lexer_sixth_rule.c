/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_sixth_rule.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 21:18:54 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/01 23:31:58 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

/**
 * 6th rule:
 * If the current character is not quoted and can be used as the first 
 * character of a new operator, the current token (if any) shall be delimited.
 * The current character shall be used as the beginning of the next (operator)
 * token.
*/
t_none	lexer_sixth_rule(t_mini mini)
{
	const t_lexer	lexer = mini->lexer;

	if (!lexer->is_quoted)
	{
		if (lexer_try_operator(mini))
		{
			lexer_delimit(mini);
			lexer->is_operator = TRUE;
			lexer->has_applied_rule = TRUE;
			lexer_add_character(mini);
			printf("6th rule applied.\n");
		}
	}
}
