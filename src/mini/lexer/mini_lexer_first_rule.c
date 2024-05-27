/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_lexer_first_rule.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 19:14:30 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/25 20:07:04 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * 1st rule:
 * If the end of input is recognized, the current token (if any) shall be 
 * delimited.
*/
t_none	mini_lexer_first_rule(t_mini mini)
{
	// if (context->line[context->index] == '\0')
	// {
	// 	mini_lexer_cut(mini, context);
	// 	context->was_rule_applied = TRUE;
	// }
	(void)mini;
}
