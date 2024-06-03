/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 21:58:21 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/03 18:41:28 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

t_none	lexer_create(t_mini mini)
{
	mini->lexer = mini_alloc(mini, sizeof(struct s_lexer_context));
	mini->lexer->mode = LEXER_MODE_ORDINARY;
	mini->lexer->cursor = NULL;
	mini->lexer->index = 0;
	mini->lexer->state = 0;
	lexer_init_table(mini);
	mini->lexer->tokens = NULL;
}
