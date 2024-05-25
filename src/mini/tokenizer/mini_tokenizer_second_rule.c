/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_tokenizer_second_rule.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 20:04:31 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/25 20:08:16 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * 2nd rule:
 * If the previous character was used as part of an operator and the current 
 * character is not quoted and can be used with the previous characters to 
 * form an operator, it shall be used as part of that (operator) token.
*/
t_none	mini_tokenizer_second_rule(t_mini mini, t_tokenizer_context context)
{
	(void)mini;
	(void)context;
}
