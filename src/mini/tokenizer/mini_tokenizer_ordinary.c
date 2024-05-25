/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_tokenizer_ordinary.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 18:45:26 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/25 19:19:29 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * This function simply applies the rules described in this document:
 * https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html
 * See '2.3 Token Recognition'
*/
void	mini_tokenizer_ordinary(t_mini mini, t_tokenizer_context context)
{
	mini_tokenizer_first_rule(mini, context);
	mini_tokenizer_second_rule(mini, context);
	mini_tokenizer_third_rule(mini, context);
	mini_tokenizer_fourth_rule(mini, context);
	mini_tokenizer_fifth_rule(mini, context);
	mini_tokenizer_sixth_rule(mini, context);
	mini_tokenizer_seventh_rule(mini, context);
	mini_tokenizer_eighth_rule(mini, context);
	mini_tokenizer_ninth_rule(mini, context);
	mini_tokenizer_tenth_rule(mini, context);
}
