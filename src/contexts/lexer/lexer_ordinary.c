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

#include "contexts/mini.h"

/**
 * This function simply applies the rules described in this document:
 * https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html
 * See '2.3 Token Recognition'
*/
void	mini_lexer_ordinary(t_mini mini)
{
	// const t_none	(*rules[10])(t_mini) = {
	// 	mini_lexer_first_rule,
	// 	mini_lexer_second_rule,
	// 	mini_lexer_third_rule,
	// 	mini_lexer_fourth_rule,
	// 	mini_lexer_fifth_rule,
	// 	mini_lexer_sixth_rule,
	// 	mini_lexer_seventh_rule,
	// 	mini_lexer_eighth_rule,
	// 	mini_lexer_ninth_rule,
	// 	mini_lexer_tenth_rule
	// };
	// t_i32					index;

	// index = 0;
	// while (index < 10)
	// {
	// 	if (lexer_check_flag(LEXER_CONTEXT_FLAG_HAS_APPLIED_RULE))
	// 		break;
	// 	rules[index](mini);
	// 	index++;
	// }
	(void)mini;
}
