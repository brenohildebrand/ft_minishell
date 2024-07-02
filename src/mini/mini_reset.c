/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_reset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:42:20 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/30 20:55:12 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	mini_reset(t_mini mini)
{
	reader_reset(mini);
	lexer_reset(mini);
	expansion_reset(mini);
	parser_reset(mini);
	heredoc_reset(mini);
	eval_reset(mini);
	mini->shared->is_statement_complete = FALSE;
}
