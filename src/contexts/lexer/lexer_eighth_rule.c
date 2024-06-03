/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_eighth_rule.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 21:19:17 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/01 23:32:14 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

/**
 * 8th rule:
 * If the previous character was part of a word, the current character shall 
 * be appended to that word.
*/
t_none	lexer_eighth_rule(t_mini mini)
{
	const t_lexer	lexer = mini->lexer;

	if (lexer->buffer_length > 0 && !lexer->is_operator)
	{
		lexer_add_character(mini);
		lexer->has_applied_rule = TRUE;
		printf("8th rule applied.\n");
	}
}
