/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_lexer_seventh_rule.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 20:33:55 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/25 20:34:28 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * 7th rule:
 * If the current character is an unquoted <blank>, any token containing the 
 * previous character is delimited and the current character shall be 
 * discarded.
*/
t_none	mini_lexer_seventh_rule(t_mini mini)
{
	(void)mini;
}
