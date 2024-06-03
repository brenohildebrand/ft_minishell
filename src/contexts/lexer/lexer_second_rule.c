/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_second_rule.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 21:18:10 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/01 23:31:24 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

/**
 * 2nd rule:
 * If the previous character was used as part of an operator and the current 
 * character is not quoted and can be used with the previous characters to 
 * form an operator, it shall be used as part of that (operator) token.
*/
t_none	lexer_second_rule(t_mini mini)
{
	const t_lexer	lexer = mini->lexer;

	if (lexer->is_operator && !lexer->is_quoted)
	{
		if (lexer_try_operator(mini))
		{
			lexer_add_character(mini);
			lexer->has_applied_rule = TRUE;
			printf("2nd rule applied.\n");
		}
	}
}
