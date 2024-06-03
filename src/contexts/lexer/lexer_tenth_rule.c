/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_tenth_rule.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 21:19:36 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/01 23:32:30 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

/**
 * 10th rule:
 * The current character is used as the start of a new word.
*/
t_none	lexer_tenth_rule(t_mini mini)
{
	const t_lexer	lexer = mini->lexer;

	lexer_add_character(mini);
	lexer->is_operator = FALSE;
	lexer->has_applied_rule = TRUE;
	printf("10th rule applied.\n");
}
