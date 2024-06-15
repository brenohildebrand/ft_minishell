/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_reset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:42:20 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/14 23:55:01 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	mini_reset(t_mini mini)
{
	mini_reader_reset(mini);
	mini_lexer_reset(mini);
	mini_expansion_reset(mini);
	mini_parser_reset(mini);
	mini_heredoc_reset(mini);
	mini_eval_reset(mini);
	mini->shared->is_statement_complete = FALSE;
}
