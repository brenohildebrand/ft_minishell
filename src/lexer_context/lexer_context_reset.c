/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_context_reset.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 10:25:26 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/28 11:24:03 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	lexer_context_reset(t_mini mini)
{
	const t_lexer_context	context = mini->lexer_context;

	if (context->tokens == NULL)
	{
		context->tokens = llist_new(mini);
	}
	else
	{
		llist_destroy(mini, context->tokens);
		context->tokens = llist_new(mini);
	}
	context->cursor = mini->mini_context->line;
	context->delimiter_end = context->cursor;
	context->delimiter_start = context->cursor;
	context->mode = LEXER_MODE_ORDINARY;
	context->has_applied_rule = FALSE;
	context->has_finished = FALSE;
}
