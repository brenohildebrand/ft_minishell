/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_lexer_third_rule.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 20:07:24 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/25 20:08:44 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * 3rd rule:
 * If the previous character was used as part of an operator and the current
 * character cannot be used with the previous characters to form an operator, 
 * the operator containing the previous character shall be delimited.
*/
t_none	mini_lexer_third_rule(t_mini mini)
{
	(void)mini;
}
