/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_seventh_rule.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 21:19:05 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/01 23:32:06 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

/**
 * 7th rule:
 * If the current character is an unquoted <blank>, any token containing the 
 * previous character is delimited and the current character shall be 
 * discarded.
*/
static t_bool	is_blank(t_mini mini)
{
	const t_lexer	lexer = mini->lexer;

	if (lexer->cursor[0] == ' ')
		return (TRUE);
	if (lexer->cursor[0] >= '\t' && lexer->cursor[0] <= '\r')
		return (TRUE);
	return (FALSE);
}

t_none	lexer_seventh_rule(t_mini mini)
{
	const t_lexer	lexer = mini->lexer;

	if (!lexer->is_quoted && is_blank(mini))
	{
		lexer_delimit(mini);
		lexer_discard_character(mini);
		lexer->has_applied_rule = TRUE;
		printf("7th rule applied.\n");
	}
}
