/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_lexer_sixth_rule.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 20:33:05 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/25 20:33:44 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * 6th rule:
 * If the current character is not quoted and can be used as the first 
 * character of a new operator, the current token (if any) shall be delimited.
 * The current character shall be used as the beginning of the next (operator)
 * token.
*/
t_none	mini_lexer_sixth_rule(t_mini mini)
{
	(void)mini;
}
