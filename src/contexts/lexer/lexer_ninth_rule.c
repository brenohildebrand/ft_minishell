/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_ninth_rule.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 21:19:26 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/01 23:32:21 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

/**
 * 9th rule:
 * If the current character is a '#', it and all subsequent characters up to,
 * but excluding, the next <newline> shall be discarded as a comment. The
 * <newline> that ends the line is not considered part of the comment.
*/
t_none	lexer_ninth_rule(t_mini mini)
{
	const t_lexer	lexer = mini->lexer;

	if (lexer->cursor[0] == '#')
	{
		while (lexer->cursor[0] != '\n' && lexer->cursor[0] != '\0')
		{
			lexer_discard_character(mini);
			lexer->has_applied_rule = TRUE;
			printf("9th rule applied.\n");
		}
	}
}
