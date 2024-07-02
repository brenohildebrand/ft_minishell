/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_reset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 00:27:06 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/30 20:14:14 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	lexer_reset(t_mini mini)
{
	mini->lexer->cursor = NULL;
	mini->lexer->end = 0;
	mini->lexer->start = 0;
	mini->lexer->state = 0;
	if (mini->lexer->tokens)
		mini_list_clear(mini, &mini->lexer->tokens);
	mini->lexer->tokens = NULL;
}
