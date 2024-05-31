/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_lexer_second_rule.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 20:04:31 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/25 20:08:16 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

/**
 * 2nd rule:
 * If the previous character was used as part of an operator and the current 
 * character is not quoted and can be used with the previous characters to 
 * form an operator, it shall be used as part of that (operator) token.
*/
t_none	mini_lexer_second_rule(t_mini mini)
{
	const t_lexer_context	context = mini->lexer_context;

	if (context->has_applied_rule)
		return ;
	if (context->is_operator && context->is_quoted)
	{
		// compare to ">"
		// compare to ">>"
		// compare to "<<"
		// compare to ""
	}
}
