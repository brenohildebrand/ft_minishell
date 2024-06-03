/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_third_rule.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 21:17:59 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/01 23:31:33 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

/**
 * 3rd rule:
 * If the previous character was used as part of an operator and the current
 * character cannot be used with the previous characters to form an operator, 
 * the operator containing the previous character shall be delimited.
*/
t_none	lexer_third_rule(t_mini mini)
{
	const t_lexer	lexer = mini->lexer;

	if (lexer->is_operator)
	{
		if (!lexer_try_operator(mini))
		{
			lexer_delimit(mini);
			lexer->has_applied_rule = TRUE;
			printf("3rd rule applied.\n");
		}
	}
}
