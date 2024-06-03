/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_fourth_rule.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 21:18:35 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/03 10:55:55 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

/**
 * 4th rule:
 * If the current character is <backslash>, single-quote, or double-quote and 
 * it is not quoted, it shall affect quoting for subsequent characters up to 
 * the end of the quoted text. The rules for quoting are as described in 
 * Quoting . During token recognition no substitutions shall be actually 
 * performed, and the result token shall contain exactly the characters that 
 * appear in the input (except for <newline> joining), unmodified, including 
 * any embedded or enclosing quotes or substitution operators, between the 
 * <quotation-mark> and the end of the quoted text. The token shall not be 
 * delimited by the end of the quoted field.
*/
t_none	lexer_fourth_rule(t_mini mini)
{
	const t_lexer	lexer = mini->lexer;

	if ((lexer->cursor[0] == '\\' || lexer->cursor[0] == '\'' || lexer->cursor[0] == '"') && !lexer->is_quoted)
	{
		lexer->is_quoted = TRUE;	
		lexer->has_applied_rule = TRUE;
		printf("4h rule applied.\n");
	}
}
