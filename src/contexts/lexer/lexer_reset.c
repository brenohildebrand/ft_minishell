/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_reset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 10:25:26 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/01 18:47:22 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

t_none	lexer_reset(t_mini mini)
{
	const t_lexer	lexer = mini->lexer;

	if (lexer->tokens == NULL)
	{
		lexer->tokens = linked_list_new(mini);
	}
	else
	{
		linked_list_destroy(mini, lexer->tokens);
		lexer->tokens = linked_list_new(mini);
	}
	lexer->cursor = mini->input->line;
	lexer->mode = LEXER_MODE_ORDINARY;
	lexer->has_applied_rule = FALSE;
	lexer->has_finished = FALSE;
	lexer->is_operator = FALSE;
	lexer->is_quoted = FALSE;
}
