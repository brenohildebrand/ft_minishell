/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_context_reset.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 10:25:26 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/27 11:35:05 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	lexer_context_reset(t_mini mini)
{
	const t_lexer_context	context = mini->lexer_context;

	context->tokens = linked_list_new(mini);
	context->delimiter_end = 0;
	context->delimiter_start = 0;
	context->mode = LEXER_MODE_ORDINARY;
	context->has_finished = TRUE;
}
