/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 21:58:21 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/30 22:11:40 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

t_none	lexer_create(t_mini mini)
{
	mini->lexer = mini_alloc(mini, sizeof(struct s_lexer_context));
	mini->lexer->buffer = NULL;
	mini->lexer->cursor = NULL;
	mini->lexer->flags = 0;
	mini->lexer->line = NULL;
	mini->lexer->tokens = NULL;
}
