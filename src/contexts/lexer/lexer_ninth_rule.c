/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_lexer_ninth_rule.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 20:35:42 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/25 20:36:36 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

/**
 * 9th rule:
 * If the current character is a '#', it and all subsequent characters up to,
 * but excluding, the next <newline> shall be discarded as a comment. The
 * <newline> that ends the line is not considered part of the comment.
*/
t_none	mini_lexer_ninth_rule(t_mini mini)
{
	const t_lexer_context	context = mini->lexer_context;

	if (*(context->cursor) == '#')
	{
		while (*(context->cursor) != '\n' && *(context->cursor) != '\0')
		{
			(context->cursor)++;
		}
	}
}
