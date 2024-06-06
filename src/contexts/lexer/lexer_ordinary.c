/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_lexer_ordinary.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 18:45:26 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/25 19:19:29 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	lexer_ordinary(t_mini mini)
{
	lexer_automaton(mini);
}

// /**
//  * This function simply applies the rules described in this document:
//  * https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html
//  * See '2.3 Token Recognition'
// */
// void	lexer_ordinary(t_mini mini)
// {
// 	const t_lexer	lexer = mini->lexer;
// 	t_none (* const rules[10])(t_mini) = {
// 		lexer_first_rule,
// 		lexer_second_rule,
// 		lexer_third_rule,
// 		lexer_fourth_rule,
// 		lexer_fifth_rule,
// 		lexer_sixth_rule,
// 		lexer_seventh_rule,
// 		lexer_eighth_rule,
// 		lexer_ninth_rule,
// 		lexer_tenth_rule
// 	};
// 	t_i32			index;

// 	lexer->has_applied_rule = FALSE;
// 	index = 0;
// 	while (index < 10 && !lexer->has_applied_rule)
// 	{
// 		rules[index](mini);
// 		index++;
// 	}
// }
