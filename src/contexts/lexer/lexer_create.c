/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 21:58:21 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/06 13:08:01 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	lexer_create(t_mini mini)
{
	mini->lexer = mini_alloc(mini, sizeof(struct s_lexer_context));
	mini->lexer->mode = LEXER_MODE_ORDINARY;
	mini->lexer->cursor = NULL;
	mini->lexer->start = 0;
	mini->lexer->end = 0;
	mini->lexer->state = 0;
	lexer_init_table(mini);
	mini->lexer->tokens = NULL;
}
