/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 21:58:21 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/01 18:47:40 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

t_none	lexer_create(t_mini mini)
{
	mini->lexer = mini_alloc(mini, sizeof(struct s_lexer_context));
	mini->lexer->mode = LEXER_MODE_ORDINARY;
	mini->lexer->buffer = NULL;
	mini->lexer->buffer_length = 0;
	mini->lexer->buffer_size = 0;
	mini->lexer->cursor = NULL;
	mini->lexer->tokens = NULL;
	mini->lexer->has_finished = FALSE;
}
