/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_lexer_update_mode.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:16:54 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/06 14:20:19 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	mini_lexer_update_mode(t_mini mini)
{
	if (mini->shared->is_statement_complete)
	{
		if (!mini->shared->is_heredoc_complete)
		{
			mini->lexer->mode = LEXER_MODE_HEREDOC;
		}
	}
}
