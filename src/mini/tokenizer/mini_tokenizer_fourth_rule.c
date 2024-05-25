/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_tokenizer_fourth_rule.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 20:10:41 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/25 20:11:37 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * 4th rule:
 * If the current character is <backslash>, single-quote, or double-quote and 
 * it is not quoted, it shall affect quoting for subsequent characters up to 
 * the end of the quoted text. The rules for quoting are as described in 
 * Quoting . During token recognition no substitutions shall be actually 
 * performed, and the result token shall contain exactly the characters that 
 * appear in the input (except for <newline> joining), unmodified, including 
 * any embedded or enclosing quotes or substitution operators, between the 
 * <quotation-mark> and the end of the quoted text. The token shall not be 
 * delimited by the end of the quoted field.
*/
t_none	mini_tokenizer_fourth_rule(t_mini mini, t_tokenizer_context context)
{
	(void)mini;
	(void)context;
}
