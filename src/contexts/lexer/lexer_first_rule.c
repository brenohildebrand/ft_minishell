/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_first_rule.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 21:18:16 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/01 23:31:13 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

/**
 * 1st rule:
 * If the end of input is recognized, the current token (if any) shall be 
 * delimited.
*/
t_none	lexer_first_rule(t_mini mini)
{
	const t_lexer	lexer = mini->lexer;

	if (lexer->cursor[0] == '\0')
	{
		lexer->has_applied_rule = TRUE;
		lexer->has_finished = TRUE;
		lexer_delimit(mini);
		printf("1st rule applied.\n");
	}
}
